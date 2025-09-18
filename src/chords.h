#ifndef CHORDS_H_INCLUDED
#define CHORDS_H_INCLUDED

#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

// NOTE: The structures defined here are meant to make it easier to represent a
// constant set of chords and keys.  You should mostly likely not be
// instantiating them yourself.

// Note that not all possible types of chords are supported, but only a subset
// useful for the types of songs I play.
enum chord_type {
    MAJOR_CHORD,
    MINOR_CHORD,
    DIMINISHED_CHORD,
    DOMINANT_7TH_CHORD
};

// Each chord is an array of six integers, one for each string of a guitar. Any
// non-zero value is a MIDI note. Although there is a MIDI note associated with
// zero, we treat it as "do not play".

typedef uint8_t chord[6];

// Chords are grouped into "families", such as major, minor, diminished.  Each
// family is an array of 12 elements, indexed by the offset from C.

// typedef chord chord_family[12];
typedef uint8_t chord_family[12][6];

enum key_type {
    MAJOR_KEY,
    MAJOR_KEY_WITH_SEVENTHS,
    MINOR_KEY,
    MINOR_KEY_WITH_SEVENTHS
};

// A key is an array of chords indexed by the notes in an octave, where 0 is C.
// Any chords that are not used in a given key will be set to EMPTY_CHORD.
// typedef chord key[12];
typedef uint8_t key[12][6];

// Utility functions
void set_major_key_by_note (int index, key dest);
void set_minor_key_by_note (int index, key dest);

void set_chord(chord dest, chord source);

void set_chord_by_key_and_note(chord dest, key key, int note);

bool is_empty_chord(chord to_check);

// Placeholder definitions for variables defined in chords.c

// Chord Definitions

// There is a comment above each chord expressing the chord in terms of frets
// held.  To avoid constantly adding offsets, the chords themselves are
// expressed as MIDI notes, and the starting notes for each string are:
//
// 40, 45, 50, 55, 59, 64
//
// Thanks to: https://www.fachords.com/note-frequencies/

// Placeholder for "dead" notes in keys, so that the lookup table is always complete
#define EMPTY_CHORD { 0, 0, 0, 0, 0, 0 }

// Minor Chords

//                     40, 45, 50, 55, 59, 64
//            Cmaj":  [ X,  3,  2,  0,  1,  0],
#define C_MAJOR_CHORD { 0, 48, 52, 55, 60, 64 }

//                           40, 45, 50, 55, 59, 64
//                 "C#maj": [ X,  4,  3,  1,  1,  1],
#define C_SHARP_MAJOR_CHORD { 0, 49, 53, 56, 60, 65 }

//                     40, 45, 50, 55, 59, 64
//           "Dmaj":  [ X,  X,  0,  2,  3,  2],
#define D_MAJOR_CHORD { 0,  0, 50, 57, 62, 66 }

//                           40, 45, 50, 55, 59, 64
//                 "D#maj": [ X,  X,  3,  1,  2,  1],
#define D_SHARP_MAJOR_CHORD { 0,  0, 53, 56, 60, 65 }

//                      40, 45, 50, 55, 59, 64
//           "Emaj":  [ 0,  2,  2,  1,  0,  0],
#define E_MAJOR_CHORD { 40, 47, 52, 56, 59, 64 }

//           40, 45, 50, 55, 59, 64
// "Fmaj":  [ 1,  3,  3,  2,  1,  1],
#define F_MAJOR_CHORD { 41, 48, 53, 57, 60, 65 }

//           40, 45, 50, 55, 59, 64
// "F#maj": [ 2,  4,  4,  3,  2,  2],
#define F_SHARP_MAJOR_CHORD { 42, 49, 54, 58, 61, 66 }

//                      40, 45, 50, 55, 59, 64
//           "Gmaj":  [  3,  2,  0,  0,  0,  3],
#define G_MAJOR_CHORD { 43, 47, 50, 55, 59, 67 }

//                            40, 45, 50, 55, 59, 64
//                 "G#maj": [  4,  6,  6,  5,  4,  4],
#define G_SHARP_MAJOR_CHORD { 44, 51, 56, 60, 63, 68 }

//                     40, 45, 50, 55, 59, 64
//           "Amaj":  [ X,  0,  2,  2,  2,  0],
#define A_MAJOR_CHORD { 0, 45, 52, 57, 61, 64 }

//                           40, 45, 50, 55, 59, 64
//                 "A#maj": [ 0,  1,  3,  3,  3,  1],
#define A_SHARP_MAJOR_CHORD { 0, 46, 53, 58, 62, 65 }

//                     40, 45, 50, 55, 59, 64
//           "Bmaj":  [ 0,  2,  4,  4,  4,  2],
#define B_MAJOR_CHORD { 0, 47, 54, 59, 63, 66 }

