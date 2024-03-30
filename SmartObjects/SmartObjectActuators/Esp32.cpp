#include "Esp32.h"
Esp32::Esp32() : lcd(0x27, 16, 2)
{
}
void Esp32::intilizeLcd()
{
  lcd.begin();
  lcd.display();
  lcd.backlight();
}
void Esp32::connectToInternet(const char *wifiSsid, const char *wifiPass)
{
  Serial.println("WiFi disconnect ");
  WiFi.disconnect(true);
  WiFi.hostname("Ultrasonico");
  WiFi.begin(wifiSsid, wifiPass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("*");
  }
}
IPAddress Esp32::getIpAdress()
{
  return WiFi.localIP();
}
void Esp32::parseList(string message, uint8_t data[8])
{
  istringstream ss(message);
  string token;
  int num;
  for (int i = 0; i < 8; i++)
  {
    getline(ss, token, ',');
    ss >> num;
    data[i] = num;
  }
}
void Esp32::printCharForLcd(String message, int column, int row, int id)
{
  uint8_t data[8];
  parseList(message.c_str(), data);
  lcd.createChar(id, data);
  lcd.setCursor(column, row);
  lcd.write(id);
}
void Esp32::printMessageForLcd(String message, int column, int row)
{
  lcd.clear();
  string firstPartOfMessage;
  stringstream ss(message.c_str());
  getline(ss, firstPartOfMessage, ',');
  lcd.setCursor(column - firstPartOfMessage.length() / 2, row);
  lcd.print(firstPartOfMessage.c_str());
}
void Esp32::initializeLeds()
{
  for (int i = 0; i < LEDS_COUNT; i++)
    leds[i] = Led(ledPins[i]);
}
bool Esp32::isTime(int actualMillis, int previousMillis, int limitMillis)
{
  return actualMillis - previousMillis >= limitMillis;
}
void Esp32::controlTheLed(int index, int limit)
{
  if (index < limit)
  {
    leds[index].turnOn();
  }
  else
  {
    leds[index].turnOff();
  }
}
void Esp32::turnOnTheLeds(int limit)
{
  for (int i = 0; i < LEDS_COUNT; i++)
  {
    int actualMillis = millis();
    if (isTime(actualMillis, leds[i].getPreviousMillis(), 700))
    {
      leds[i].setPreviosMillis(actualMillis);
      controlTheLed(i, limit);
    }
  }
}
Esp32::~Esp32()
{
}