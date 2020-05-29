#include "pitches.h"
#include "LiquidCrystal.h"
int buzzer = 19;
const int RS = 10;
const int EN = 9;
const int D4 = 8;
const int D5 = 7;
const int D6 = 6;
const int D7 = 5;
  LiquidCrystal lcd(RS,EN,D4,D5,D6,D7); // tells the microcontroller where the pins are connected to
// code needed to play happy birthday
const int numOfNotes = 28; // this is the total number of notes played in happy birthday
int   noteSequence[numOfNotes] = 
{NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_F5, NOTE_E5, PAUSE,
NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_F5, PAUSE,
NOTE_C5, NOTE_C5, NOTE_C6, NOTE_A5, NOTE_F5, NOTE_E5, NOTE_D5, PAUSE,
NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_F5 };
// the notes played in happy birthday in the correct order 

int   noteLength[numOfNotes]   = 
{4,2,8,8,8,16,   50,     //50  milliseconds for the first pause
 4,2,8,8,8,16,   100,    //100 milliseconds for the second pause
 4,2,8,8,8,8,16, 150,    //150 milliseconds for the third pause
 4,2,8,8,8,20 };
// length of the notes in the correct order with pauses as well
int tempo = 65; // how quickly you want the song to be played (make the number bigger if you want it longer and smaller for shorter)

/*function for making the buzzer play the notes*/
void playNote(int note, int duration) 
{
tone(buzzer,note); // makes the buzzer (buzzer) play the pitch put into the function
delay(duration); // delay is used to to make the note play for the duration wanted
noTone(buzzer); // makes the buzzer stop making noise
}
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16,2); // starts up the LCD
  lcd.setCursor(0,0); // sets where the typing will start (first number is for the collumn second number is the row)
  lcd.print("Happy Birthday"); // prints Happy Birthday on the LCD
  lcd.setCursor(0,1); // moves the cursor to the second row of the LCD
  lcd.print("(insert persons name)!"); // I put this line of code to add the person's name but can be taken out if not wanted
}
// loops playing happy birthday with a 2 second pause in between each repitition
void loop() { 
  for (int counter = 0; counter < numOfNotes; counter++) 
    {
        if ( noteSequence[counter] != PAUSE) 
          {
            playNote( noteSequence[counter], noteLength[counter] * tempo); // calls the playNote function to play the specified note with its corresponding length
            delay(tempo);// adds a delay with th duration of the tempo to make the song sound smoother
          } 
        else 
          {
            delay( noteLength[counter]);// delay if this is a pause. (it will be in millis, check noteLength)
          }
    }
  delay(2000); // 2 second delay in between each repitition of happy birthday
}
