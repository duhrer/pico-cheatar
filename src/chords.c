#include "chords.h"

const chord_family MAJOR_CHORDS = {
    C_MAJOR_CHORD,
    C_SHARP_MAJOR_CHORD,
    D_MAJOR_CHORD,
    D_SHARP_MAJOR_CHORD,
    E_MAJOR_CHORD,
    F_MAJOR_CHORD,
    F_SHARP_MAJOR_CHORD,
    G_MAJOR_CHORD,
    G_SHARP_MAJOR_CHORD,
    A_MAJOR_CHORD,
    A_SHARP_MAJOR_CHORD,
    B_MAJOR_CHORD
};

const chord_family DOMINANT_7_CHORDS = {
    C_DOMINANT_7_CHORD,
    C_SHARP_DOMINANT_7_CHORD,
    D_DOMINANT_7_CHORD,
    D_SHARP_DOMINANT_7_CHORD,
    E_DOMINANT_7_CHORD,
    F_DOMINANT_7_CHORD,
    F_SHARP_DOMINANT_7_CHORD,
    G_DOMINANT_7_CHORD,
    G_SHARP_DOMINANT_7_CHORD,
    A_DOMINANT_7_CHORD,
    A_SHARP_DOMINANT_7_CHORD,
    B_DOMINANT_7_CHORD
};

const chord_family MINOR_CHORDS = {
    C_MINOR_CHORD,
    C_SHARP_MINOR_CHORD,
    D_MINOR_CHORD,
    D_SHARP_MINOR_CHORD,
    E_MINOR_CHORD,
    F_MINOR_CHORD,
    F_SHARP_MINOR_CHORD,
    G_MINOR_CHORD,
    G_SHARP_MINOR_CHORD,
    A_MINOR_CHORD,
    A_SHARP_MINOR_CHORD,
    B_MINOR_CHORD
};

const chord_family DIMINISHED_CHORDS = {
    C_DIMINISHED_CHORD,
    C_SHARP_DIMINISHED_CHORD,
    D_DIMINISHED_CHORD,
    D_SHARP_DIMINISHED_CHORD,
    E_DIMINISHED_CHORD,
    F_DIMINISHED_CHORD,
    F_SHARP_DIMINISHED_CHORD,
    G_DIMINISHED_CHORD,
    G_SHARP_DIMINISHED_CHORD,
    A_DIMINISHED_CHORD,
    A_SHARP_DIMINISHED_CHORD,
    B_DIMINISHED_CHORD
};

// Key Definitions

// Major Keys
const key C_MAJOR_KEY = {
    C_MAJOR_CHORD,
    EMPTY_CHORD, // C#
    D_MINOR_CHORD,
    EMPTY_CHORD, // D#
    E_MINOR_CHORD,
    F_MAJOR_CHORD,
    EMPTY_CHORD, // F#
    G_MAJOR_CHORD,
    EMPTY_CHORD, // G#
    A_MINOR_CHORD,
    EMPTY_CHORD, // A#
    B_DIMINISHED_CHORD
};

const key C_SHARP_MAJOR_KEY = {
    C_DIMINISHED_CHORD,
    C_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // D
    D_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // E
    F_MINOR_CHORD,
    F_SHARP_MAJOR_CHORD,
    G_MAJOR_CHORD,
    G_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // A
    EMPTY_CHORD, // A#
    EMPTY_CHORD  // B
};

const key D_MAJOR_KEY = {
    EMPTY_CHORD, // C
    C_SHARP_DIMINISHED_CHORD,
    D_MAJOR_CHORD,
    EMPTY_CHORD, // D#
    E_MINOR_CHORD,
    EMPTY_CHORD, // F
    F_SHARP_MINOR_CHORD, 
    G_MAJOR_CHORD,
    EMPTY_CHORD, // G#
    A_MAJOR_CHORD,
    EMPTY_CHORD, // A#
    B_MINOR_CHORD
};

