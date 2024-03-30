#ifndef CLIENTHANDLERLEDS_H
#define CLIENTHANDLERLEDS_H
#include "ClientHandler.h"
using namespace std;
class ClientHandlerLeds : public ClientHandler
{
public:
  ClientHandlerLeds(String request);
  void getResponseFromServer(Esp32 esp);
  ~ClientHandlerLeds();
};
#endif