#include "Led.h"
Led::Led(int ledPin)
{
  this->ledPin = ledPin;
  previousMillis = 0;
  pinMode(ledPin, OUTPUT);
}
Led::Led()
{
}
void Led::turnOff()
{
  digitalWrite(ledPin, LOW);
}
void Led::turnOn()
{
  digitalWrite(ledPin, HIGH);
}
int Led::getPreviousMillis()
{
  return previousMillis;
}
void Led::setPreviosMillis(int millis)
{
  previousMillis = millis;
}
Led::~Led()
{
}