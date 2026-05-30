#include <Arduino.h>
#include <DHT.h>



// Global Variables
int  error_ledPin = 2;
int on_ledPin = 12;
#define DHTPIN 21
#define DHTTYPE DHT11

// Temperature based Variables
int hot_led_pin = 4;
int cold_led_pin = 5;
int tepid_led_pin = 19;

int temp_results;
DHT dht(DHTPIN, DHTTYPE);
float temp = dht.readTemperature();



void error_led(){   // So far the led is always on, add future code to change if nan
  digitalWrite(error_ledPin, HIGH);
  delay(250);
  digitalWrite(error_ledPin, LOW);
  delay(250);

}

int create_temp_result(int temp){
  if (temp >= 11 && temp <= 21) {   // Tepid
    return temp_results = 1; 
  } else if ( temp > 21) {    // hot
    return temp_results = 2;
  } else {
    return temp_results = 3;
  }
}

void check_temp_leds(){
  digitalWrite(hot_led_pin, HIGH);
  digitalWrite(tepid_led_pin, HIGH);
  digitalWrite(cold_led_pin, HIGH);
}




void setup() {
  pinMode(error_ledPin, OUTPUT);

  // Temurature Leds
  pinMode(hot_led_pin, OUTPUT);
  pinMode(cold_led_pin, OUTPUT);
  pinMode(tepid_led_pin, OUTPUT);

  // Other Communication Leds (On_led and Error_Led)
  pinMode(on_ledPin, OUTPUT);

 



  Serial.begin(115200);     
  dht.begin();
  delay(2000);
 
}

void loop() {
  // LEDs
  error_led();
  check_temp_leds();

  // Dimming the LEDS
  analogWrite(on_ledPin, 5);
  analogWrite(hot_led_pin, 5);
  analogWrite(tepid_led_pin, 5);
  analogWrite(cold_led_pin, 5);




  float temp = dht.readTemperature();      
  float humidity = dht.readHumidity();     

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);
}