const key D_SHARP_MAJOR_KEY = {
    C_MINOR_CHORD,
    EMPTY_CHORD, // C#
    D_DIMINISHED_CHORD,
    D_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // E
    F_MINOR_CHORD,
    EMPTY_CHORD, // F#
    G_MINOR_CHORD,
    G_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // A
    A_SHARP_MAJOR_CHORD,
    EMPTY_CHORD // B
};

const key E_MAJOR_KEY = {
    EMPTY_CHORD, // C
    C_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // D
    D_SHARP_DIMINISHED_CHORD,
    E_MAJOR_CHORD,
    EMPTY_CHORD, // F
    F_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // G
    G_SHARP_MINOR_CHORD,
    A_MAJOR_CHORD,
    EMPTY_CHORD, // A#
    B_MAJOR_CHORD
};

const key F_MAJOR_KEY = {
    C_MAJOR_CHORD,
    EMPTY_CHORD, // C#
    D_MINOR_CHORD,
    EMPTY_CHORD, // D#
    E_DIMINISHED_CHORD,
    F_MAJOR_CHORD,
    EMPTY_CHORD, // F#
    G_MINOR_CHORD,
    EMPTY_CHORD, // G#
    A_MINOR_CHORD,
    A_SHARP_MAJOR_CHORD,
    EMPTY_CHORD // B
};

const key F_SHARP_MAJOR_KEY = {
    EMPTY_CHORD, // C
    C_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // D
    D_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // E
    F_DIMINISHED_CHORD,
    F_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // G
    G_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // A
    A_SHARP_MAJOR_CHORD,
    B_MAJOR_CHORD
};

const key G_MAJOR_KEY = {
    C_MAJOR_CHORD,
    EMPTY_CHORD, // C#
    D_MAJOR_CHORD,
    EMPTY_CHORD, // D#
    E_MINOR_CHORD,
    EMPTY_CHORD, // F
    F_SHARP_DIMINISHED_CHORD,
    G_MAJOR_CHORD,
    EMPTY_CHORD, // G#
    A_MINOR_CHORD,
    EMPTY_CHORD, // A#
    B_MINOR_CHORD
};

const key G_SHARP_MAJOR_KEY = {
    C_MINOR_CHORD,
    C_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // D
    D_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // E
    F_MINOR_CHORD,
    EMPTY_CHORD, // F#
    G_DIMINISHED_CHORD,
    G_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // A
    A_SHARP_MINOR_CHORD,
    EMPTY_CHORD // B
};

const key A_MAJOR_KEY = {
    EMPTY_CHORD, // C
    C_SHARP_MINOR_CHORD,
    D_MAJOR_CHORD,
    EMPTY_CHORD, // D#
    E_MAJOR_CHORD,
    EMPTY_CHORD, // F
    F_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // G
    G_SHARP_DIMINISHED_CHORD,
    A_MAJOR_CHORD,
    EMPTY_CHORD, // A#
    B_MINOR_CHORD
};

const key A_SHARP_MAJOR_KEY = {
    C_MINOR_CHORD,
    EMPTY_CHORD, // C#
    D_MINOR_CHORD,
    D_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // E
    F_MAJOR_CHORD,
    EMPTY_CHORD, // F#
    G_MINOR_CHORD,
    EMPTY_CHORD, // G#
    A_DIMINISHED_CHORD,
    A_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // B
};

const key B_MAJOR_KEY = {
    EMPTY_CHORD, // C
    C_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // D
    D_SHARP_MINOR_CHORD,
    E_MAJOR_CHORD,
    EMPTY_CHORD, // F
    F_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // G
    G_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // A
    A_SHARP_DIMINISHED_CHORD,
    B_MAJOR_CHORD
};

const key EMPTY_KEY = {
    EMPTY_CHORD
};

// MINOR_KEYS, adapted from: https://www.piano-keyboard-guide.com/key-of-a-sharp-minor.html

const key C_MINOR_KEY = {
    C_MINOR_CHORD,
    EMPTY_CHORD, // C#
    D_DIMINISHED_CHORD,
    D_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // E
    F_MINOR_CHORD,
    EMPTY_CHORD, // F#
    G_MINOR_CHORD,
    G_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // A
    A_SHARP_MAJOR_CHORD,
    EMPTY_CHORD // B    
};

