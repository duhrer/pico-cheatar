// Adapted from https://github.com/infovore/pico-example-midi

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hardware/clocks.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/bootrom.h"

// Set the "data plus" pin for PIO USB to 16, which is what the Adafruit feather rp2040 with USB Host uses.
#define PIO_USB_DP_PIN      16

#define PIO_USB_CONFIG { \
    PIO_USB_DP_PIN, \
    PIO_USB_TX_DEFAULT, \
    PIO_SM_USB_TX_DEFAULT, \
    PIO_USB_DMA_TX_DEFAULT, \
    PIO_USB_RX_DEFAULT, \
    PIO_SM_USB_RX_DEFAULT, \
    PIO_SM_USB_EOP_DEFAULT, \
    NULL, \
    PIO_USB_DEBUG_PIN_NONE, \
    PIO_USB_DEBUG_PIN_NONE, \
    false, \
    PIO_USB_PINOUT_DPDM \
}

#include "pio_usb.h"
#include "tusb.h"

int string_from_control_value (int value);

void stop_all_strings(void);
void stop_string(int string);
void start_string(int string);

#define FADE_MS 200
#define FADE_INC 4

// Guitar "state"
static int last_string = -1;
static int last_note = -1;
static bool use_7th_chords = false;

// TODO: Come up with a way to represent keys that covers major/minor/major7/7/minor7/etc.

// TODO: Come up with a lookup table for chords instead

// Open tuning, in offsets from C
//
// E: 4
// A: 9
// D: 14
// G: 19
// B: 23
// E: 28

// G major chord frets to add to the above
//
// E + 3
// A + 2
// D
// G
// B
// E + 3

// G major chord, expressed in offsets from C (36)
//
// 7
// 11
// 14
// 19
// 23
// 31

// TODO: Make a chord lookup system instead

// G major chord, as MIDI notes per string
// TODO: We used to do this like tablature, think about whether to do that again.
uint8_t chord[6] = {
  43,
  47,
  50,
  55,
  59,
  67
};

// We need this to fade out notes over time.
static int velocity_by_string[6] = { 0 };

// We also need to know which note is playing per string so we can manage that correctly on each strum.
static int note_by_string[6] = { -1 };

void midi_client_task(void);
void midi_host_task(void);

void core1_main() {
  sleep_ms(10);

  pio_usb_configuration_t pio_cfg = PIO_USB_CONFIG;
  tuh_configure(1, TUH_CFGID_RPI_PIO_USB_CONFIGURATION, &pio_cfg);

  tuh_init(1);

  while (true) {
    tuh_task();
  }
}

void fade_note_task(void);

int main() {
  // Enable USB power for client devices, nicked from OGX MINI:
  // https://github.com/wiredopposite/OGX-Mini/blob/ea14d683adeea579228109d2f92a4465fb76974d/Firmware/RP2040/src/Board/board_api_private/board_api_usbh.cpp#L35

  gpio_init(18);
  gpio_set_dir(18, GPIO_OUT);
  gpio_put(18, 1);

  // default 125MHz is not appropreate. Sysclock should be multiple of 12MHz.
  set_sys_clock_khz(120000, true);

  sleep_ms(10);

  multicore_reset_core1();
  multicore_launch_core1(core1_main);

  // device stack on native USB
  tud_init(0);

  while (true)
  {
    tud_task(); // tinyusb device task

    midi_client_task();

    // "Cleanup" cycle to fade notes a while after a strum, say seven seconds to silence
    fade_note_task();
  }
}


// Adapted from: https://github.com/lichen-community-systems/flocking-midi/blob/3fa553875b6b478fdb840da9ca006ae9beb04b10/src/core.js#L447
int generate_status_byte (int msNibble, int lsNibble) {
    return (msNibble << 4) + lsNibble;
};

// The packet consists of 4 bytes (8-bit integers):
//
// 0. contains the "cable" we're using
// 1. MIDI status byte (4 bits for the message type and 4 bits for the channel channel)
// 2. (optional) Data Byte, varies by message type.
// 3. (optional) Data Byte, varies by message type, or EOX in the case of System Exclusive messages.
//
// I still find the core of flocking-midi useful in reminding myself of the bit-packing schemes:
// https://github.com/lichen-community-systems/flocking-midi/blob/main/src/core.js

void process_incoming_packet (uint8_t *incoming_packet) {
  uint8_t midi_data[3];
  memcpy(midi_data, incoming_packet + 1, 3);
  
  // Start with the message type
  int type = midi_data[0] >> 4;

  // Force all messages to MIDI channel 0.
  midi_data[0] = generate_status_byte(type, 0);

  switch (type) {
    case MIDI_CIN_NOTE_ON:
      // Handle string muting
      stop_all_strings();

      int note_relative_to_c = midi_data[1] % 12;

      if (note_relative_to_c == last_note) {
        // TODO: handle key change
      }
      else {
        // TODO: Detect whether the current note corresponds to a chord in this key

        // If so, change the chord

        // If not, toggle 7th chords
      }
      last_note = note_relative_to_c;
      break;
    case MIDI_CIN_CONTROL_CHANGE:
      if (midi_data[1] == 1) {
        // Handle "string" detection
        int string = string_from_control_value(midi_data[2]);

        if (last_string != string) {
          if (string != -1) {
            stop_string(string);
            start_string(string);
          }

          last_string = string;
        }
      }
    // Strip all other message types such as sysex, clock, etc.
    default:
      break;
  }
}

