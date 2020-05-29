#include "pitches.h"
#include "LiquidCrystal.h"
#include <stdio.h>
int SPEAKER = 19;
const int RS = 10;
const int EN = 9;
const int D4 = 8;
const int D5 = 7;
const int D6 = 6;
const int D7 = 5;
  LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
// code related to the melody itself
const int numOfNotes = 28;
int   NOTE_SEQ[numOfNotes] = {
      NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_F5, NOTE_E5, PAUSE,
      NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_F5, PAUSE,
      NOTE_C5, NOTE_C5, NOTE_C6, NOTE_A5, NOTE_F5, NOTE_E5, NOTE_D5, PAUSE,
      NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_F5 };
//reproduce pauses in milliseconds.

int   NOTE_LEN[numOfNotes]   = {
      4,2,8,8,8,16,   50,     //50  millis for the first pause
      4,2,8,8,8,16,   100,    //100 millis for the second pause
      4,2,8,8,8,8,16, 150,    //150 millis for the third pause
      4,2,8,8,8,20 };
int TEMPO = 65;

void playNote(int pitch, int duration) {
  tone(SPEAKER,pitch);
  delay(duration);
  noTone(SPEAKER);
}
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Happy Birthday");
  lcd.setCursor(0,1);
  lcd.print("     Nando!     ");
}

void loop() { 
  for (int i = 0; i < numOfNotes; i++) 
    {
        if ( NOTE_SEQ[i] != PAUSE) 
          {
            playNote( NOTE_SEQ[i], NOTE_LEN[i] * TEMPO);
            // delay after note reproduction following TEMPO variable's diktat
            delay( TEMPO);
          } 
        else 
          {
            // delay if this is a pause. (it will be in millis, check NOTE_LEN)
            delay( NOTE_LEN[i]);
          }
    }
  delay(2000);
}
