#pragma once
#include <SPI.h>

class SerialCommunication
{
  public:
    void SetupCommunication();
    void SendData(byte data);
    byte ReceiveData();
};
