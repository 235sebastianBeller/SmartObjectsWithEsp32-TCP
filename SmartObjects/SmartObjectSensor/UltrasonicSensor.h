#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H
#include <Arduino.h>

class UltrasonicSensor
{
private:
    byte triggerPin;
    byte echoPin;

public:
    UltrasonicSensor(byte triggerPin, byte echoPin);
    long readDistance();
    int getTheShortestDistance(byte sampleSize);
    ~UltrasonicSensor();
};

#endif