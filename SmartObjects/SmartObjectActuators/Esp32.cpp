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
  Serial.println("WiFi disconnect ");\
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
  for (byte i = 1; i <=COUNT_FIGURES*COLUMNS_FIGURE; i++)
  {
    getline(ss, token, ',');
    ss >> num;
    data[(i-1)%COLUMNS_FIGURE] = num;
    if (i%COLUMNS_FIGURE==0)
      lcd.createChar(i/COLUMNS_FIGURE-1, data);
  }

}
void Esp32::printStoredFigure(byte column, byte row){
  for(byte i=0;i<3;i++){
    lcd.setCursor(column+i, row);
    lcd.write(i);
  }
}
void Esp32::printFigureForLcd(String message, byte column, byte row)
{
  uint8_t data[8];
  parseList(message.c_str(), data);
  printStoredFigure(column, row);
}
void Esp32::printMessageForLcd(String message, byte column, byte row)
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
  for (byte i = 0; i < LEDS_COUNT; i++)
    leds[i] = Led(ledPins[i]);
}
bool Esp32::isTime(unsigned long actualMillis, unsigned long previousMillis, unsigned long limitMillis)
{
  return actualMillis - previousMillis >= limitMillis;
}
void Esp32::controlTheLed(byte index, byte limit)
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
  for (byte i = 0; i < LEDS_COUNT; i++)
  {
    unsigned long actualMillis = millis();
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