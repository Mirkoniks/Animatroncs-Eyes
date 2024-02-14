#pragma once
#include "Globals.h"
#include <Servo.h>

typedef struct
{
  uint8_t LeftEyeTiltPin;
  uint8_t LeftEyePanPin;
  uint8_t RightEyeTiltPin;
  uint8_t RightEyePanPin;
  uint8_t EyelidsTiltPin;
  uint8_t EyelidsOpennessPin;
} ServoConfig;

class EyeControl
{
  private:
    ServoConfig servoConfig;
    Servo leftEyeTilt;
    Servo leftEyePan;
    Servo rightEyeTilt;
    Servo rightEyePan;
    Servo eyelidsTilt;
    Servo eyelidsOpenness;

    uint16_t* leftEyeTiltOldValue;
    uint16_t* leftEyePanOldValue;
    uint16_t* rightEyeTiltOldValue;
    uint16_t* rightEyePanOldValue;
    uint16_t* eyelidsTiltOldValue;
    uint16_t* eyelidsOpennessOldValue;

    bool EvaluateServoInputValie(uint16_t degrees);
    void MoveServo(uint16_t value, Servo servo);

  public:

    uint16_t getLeftEyeTiltOldValue();
    uint16_t* getLeftEyePanOldValue();
    uint16_t getRightEyeTiltOldValue();
    uint16_t getRightEyePanOldValue();
    uint16_t getEyelidsTiltOldValue();
    uint16_t getEyelidsOpennessOldValue();

    void setLeftEyeTiltOldValue(uint16_t value);
    void setLeftEyePanOldValue(uint16_t value);
    void setRightEyeTiltOldValue(uint16_t value);
    void setRightEyePanOldValue(uint16_t value);
    void setEyelidsTiltOldValue(uint16_t value);
    void setEyelidsOpennessOldValue(uint16_t value);
    
    void init(ServoConfig* servoConfig);

    void SetupServos();
  
    int8_t TiltLeftEye(uint16_t degrees);
    int8_t PanLeftEye(uint16_t degrees);
    int8_t TiltRightEye(uint16_t degrees);
    int8_t PanRightEye(uint16_t degrees);
    int8_t TiltEyelids(uint16_t degrees);
    int8_t ChangeEyeOpenness(uint16_t degrees);
    uint16_t SmoothMotion(uint16_t* oldValue, uint16_t newValue);
};