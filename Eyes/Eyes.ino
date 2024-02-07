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

void setup() 
{
  eyeControl.init(&config);
  eyeControl.SetupServos();

  Serial.begin(9600); 
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    int number = Serial.parseInt();
    
    if (Serial.read() == '\n') 
    {
      Serial.print("Received Number: ");
      Serial.println(number);
      eyeControl.TiltLeftEye(number);
      
    } else 
    {
      Serial.println("Error: Invalid input. Please enter a valid integer.");
    }
  }
}