const key C_SHARP_MINOR_KEY = {
    EMPTY_CHORD, // C
    C_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // D
    D_SHARP_DIMINISHED_CHORD,
    E_MAJOR_CHORD,
    EMPTY_CHORD, // F
    F_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // G
    G_SHARP_MINOR_CHORD,
    A_MAJOR_CHORD,
    EMPTY_CHORD, // A#
    B_MAJOR_CHORD
};

const key D_MINOR_KEY = {
    C_MAJOR_CHORD,
    EMPTY_CHORD, // C#
    D_MINOR_CHORD,
    EMPTY_CHORD, // D3
    E_DIMINISHED_CHORD,
    F_MAJOR_CHORD,
    EMPTY_CHORD, // F#
    G_MINOR_CHORD,
    EMPTY_CHORD, // G#
    A_MINOR_CHORD,
    A_SHARP_MAJOR_CHORD,
    EMPTY_CHORD // B    
};

const key D_SHARP_MINOR_KEY = {
    EMPTY_CHORD, // C
    C_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // D
    D_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // E
    F_DIMINISHED_CHORD,
    F_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // G
    G_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // A
    A_SHARP_MINOR_CHORD,
    B_MAJOR_CHORD    
};

const key E_MINOR_KEY = {
    C_MAJOR_CHORD,
    EMPTY_CHORD, // C#
    D_MAJOR_CHORD,
    EMPTY_CHORD, // D#
    E_MINOR_CHORD,
    EMPTY_CHORD, // F
    F_SHARP_DIMINISHED_CHORD,
    G_MAJOR_CHORD,
    EMPTY_CHORD, // G#,
    A_MINOR_CHORD,
    EMPTY_CHORD, // A#
    B_MINOR_CHORD    
};

const key F_MINOR_KEY = {
    C_MINOR_CHORD,
    C_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // D
    D_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // E
    F_MINOR_CHORD,
    EMPTY_CHORD, // F#
    G_DIMINISHED_CHORD,
    G_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // A
    A_SHARP_MINOR_CHORD,
    EMPTY_CHORD // B
};

const key F_SHARP_MINOR_KEY = {
    EMPTY_CHORD, // C
    C_SHARP_MINOR_CHORD,
    D_MAJOR_CHORD,
    EMPTY_CHORD, // D#
    E_MAJOR_CHORD,
    EMPTY_CHORD, // F
    F_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // G
    G_SHARP_DIMINISHED_CHORD,
    A_MAJOR_CHORD,
    EMPTY_CHORD, // A#
    B_MINOR_CHORD  
};

const key G_MINOR_KEY = {
    C_MINOR_CHORD,
    EMPTY_CHORD, // C#
    D_MINOR_CHORD,
    D_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // E
    F_MAJOR_CHORD,
    EMPTY_CHORD, // F#
    G_MINOR_CHORD,
    EMPTY_CHORD, // G#
    A_DIMINISHED_CHORD,
    A_SHARP_MAJOR_CHORD,
    EMPTY_CHORD // B   
};

const key G_SHARP_MINOR_KEY = {
    EMPTY_CHORD, // C
    C_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // D
    D_SHARP_MINOR_CHORD,
    E_MAJOR_CHORD,
    EMPTY_CHORD, // F
    F_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // G
    G_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // A
    A_SHARP_DIMINISHED_CHORD,
    B_MAJOR_CHORD
};

const key A_MINOR_KEY = {
    C_MAJOR_CHORD,
    EMPTY_CHORD, // C#
    D_MINOR_CHORD,
    EMPTY_CHORD, // D#
    E_MINOR_CHORD,
    F_MAJOR_CHORD,
    EMPTY_CHORD, // F#
    G_MAJOR_CHORD,
    EMPTY_CHORD, // G#
    A_MINOR_CHORD,
    EMPTY_CHORD, // A#
    B_DIMINISHED_CHORD
};

const key A_SHARP_MINOR_KEY = {
    C_DIMINISHED_CHORD,
    C_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // D
    D_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // E
    F_MINOR_CHORD,
    F_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // G
    G_SHARP_MAJOR_CHORD,
    EMPTY_CHORD, // A
    A_SHARP_MINOR_CHORD,
    EMPTY_CHORD, // B
};

