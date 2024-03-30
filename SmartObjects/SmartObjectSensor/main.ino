#include "Esp32.h"
#include "UltrasonicSensor.h"

#include "constants.h"

Esp32 esp;
UltrasonicSensor ultrasonicSensor(TRIGGER_PIN,ECHO_PIN);

void setup() {
  Serial.begin(TRANSMISSION_SPEED);
  esp.connectToInternet(WIFI_SSID, WIFI_PASS);
    Serial.print("\n My IP address: ");
  Serial.println(esp.getIpAdress());
}

int cm=0;
WiFiClient client;
void loop() {
  delay(800);

  Serial.print("Connecting to: ");
  Serial.println(SERVER_ADDRESS);

  if (!client.connect(SERVER_ADDRESS, SERVER_PORT)) {
    Serial.println("Connection failed"); 
    return;
  }
  cm=ultrasonicSensor.getTheShortestDistance(SAMPLE_SIZE);

  String set = esp.getStrForSet(cm).c_str();
  client.print(set);
  

  Serial.println("Closing connection.");
  client.stop();
}