extern const chord_family DOMINANT_7_CHORDS;

// Adapted from: https://www.guitar-chord.org/7.html

// Dominant 7th Chords
//                          40, 45, 50, 55, 59, 64
//                  "C7":  [ X,  3,  2,  3,  1,  0]
#define C_DOMINANT_7_CHORD { 0, 48, 52, 58, 60, 64 }

//                                40, 45, 50, 55, 59, 64
//                        "C#7": [ X,  4,  3,  4,  2, X]
#define C_SHARP_DOMINANT_7_CHORD { 0, 49, 53, 59, 61, 0 }

//                          40, 45, 50, 55, 59, 64
//                  "D7":  [ X, X,  0,  2,  1,  2]
#define D_DOMINANT_7_CHORD { 0, 0, 50, 57, 61, 66 }

//                                40, 45, 50, 55, 59, 64
//                        "D#7": [ X,  6,  5,  6,  4, X]
#define D_SHARP_DOMINANT_7_CHORD { 0, 51, 55, 61, 63, 0 }

//                           40, 45, 50, 55, 59, 64
//                  "E7":  [  0,  2,  0,  1,  0, 0]
#define E_DOMINANT_7_CHORD { 40, 47, 50, 57, 59, 64 }

//                    40, 45, 50, 55, 59, 64
//                  "F7":  [  1,  3,  1,  2,  1,  1]
#define F_DOMINANT_7_CHORD { 41, 48, 51, 57, 60, 65 }

//                                40, 45, 50, 55, 59, 64
//                        "F#7": [ X, X,  4,  3,  2, 0 ]
#define F_SHARP_DOMINANT_7_CHORD { 0,  0, 54, 58, 61, 64 }

//                           40, 45, 50, 55, 59, 64
//                  "G7":  [  3,  2,  0,  0,  0,  1]
#define G_DOMINANT_7_CHORD { 43, 47, 50, 55, 59, 65 }

//                                40, 45, 50, 55, 59, 64
//                        "G#7": [ X,  X,  6,  8,  7,  8]
#define G_SHARP_DOMINANT_7_CHORD { 0, 0, 56, 63, 66, 72 }

//                          40, 45, 50, 55, 59, 64
//                  "A7":  [ X,  0,  2,  0,  2,  0]
#define A_DOMINANT_7_CHORD { 0, 45, 52, 55, 61, 64 }

//                                40, 45, 50, 55, 59, 64
//                        "A#7": [ X,  X,  8, 10,  9, 10]
#define A_SHARP_DOMINANT_7_CHORD { 0,  0, 58, 65, 68, 74 }

//                          40, 45, 50, 55, 59, 64
//                  "B7":  [ X,  2,  1,  2,  0,  2 ]
#define B_DOMINANT_7_CHORD { 0, 47, 51, 57, 59, 66 }

extern const chord_family MINOR_CHORDS;

// Minor Chords

//                     40, 45, 50, 55, 59, 64
//           "Cmin":  [ X,  3,  5,  5,  4,  3],
#define C_MINOR_CHORD { 0, 48, 55, 60, 63, 67 }

//                           40, 45, 50, 55, 59, 64
//                 "C#min": [ X,  X,  2,  1,  2,  0],
#define C_SHARP_MINOR_CHORD { 0,  0, 52, 57, 61, 64 }

//                     40, 45, 50, 55, 59, 64
//            Dmin":  [ X,  X,  0,  2,  3,  1],
#define D_MINOR_CHORD { 0,  0, 50, 57, 62, 65 }

//                           40, 45, 50, 55, 59, 64
//                 "D#min": [ X,  X,  4,  3,  4,  2],
#define D_SHARP_MINOR_CHORD { 0,  0, 54, 58, 63, 66 }

//                      40, 45, 50, 55, 59, 64
//           "Emin":  [  0,  2,  2,  0,  0,  0],
#define E_MINOR_CHORD { 40, 47, 52, 55, 59, 64 }

//                      40, 45, 50, 55, 59, 64
//           "Fmin":  [  1,  3,  3,  1,  1,  1],
#define F_MINOR_CHORD { 41, 48, 53, 56, 60, 65 }

//                            40, 45, 50, 55, 59, 64
//                 "F#min": [  2,  4,  4,  2,  2,  2],
#define F_SHARP_MINOR_CHORD { 42, 49, 54, 57, 61, 66 }

//                      40, 45, 50, 55, 59, 64
//           "Gmin":  [  3,  5,  5,  3,  3,  3],
#define G_MINOR_CHORD { 43, 50, 55, 58, 62, 67 }

//                            40, 45, 50, 55, 59, 64
//                 "G#min": [  1,  3,  3,  1,  1,  1],
#define G_SHARP_MINOR_CHORD { 41, 48, 53, 56, 60, 65 }

