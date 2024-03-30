#include "Esp32.h"
#include <WiFi.h>
#include "ClientHandlerLeds.h"
#include "ClientHandlerLcd.h"
#include "constants.h"

Esp32 esp;
void setup() {
  Serial.begin(TRANSMISSION_SPEED);
  esp.initializeLeds();
  esp.intilizeLcd();
  esp.connectToInternet(WIFI_SSID, WIFI_PASS);
  Serial.print("\n My IP address: ");
  Serial.println(esp.getIpAdress());
}

void loop() {
  delay(1000);
  ClientHandler *clientList[CLIENTS_ACTUATORS_COUNT] = { new ClientHandlerLeds(REQUEST_CLIENT_HANDLER_LEDS), new ClientHandlerLcd(REQUEST_CLIENT_HANDLER_LCD) };
  for (byte i = 0; i < CLIENTS_ACTUATORS_COUNT; i++) {
    ClientHandler *clientHdl = clientList[i];
    clientHdl->connectoToTheServer(SERVER_ADDRESS, SERVER_PORT);
    clientHdl->sendRequestToTheServer();
    clientHdl->getResponseFromServer(esp);
    clientHdl->closeConnectionFromTheServer();
    delete clientList[i];
  }
}