#include <NewPing.h>

#define BUTTON_PIN 2
#define LED_PIN 13
#define TRIG_PIN 9
#define ECHO_PIN 10

NewPing sonar(TRIG_PIN, ECHO_PIN, 200);

enum State {
  IDLE,
  MEASURE
}

State state = IDLE;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    state = (state == IDLE) ? MEASURE : IDLE;
  }

  switch (state) {
    case IDLE:
      digitalWrite(LED_PIN, LOW);
      break;

    case MEASURE:
      digitalWrite(LED_PIN, HIGH);
      unsigned int distance = sonar.ping_cm();
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      delay(100);
      break;
  }
}
