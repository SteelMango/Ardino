

int pin;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(18, OUTPUT);
}

void blinking_led(int pin) {
  digitalWrite(pin, HIGH);  // on
  delay(500);
  digitalWrite(pin, LOW);   // off
  delay(500);

}


void loop() {
  blinking_led(15);
  blinking_led(2);
  blinking_led(18);
}