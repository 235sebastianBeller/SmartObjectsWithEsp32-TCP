#include "ClientHandlerLcd.h"
ClientHandlerLcd::ClientHandlerLcd(String request) : ClientHandler(request)
{
}

ClientHandlerLcd::~ClientHandlerLcd()
{
}

void ClientHandlerLcd::getResponseFromServer(Esp32 esp)
{
    if (client.available() > 0)
    {
        String line = client.readStringUntil('\n');
        line = line.substring(0, line.length() - 1);
        Serial.println(line);
        esp.printMessageForLcd(line, 8, 0);
        esp.printCharForLcd(line, 7, 1, 0);
    }
    else
        Serial.println("Server timeout.");
}