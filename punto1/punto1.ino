
#include <Arduino.h>
#define LED 0 
const int LED1_PIN = 2;
const int LED2_PIN = 4;
const int LED3_PIN = 5;

void setup() {
  
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
}

void loop() {
  
  digitalWrite(LED1_PIN, HIGH);                         
  delay(200);
  digitalWrite(LED1_PIN, LOW);
 
  delay(200);

  digitalWrite(LED2_PIN, HIGH);
  delay(200);
  digitalWrite(LED2_PIN, LOW);

  delay(200);

  digitalWrite(LED3_PIN, HIGH);
  delay(200);
  digitalWrite(LED3_PIN, LOW);

  delay(200);
}

