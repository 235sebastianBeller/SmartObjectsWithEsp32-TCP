#ifndef LED_H
#define LED_H
#include <Arduino.h>
class Led
{
private:
  int ledPin;
  int previousMillis;

public:
  Led();
  Led(int ledPin);
  void turnOff();
  void turnOn();
  void setPreviosMillis(int millis);
  int getPreviousMillis();
  ~Led();
};
#endif