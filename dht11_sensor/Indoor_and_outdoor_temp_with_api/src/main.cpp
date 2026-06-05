#include <Arduino.h>
#include <ArduinoJson.h>

const int dataPin = 21;
const int clockPin = 22;
const int latchPin = 19; 

// Need to first have latch to low, load then set latch to high for screenshot

// D1, D2, D3, D4 pins should be paired to the microcontroller directly.
const int dig4 = 4;
const int dig1 = 2;
const int dig2 = 15;
const int dig3 = 18;

// QA=bit7, QB=bit6, QC=bit5, QD=bit4, QE=bit3, QF=bit2, QG=bit1
byte segA = 0b10000000;
byte segB = 0b01000000;
byte segC = 0b00100000;
byte segD = 0b00010000;
byte segE = 0b00001000;
byte segF = 0b00000100;
byte segG = 0b00000001;  

byte all_On = 0b11111111;
byte all_Off = 0b00000000;

// Combining segments to make the numbers 0-9
byte num1 = segG | segD;
byte num2 = segB | segG | segC | segF | segE;
byte num3 = segB | segG | segC | segD | segE;
byte num4 = segA | segC | segG | segD;
byte num5 = segB | segA | segC | segD | segE;

byte num6 = segB | segA | segC | segF | segD | segE;
byte num7 = segB | segG | segD;
byte num8 = segB | segA | segG | segC | segF | segD | segE;
byte num9 = segB | segA | segG | segC | segD | segE;
byte num0 = segB | segA | segG |  segF | segD | segE | segF;
byte nums[] = {num0, num1, num2, num3, num4, num5, num6, num7, num8, num9};

void iterate_all_pins() {
  for (int i = 0; i < 256; i++) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, i);
    digitalWrite(latchPin,HIGH);
    delay(500);
  }
}

// Should prevent ghosting
void turn_off_all_digits() {
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);
}

void show_digit(int digitPin, byte segment) {
  turn_off_all_digits();
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, segment);
  digitalWrite(latchPin, HIGH);
  digitalWrite(digitPin, LOW);
  delay(1);
}

void show_celcius() {
  // Make the tiny * for the Celcius
  turn_off_all_digits();
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, segA | segB | segC | segG);
  digitalWrite(latchPin, HIGH);
  digitalWrite(dig3, LOW);
  delay(1);

  // Make digit 4 show the C for Celcius
  turn_off_all_digits();
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, segB | segA | segF | segE);
  digitalWrite(latchPin, HIGH);
  digitalWrite(dig4, LOW);
  delay(1);
}

void iterate_numbers() {
  for (int i = 0; i < 10; i++) {       
    unsigned long start = millis();
    while (millis() - start < 1000) {   
      show_digit(dig1, nums[i]);        
      show_celcius();                
    }
  }
}


void setup() {
  // Shift Register 
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);
  pinMode(dig3, OUTPUT);
  pinMode(dig4, OUTPUT);
  
  turn_off_all_digits();
}

void loop() {
  // show_celcius();
  iterate_numbers();

}
