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
    Servo eyelidsOpennes;

    uint16_t leftEyeTiltOldValue = 0;
    uint16_t leftEyePanOldValue = 0;
    uint16_t rightEyeTiltOldValue = 0;
    uint16_t rightEyePanOldValue = 0;
    uint16_t eyelidsTiltOldValue = 0;
    uint16_t eyelidsOpennesOldValue = 0;

    bool EvaluateServoInputValie(uint16_t degrees);
    void MoveServo(uint16_t value, Servo servo);
    uint16_t SmoothMotion(uint16_t oldValue, uint16_t newValue);

  public:

    void init(ServoConfig* servoConfig);

    void SetupServos();
  
    int8_t TiltLeftEye(uint16_t degrees);
    int8_t PanLeftEye(uint16_t degrees);
    int8_t TiltRightEye(uint16_t degrees);
    int8_t PanRightEye(uint16_t degrees);
    int8_t TiltEyelids(uint16_t degrees);
    int8_t ChangeEyeOpenness(uint16_t degrees);
};