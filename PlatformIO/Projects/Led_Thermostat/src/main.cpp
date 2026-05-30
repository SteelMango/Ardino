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
int tepid_led_pin = 22;


DHT dht(DHTPIN, DHTTYPE);
int temp_results;


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

void turn_temp_led_on(int temp_results){
  digitalWrite(hot_led_pin, LOW);
  digitalWrite(tepid_led_pin, LOW);
  digitalWrite(cold_led_pin, LOW);

  if (temp_results == 1){
    analogWrite(tepid_led_pin, 5);
  } else if (temp_results  == 2){
    analogWrite(hot_led_pin, 5);
  } else if (temp_results == 3){
    analogWrite(cold_led_pin, 5);
  }

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

  // Dimming the LEDS
  analogWrite(on_ledPin, 5);
  float temp = dht.readTemperature();      
  float humidity = dht.readHumidity();   

  int result = create_temp_result((int)temp);
  turn_temp_led_on(result);




    

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000);
}

