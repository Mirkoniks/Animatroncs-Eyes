#include "EyeControl.h"
#include "SerialCommunication.h"

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
SerialCommunication serialCommunication;

int number;

void setup() 
{
  eyeControl.init(&config);
  serialCommunication.init();
  Serial.begin(9600); 
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

  //uint16_t smoth = eyeControl.SmoothMotion(eyeControl.getLeftEyePanOldValue(), number); 

  char* a = serialCommunication.ReceiveData();

  Serial.println(a);
}
