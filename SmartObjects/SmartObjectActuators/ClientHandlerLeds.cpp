#include "ClientHandlerLeds.h"
ClientHandlerLeds::ClientHandlerLeds(String request) : ClientHandler(request)
{
}

ClientHandlerLeds::~ClientHandlerLeds()
{
}
void ClientHandlerLeds::getResponseFromServer(Esp32 esp)
{
  if (client.available() > 0)
  {
    String line = client.readStringUntil('\n');
    Serial.println(line);
    int countLedsOn = line.toInt();
    esp.turnOnTheLeds(countLedsOn);
  }
  else
    Serial.println("Server timeout.");
}