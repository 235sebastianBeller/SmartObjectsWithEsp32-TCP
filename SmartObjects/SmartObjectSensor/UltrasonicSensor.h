#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H
#include <Arduino.h>

class UltrasonicSensor
{
private:
    int triggerPin;
    int echoPin;

public:
    UltrasonicSensor(int triggerPin, int echoPin);
    long readDistance();
    int getTheShortestDistance(int sampleSize);
    ~UltrasonicSensor();
};

#endif