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

void num0() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
}

void num1() {
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

void num2() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
}

void num3() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

void num4() {
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

void num5() {
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

void num6() {
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);

}

void num7() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

void num8() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void num9() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void clear() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(list_pins[i], LOW);
  }
}

void flash67() {
  num6();
  delay(1000);
  clear();
  delay(1000);
  num7();
  delay(1000);
  clear();
  delay(1000);

}

void setup() {
  // iterate through list_pins to set pinmode
  for (int i = 0; i < 7; i++) {
    pinMode(list_pins[i],OUTPUT);
  }
}

void loop() {
  flash67();
  
}

