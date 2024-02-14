#include "Globals.h"
#include "SerialCommunication.h"

void SerialCommunication::SetupCommunication()
{
    SPI.begin();
}

void SerialCommunication::SendData(byte data)
{
    SPI.transfer(data);
}

byte SerialCommunication::ReceiveData()
{
    byte data = SPI.transfer(0x00);

    return data;
}
