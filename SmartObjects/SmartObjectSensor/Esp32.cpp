#include"Esp32.h"

Esp32::Esp32(){
}
void Esp32::connectToInternet(const char * wifiSsid,const char * wifiPass){
  Serial.println("WiFi disconnect ");
WiFi.disconnect(true);
  WiFi.begin(wifiSsid, wifiPass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print("*");
  }
}
IPAddress Esp32::getIpAdress(){
   return WiFi.localIP();
}
string Esp32::getStrForSet(int distance){
  stringstream ss;
  ss<<"SET id=0 distance="<<distance;
  return ss.str();
}
Esp32::~Esp32(){
}