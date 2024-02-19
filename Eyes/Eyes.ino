#include "EyeControl.h"
#include "SerialCommunication.h"
#include <SoftwareSerial.h> 
#include <ArduinoJson.h>

ServoConfig config = 
{
  LEFT_EYE_TILT,
  LEFT_EYE_PAN,
  RIGHT_EYE_TILT, 
  RIGHT_EYE_PAN,
  EYELIDS_TILT, 
  EYELIDS_OPENNESS
};

EyeControl eyeControl;
SerialCommunication jetsonSerial;
SoftwareSerial jSerial(A5,A4);
StaticJsonDocument<1024> cmd;

int number;

void setup() 
{
  eyeControl.init(&config);
  jetsonSerial = SerialCommunication();
  Serial.begin(9600);
  jSerial.begin(9600);
}

int oldValue = 1500;
int smooth = 1500;

void loop() 
{
  // if (Serial.available() > 0) 
  // {
  //   number = Serial.parseInt();
    
  //   if (Serial.read() == '\n') 
  //   {
  //     Serial.print("Received Number: ");
  //     Serial.println(number);

  //     smooth = (number * 0.1) + (oldValue * 0.10);
  //     oldValue = smooth;

  //     Serial.println(smooth);
  //     Serial.println(oldValue);

  //     eyeControl.PanLeftEye(smooth);
  //     eyeControl.PanRightEye(smooth);   
  //   } 
  //   else 
  //   {
  //     Serial.println("Error: Invalid input. Please enter a valid integer.");
  //   }

  //     Serial.println(number);
  // }

  // uint16_t smoth = eyeControl.SmoothMotion(eyeControl.getLeftEyePanOldValue(), number); 

 if (jSerial.available() > 0) 
  {
    String data = jSerial.readStringUntil('\n');
    // Serial.print("Received: ");
    // Serial.println(data);

    jSerial.println("Hello from Arduino Nano");

    DeserializationError error = deserializeJson(cmd, data);

    if (error) 
    {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
    }
  }
  String b = cmd["action"];

  Serial.println(b);
}
