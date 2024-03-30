#include "Led.h"
Led::Led(byte ledPin)
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
unsigned long Led::getPreviousMillis()
{
  return previousMillis;
}
void Led::setPreviosMillis(unsigned long millis)
{
  previousMillis = millis;
}
Led::~Led()
{
}