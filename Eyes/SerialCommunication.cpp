#include "Globals.h"
#include "SerialCommunication.h"

void SerialCommunication::init()
{
  SetupCommunication();
}

void SerialCommunication::SetupCommunication()
{
    SPI.begin();
}

void SerialCommunication::SendData(byte data)
{
    SPI.transfer(data);
}

char* SerialCommunication::ReceiveData()
{
  char receivedData[256];
  int index = 0;

   while (1) {
    char receivedByte = SPI.transfer(0x00); 
    if (receivedByte == '\0') {
      break; 
    }
    receivedData[index++] = receivedByte;
  }

  receivedData[index] = '\0';
  
  return receivedData;
}