//--------------------------------------------------------------------+
// Device callbacks
//--------------------------------------------------------------------+

// Client Callbacks

// Invoked when device is mounted
void tud_mount_cb(void) {}

// Invoked when device is unmounted
void tud_umount_cb(void) {}

// Invoked when usb bus is suspended
// remote_wakeup_en : if host allow us  to perform remote wakeup
// Within 7ms, device must draw an average of current less than 2.5 mA from bus
void tud_suspend_cb(bool remote_wakeup_en)
{
  (void) remote_wakeup_en;
}

// Invoked when usb bus is resumed
void tud_resume_cb(void) {}

// Host Callbacks

// The empty placeholder callbacks would ordinarily throw warnings about unused variables, so we use the strategy outlined here:
// https://stackoverflow.com/questions/3599160/how-can-i-suppress-unused-parameter-warnings-in-c

// Invoked when device with MIDI interface is mounted.
void tuh_midi_mount_cb(__attribute__((unused)) uint8_t idx, __attribute__((unused)) const tuh_midi_mount_cb_t* mount_cb_data) {}

// Invoked when device with hid interface is un-mounted
void tuh_midi_umount_cb(__attribute__((unused)) uint8_t idx) {}

void tuh_midi_rx_cb(uint8_t idx, uint32_t xferred_bytes) {
  if (xferred_bytes == 0) {
    return;
  }

  uint8_t incoming_packet[4];
  while (tuh_midi_packet_read(idx, incoming_packet)) {
    process_incoming_packet(incoming_packet);
  }
}

void tuh_midi_tx_cb(uint8_t idx, uint32_t xferred_bytes) {
  (void) idx;
  (void) xferred_bytes;
}

// End TinyUSB Callbacks

//--------------------------------------------------------------------+
// MIDI Tasks
//--------------------------------------------------------------------+
void midi_client_task(void)
{

  // Read any incoming messages from our primary USB port.
  while (tud_midi_available()) {
    uint8_t incoming_packet[4];
    tud_midi_packet_read(incoming_packet);
    process_incoming_packet(incoming_packet);
  }
}

void midi_host_task(void) {
  // TODO: Do something?
}


// Guitar functions

/**
 * A MIDI control returns values from 0-127.  This function dives that up into
 * eight zones.  The first and last zone are "dead" and return -1, indicating
 * that there is no string there. The middle zones from 0 to 5 correspond to a
 * guitar string, 0 for low E, et cetera.
 * 
 * @param value The current value of the MIDI control, from 0-127.
 */

int string_from_control_value (int value) {
  
  if (value < 24) return 0;
  else if (value < 44) return 1;
  else if (value < 64) return 2;
  else if (value < 84) return 3;
  else if (value < 104) return 4;

  return 5;
};

void stop_all_strings() {
  for (int a = 0; a < 6; a++) {
    stop_string(a);
  }
}

void stop_string(int string) {
  int note = note_by_string[string];
  velocity_by_string[string] = 0;

  if (note > 0) {
    uint8_t midi_data[3] = {
        MIDI_CIN_NOTE_OFF << 4,
        note,
        0
    };
    tud_midi_stream_write(0, midi_data, 3);

    note_by_string[string] = -1;
  }
};

void start_string(int string) {
  int note = chord[string];

  uint8_t midi_data[3] = {
      MIDI_CIN_NOTE_ON << 4,
      note,
      127
  };
  tud_midi_stream_write(0, midi_data, 3);

  note_by_string[string] = chord[string];
  velocity_by_string[string] = 127;
};

static absolute_time_t last_pass_time;


void fade_note_task(void) {
  if (is_nil_time(last_pass_time)) {
    last_pass_time = get_absolute_time();
    return;
  }

  absolute_time_t now = get_absolute_time();

  // Note the difference is in MICROseconds.  I still use millis because it seems saner.
  int64_t time_difference = absolute_time_diff_us(last_pass_time, now);
  if (time_difference < (FADE_MS * 1000)) return;

  last_pass_time = now;
  
  for (int string = 0; string < 6; string++) {
    int note = note_by_string[string];
    if (note != -1 && velocity_by_string[string] > 0) {
      if (velocity_by_string[string] > FADE_INC) {
        int new_velocity = velocity_by_string[string] - FADE_INC;
        velocity_by_string[string] = new_velocity;
        uint8_t midi_data[3] = {
            MIDI_CIN_POLY_KEYPRESS << 4,
            note,
            new_velocity
        };
        tud_midi_stream_write(0, midi_data, 3);
      }
      else {
        velocity_by_string[string] = 0;
        uint8_t midi_data[3] = {
          MIDI_CIN_NOTE_ON << 4,
          note,
          0
        };
        tud_midi_stream_write(0, midi_data, 3);
      }
    }
  }
};