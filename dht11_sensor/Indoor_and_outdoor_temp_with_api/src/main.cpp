#include <Arduino.h>

const int dataPin = 21;
const int clockPin = 22;
const int latchPin = 19; 

// D1, D2, D3, D4 pins should be paired to the microcontroller directly
const int dig4 = 4;

byte segment_dig4[] = {
  0b01000000,
  0b00100000,
  0b00010000,
  0b00001000,
  0b00000100,
};

byte combined_dig4 = segment_dig4[0] | segment_dig4[1] | segment_dig4[2] | segment_dig4[3] | segment_dig4[4];

// QA=bit7, QB=bit6, QC=bit5, QD=bit4, QE=bit3, QF=bit2, QG=bit1
// byte segA = 0b10000000;
// byte segB = 0b01000000;
// byte segC = 0b00100000;
// byte segD = 0b00010000;
// byte segE = 0b00001000;
// byte segF = 0b00000100;
// byte segG = 0b00000010;

byte all_On = 0b11111111;
byte all_Off = 0b00000000;


void iterate_all_pins() {
  for (int i = 0; i < 256; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, i);
    digitalWrite(latchPin,HIGH);
    delay(500);
  }
}


void setup() {
  // Shift Register 
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  pinMode(dig4, OUTPUT);
  digitalWrite(dig4, LOW);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin ,MSBFIRST, all_On);
  digitalWrite(latchPin, HIGH);
  delay(100);


  // iterate_all_pins();

}
