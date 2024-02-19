#pragma once
#include <SPI.h>

class SerialCommunication
{
  public:
    void init();
    void SetupCommunication();
    void SendData(byte data);
    char* ReceiveData();
};
