#ifndef ESP32_H
#define ESP32_H
#include <LCD-I2C.h>
#include <sstream>
#include <WiFi.h>
#include "constants.h"
#include "Led.h"
using namespace std;
class Esp32
{
private:
  Led leds[LEDS_COUNT];
  LCD_I2C lcd;

public:  Esp32();
  void initializeLeds();
  void intilizeLcd();
  void parseList(string message, uint8_t data[8]);
  void printStoredFigure(byte column, byte row);
  void printFigureForLcd(String message, byte column, byte row);
  void printMessageForLcd(String message, byte column, byte row);
  bool isTime(unsigned long actualMillis, unsigned long previousMillis, unsigned long limit);
  void controlTheLed(byte index, byte limit);
  void turnOnTheLeds(int limit);
  void connectToInternet(const char *wifiSsid, const char *wifiPass);
  IPAddress getIpAdress();
  ~Esp32();
};
#endif