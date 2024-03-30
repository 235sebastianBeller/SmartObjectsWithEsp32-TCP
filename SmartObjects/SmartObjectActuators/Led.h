#ifndef LED_H
#define LED_H
#include <Arduino.h>
class Led
{
private:
  byte ledPin;
  unsigned long previousMillis;

public:
  Led();
  Led(byte ledPin);
  void turnOff();
  void turnOn();
  void setPreviosMillis(unsigned long millis);
  unsigned long getPreviousMillis();
  ~Led();
};
#endif