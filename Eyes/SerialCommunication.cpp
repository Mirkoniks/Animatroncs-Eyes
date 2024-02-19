#include "SerialCommunication.h"

void SerialCommunication::SendData(String data)
{
    this->jetsonSoftwareSerial.println(data);
}

String SerialCommunication::ReceiveData()
{
  String data = "";

  if (this->jetsonSoftwareSerial.available() > 0) 
  {
    data = this->jetsonSoftwareSerial.readStringUntil('\n');
  }

  return data;
}

void SerialCommunication::init()
{
  this->jetsonSoftwareSerial.begin(9600);
}

