// UltrasonicSensor.cpp
#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
}

void UltrasonicSensor::init() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float UltrasonicSensor::readDistance() {
  // Limpia el pin TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Envia un pulso de 10µs por el pin TRIG
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee el tiempo que tarda el pulso en regresar
  long duration = pulseIn(echoPin, HIGH);

  // Calcula la distancia en centímetros
  float distance = (duration * 0.034) / 2;

  return distance;
}
