#pragma once
#include "Globals.h"
#include <SoftwareSerial.h>

class SerialCommunication
{
  private:
    SoftwareSerial jetsonSoftwareSerial = SoftwareSerial(RX_NANO,TX_NANO);

  public:

    void init();

    void SendData(String data);
    String ReceiveData();
};
