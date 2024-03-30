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

public:
  Esp32();
  void initializeLeds();
  void intilizeLcd();
  void parseList(string message, uint8_t data[8]);
  void printCharForLcd(String message, int column, int row, int id);
  void printMessageForLcd(String message, int column, int row);
  bool isTime(int actualMillis, int previousMillis, int limit);
  void controlTheLed(int index, int limit);
  void turnOnTheLeds(int limit);
  void connectToInternet(const char *wifiSsid, const char *wifiPass);
  IPAddress getIpAdress();
  ~Esp32();
};
#endif