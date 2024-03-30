#ifndef CLIENTHANDLERLCD_H
#define CLIENTHANDLERLCD_H
#include "ClientHandler.h"
using namespace std;
class ClientHandlerLcd : public ClientHandler
{
public:
  ClientHandlerLcd(String request);
  void getResponseFromServer(Esp32 esp);
  ~ClientHandlerLcd();
};
#endif