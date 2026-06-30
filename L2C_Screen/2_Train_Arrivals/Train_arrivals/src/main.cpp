#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   

// Global Variables
const char* ssid = "Mango";
const char* password = "mangoloco";
const char* url = "https://api.open-meteo.com/v1/forecast?latitude=53.543&longitude=-2.6371&current=temperature_2m";

WiFiClientSecure wifi;
HTTPClient client;

void iniWIFI() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  Serial.print("Attempting to Connect");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("...");
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void connectHttpClient() {
  client.begin(wifi, url);
}

float getTemperature() {
    Serial.print("Attempting to GET");
    int httpCode = client.GET();
    float temperature = NAN;

    connectHttpClient();

    if (httpCode == 200) {               
    String payload = client.getString();

    JsonDocument doc;
    deserializeJson(doc, payload);

    temperature = doc["current"]["temperature_2m"];
    Serial.println(temperature);

  } else {
    Serial.print("Request failed, code: ");
    Serial.println(httpCode);
  }

  client.end();    
  return temperature;  
                  
}

void change_lcd_temp() {
  float temp = getTemperature();
  lcd.setCursor(0,1);
  lcd.print(temp, 1);
  lcd.print((char)223);   // degree symbol
  lcd.print("C     ");
  lcd.setCursor(0,0);
  lcd.print("Wigan");
}


void setup() {
  // Monitoring
  Serial.begin(115200);

  // LCD Screen start up
  lcd.init();
  lcd.backlight();

  // WIFI Start Up - Disconnect from any previous  networks 
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Setup done");
  WiFi.status();

  // Connect to the Wifi
  wifi.setInsecure();
  iniWIFI();

  // Connect to the http client
  connectHttpClient();

  getTemperature();
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    change_lcd_temp();
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Reconnecting... ");
  }
  delay(60000);  
}



