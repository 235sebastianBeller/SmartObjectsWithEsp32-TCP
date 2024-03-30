#include "ClientHandler.h"
ClientHandler::ClientHandler(String request)
{
    this->request = request;
}
void ClientHandler::connectoToTheServer(string serverAdress, int serverPort)
{
    Serial.print("Connecting to: ");
    Serial.println(serverAdress.c_str());

    if (!client.connect(serverAdress.c_str(), serverPort))
    {
        Serial.println("Connection failed");
        return;
    }
}
void ClientHandler::sendRequestToTheServer()
{
    client.print(request.c_str());
    unsigned long previousMillis = millis();
    while (!client.available() && millis() - previousMillis < 500)
        ;
}
void ClientHandler::closeConnectionFromTheServer()
{
    Serial.println("Closing connection.");
    client.stop();
}
ClientHandler::~ClientHandler()
{
}