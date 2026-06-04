#include <Arduino.h>

#define dataPin 21
#define clockPin 22
#define latch 5

/* Makes it easier to visualise 
what pins = what binary */

byte pin1 = 0b00000010; // 2
byte pin2 = 0b00000100; // 4
byte pin3  = 0b00000100; // 4
byte pin4  = 0b00001000; // 8
byte pin5  = 0b00010000; // 16
byte pin6  = 0b00100000; // 32
byte pin7  = 0b01000000; // 64
byte pin8  = 0b10000000; // 128

byte all_On = 0b11111111;
byte all_Off = 0b00000000;


void setup() {
  // Shift Register 
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latch, OUTPUT);
 
}

void loop() {
  /* Each pin on the shift register
  corrisponds to a number in binary
  
  Lets say, we want to turn on a LED that
  is connected on the shift registers Q1

  We want the decimal 2, in binary that would be
  0b10

  Then put the decimal/binary in the (i)
  shiftOut(dataPin, clockPin, MSBFIRST, i);
  shiftOut(dataPin, clockPin, MSBFIRST, 2);
  
  */

  // Iterates through all the possible pins from 0-256
  digitalWrite(latch, LOW);
  shiftOut(dataPin, clockPin ,MSBFIRST, pin1 | pin2);
  digitalWrite(latch, HIGH);
  delay(100);

}

void iterate_all_pins() {
  for (int i = 0; i < 256; i++) {
    digitalWrite(latch, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, i);
    digitalWrite(latch,HIGH);
    delay(500);
  }
}
