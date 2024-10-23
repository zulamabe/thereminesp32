// UltrasonicSensor.h
#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>

class UltrasonicSensor {
  public:
    UltrasonicSensor(int trigPin, int echoPin);
    void init();
    float readDistance();

  private:
    int trigPin;
    int echoPin;
};

#endif
