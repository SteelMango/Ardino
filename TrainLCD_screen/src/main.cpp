#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   

void setup() {
  // Uncomment these to show on the monitor 
  // Serial.begin(115200);
  // Serial.println("Booting...");

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Hello World!");
  lcd.setCursor(0, 1);
  lcd.print("Steel Mango");

  // Serial.println("LCD initialized");
}

void loop() {
}