const key B_MINOR_KEY = {
    EMPTY_CHORD, // C    
    C_SHARP_DIMINISHED_CHORD,
    D_MAJOR_CHORD,
    EMPTY_CHORD, // D#
    E_MINOR_CHORD,
    EMPTY_CHORD, // F
    F_SHARP_MINOR_CHORD,
    G_MAJOR_CHORD,
    EMPTY_CHORD, // G#
    A_MAJOR_CHORD,
    EMPTY_CHORD, // A#
    B_MINOR_CHORD
};

// TODO: Add definitions for key families with 7ths

// Functions

void set_major_key_by_note (int index, key dest) {
    if (index == 0) { memcpy(dest, C_MAJOR_KEY, sizeof(chord) * 12); }
    else if (index == 1)  { memcpy(dest, C_SHARP_MAJOR_KEY, sizeof(chord) * 12); }
    else if (index == 2)  { memcpy(dest,  D_MAJOR_KEY, sizeof(chord) * 12); }
    else if (index == 3)  { memcpy(dest,  D_SHARP_MAJOR_KEY, sizeof(chord) * 12); }
    else if (index == 4)  { memcpy(dest,  E_MAJOR_KEY, sizeof(chord) * 12); }
    else if (index == 5)  { memcpy(dest,  F_MAJOR_KEY, sizeof(chord) * 12); }
    else if (index == 6)  { memcpy(dest,  F_SHARP_MAJOR_KEY, sizeof(chord) * 12); }
    else if (index == 7)  { memcpy(dest,  G_MAJOR_KEY, sizeof(chord) * 12); }
    else if (index == 8)  { memcpy(dest,  G_SHARP_MAJOR_KEY, sizeof(chord) * 12); }
    else if (index == 9)  { memcpy(dest,  A_MAJOR_KEY, sizeof(chord) * 12); }
    else if (index == 10) { memcpy(dest,  A_SHARP_MAJOR_KEY, sizeof(chord) * 12); }
    else if (index == 11) { memcpy(dest,  B_MAJOR_KEY, sizeof(chord) * 12); }
}

void set_minor_key_by_note (int index, key dest) {
    if (index == 0) { memcpy(dest, C_MINOR_KEY, sizeof(chord) * 12); }
    else if (index == 1)  { memcpy(dest, C_SHARP_MINOR_KEY, sizeof(chord) * 12); }
    else if (index == 2)  { memcpy(dest,  D_MINOR_KEY, sizeof(chord) * 12); }
    else if (index == 3)  { memcpy(dest,  D_SHARP_MINOR_KEY, sizeof(chord) * 12); }
    else if (index == 4)  { memcpy(dest,  E_MINOR_KEY, sizeof(chord) * 12); }
    else if (index == 5)  { memcpy(dest,  F_MINOR_KEY, sizeof(chord) * 12); }
    else if (index == 6)  { memcpy(dest,  F_SHARP_MINOR_KEY, sizeof(chord) * 12); }
    else if (index == 7)  { memcpy(dest,  G_MINOR_KEY, sizeof(chord) * 12); }
    else if (index == 8)  { memcpy(dest,  G_SHARP_MINOR_KEY, sizeof(chord) * 12); }
    else if (index == 9)  { memcpy(dest,  A_MINOR_KEY, sizeof(chord) * 12); }
    else if (index == 10) { memcpy(dest,  A_SHARP_MINOR_KEY, sizeof(chord) * 12); }
    else if (index == 11) { memcpy(dest,  B_MINOR_KEY, sizeof(chord) * 12); }
}

bool is_empty_chord(chord to_check) {
    if (to_check[0] || to_check[1] || to_check[2] || to_check[3] || to_check[4] || to_check[5]) {
        return false;
    }

    return true;
}

void set_chord_by_key_and_note(chord dest, key key, int note) {
    set_chord(dest, key[note]);
}

void set_chord(chord dest, chord source) {
    memcpy(dest, source, sizeof(uint8_t) * 6);
}
