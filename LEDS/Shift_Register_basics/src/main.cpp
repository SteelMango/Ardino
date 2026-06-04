#include <Arduino.h>

#define dataPin 21
#define clockPin 22
#define latch 5



void setup() {
  // Shift Register 
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latch, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 256; i++) {
    digitalWrite(latch, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, i);
    digitalWrite(latch,HIGH);
    delay(500);
  }
}

