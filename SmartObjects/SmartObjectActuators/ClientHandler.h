#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H
#include "Esp32.h"
using namespace std;
class ClientHandler
{
protected:
  String request;
  WiFiClient client;

public:
  ClientHandler(String request);
  void connectoToTheServer(string serverAdress, int serverPort);
  void sendRequestToTheServer();
  virtual void getResponseFromServer(Esp32 esp) = 0;
  ~ClientHandler();
  void closeConnectionFromTheServer();
};
#endif