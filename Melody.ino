/*******************************************
 Melody
 
This example shows how to make a short melody
with Sparki's buzzer.

This example is based on the Arduino example
by Tom Igoe.
********************************************/
#include <Sparki.h> // include the sparki library
#include "pitches.h" // include a list of pitches

// Melody notes and durations
struct {
  int note;
  int duration;
} melody[] = {
  { NOTE_C4, 4},
  { NOTE_G3, 8},
  { NOTE_G3, 8},
  { NOTE_A3, 4},
  { NOTE_G3, 4},
  { 0,       4},
  { NOTE_B3, 4},
  { NOTE_C4, 4},
};

void setup() {
  // play each note in the arrays
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {

    // calculate the note duration as 1 second divided by note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / melody[thisNote].duration;
    sparki.beep(melody[thisNote].note, noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    sparki.noBeep();
  }
}

void loop() {
  // no need to repeat the melody.
}