//                     40, 45, 50, 55, 59, 64
//           "Amin":  [ X,  0,  2,  2,  1,  0],
#define A_MINOR_CHORD { 0, 45, 52, 57, 60, 64 }

//                           40, 45, 50, 55, 59, 64
//                 "A#min": [ X,  1,  3,  3,  1,  1],
#define A_SHARP_MINOR_CHORD { 0, 46, 53, 58, 60, 65 }

//                     40, 45, 50, 55, 59, 64
//           "Bmin":  [ X,  2,  4,  4,  3,  2],
#define B_MINOR_CHORD { 0, 47, 54, 59, 62, 66 }

extern const chord_family DIMINISHED_CHORDS;

// Diminished chords

//                          40, 45, 50, 55, 59, 64
//                "Cdim":  [ X,  3,  4,  5,  4, X],
#define C_DIMINISHED_CHORD { 0, 48, 54, 60, 63, 0 }

//                                40, 45, 50, 55, 59, 64
//                      "C#dim": [ X,  4,  5,  6,  5, X],
#define C_SHARP_DIMINISHED_CHORD { 0, 49, 55, 61, 64, 0 }

//                          40, 45, 50, 55, 59, 64
//                "Ddim":  [ X,  5,  6,  7,  6, X],
#define D_DIMINISHED_CHORD { 0, 50, 57, 62, 65, 0 }

//                                40, 45, 50, 55, 59, 64
//                      "D#dim": [ X,  X,  1,  2,  4,  2],
#define D_SHARP_DIMINISHED_CHORD { 0,  0, 51, 57, 63, 66 }

//                          40, 45, 50, 55, 59, 64
//                "Edim":  [ X,  X,  2,  3,  5,  3],
#define E_DIMINISHED_CHORD { 0,  0, 52, 58, 64, 67 }

//                           40, 45, 50, 55, 59, 64
//                "Fdim":  [  1,  2,  3,  1,  0, X],
#define F_DIMINISHED_CHORD { 41, 47, 53, 56, 59, 0 }

//                                40, 45, 50, 55, 59, 64
//                      "F#dim": [ X,  X,  4,  2,  1,  2],
#define F_SHARP_DIMINISHED_CHORD { 0,  0, 54, 57, 60, 66 }

//                          40, 45, 50, 55, 59, 64
//                "Gdim":  [ X,  X,  5,  3,  2,  3],
#define G_DIMINISHED_CHORD { 0,  0, 55, 58, 61, 67 }

//                                 40, 45, 50, 55, 59, 64
//                      "G#dim": [  4,  5,  6,  4,  X,  X]
#define G_SHARP_DIMINISHED_CHORD { 44, 50, 56, 59,  0,  0 }

//                          40, 45, 50, 55, 59, 64
//                "Adim":  [ X,  X,  1,  2,  1,  2],
#define A_DIMINISHED_CHORD { 0,  0, 51, 57, 60, 66 }

//                                 40, 45, 50, 55, 59, 64
//                      "A#dim": [  X,  X,  2,  3,  2,  3],
#define A_SHARP_DIMINISHED_CHORD {  0,  0, 52, 58, 61, 67}

//                          40, 45, 50, 55, 59, 64
//                "Bdim":  [ X,  2,  3,  4,  3, X],
#define B_DIMINISHED_CHORD { 0, 47, 53, 59, 62, 0 }

// Key Definitions

// Major Keys
extern const key C_MAJOR_KEY;
extern const key C_SHARP_MAJOR_KEY;
extern const key D_MAJOR_KEY;
extern const key D_SHARP_MAJOR_KEY;
extern const key E_MAJOR_KEY;
extern const key F_MAJOR_KEY;
extern const key F_SHARP_MAJOR_KEY;
extern const key G_MAJOR_KEY;
extern const key G_SHARP_MAJOR_KEY;
extern const key A_MAJOR_KEY;
extern const key A_SHARP_MAJOR_KEY;
extern const key B_MAJOR_KEY;

extern const key EMPTY_KEY;

// MINOR_KEYS, adapted from: https://www.piano-keyboard-guide.com/key-of-a-sharp-minor.html

extern const key C_MINOR_KEY;
extern const key C_SHARP_MINOR_KEY;
extern const key D_MINOR_KEY;
extern const key D_SHARP_MINOR_KEY;
extern const key E_MINOR_KEY;
extern const key F_MINOR_KEY;
extern const key F_SHARP_MINOR_KEY;
extern const key G_MINOR_KEY;
extern const key G_SHARP_MINOR_KEY;
extern const key A_MINOR_KEY;
extern const key A_SHARP_MINOR_KEY;
extern const key B_MINOR_KEY;


#endif // ifndef CHORDS_H_INCLUDED