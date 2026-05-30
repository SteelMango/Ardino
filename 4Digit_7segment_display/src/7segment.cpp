#include <Arduino.h>

// Setting up the 1 digit 7 segment display pinout
// Each variables name will relate to the mage in the link bellows.
// https://www.oceanlabz.in/esp32-s3-7-segment-display-1-digit-with-arduino-ide-2/
// Reference for numbers https://www.dreamstime.com/royalty-free-stock-photo-digital-numbers-image1509975

int a = 13;
int b = 14;
int c = 27;
int d = 12;
int e = 18;
int f = 19;
int g = 23;

const int list_pins[7] = {a, b, c, d, e, f, g};

void setup() {
  // iterate through list_pins to set pinmode
  for (int i = 0; i < 7; i++) {
    pinMode(list_pins[i],OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(list_pins[i], HIGH);
  }
}

