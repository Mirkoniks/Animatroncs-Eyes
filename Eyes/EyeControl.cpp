#include "EyeControl.h"

void EyeControl::init(ServoConfig* servoConfig)
{
  this->servoConfig = *servoConfig;
}

void EyeControl::SetupServos()
{
  leftEyeTilt.attach(servoConfig.LeftEyeTiltPin);
  leftEyePan.attach(servoConfig.LeftEyePanPin);
  rightEyeTilt.attach(servoConfig.RightEyeTiltPin);
  rightEyePan.attach(servoConfig.RightEyePanPin);
  eyelidsTilt.attach(servoConfig.EyelidsTiltPin);
  eyelidsOpennes.attach(servoConfig.EyelidsOpennessPin);
  
  #if WRITE_DEFAULT_POSITON_ON_POWER_ON == 1

    TiltLeftEye(DEFAULT_LEFT_EYE_TILT_DEGREES);
    PanLeftEye(DEFAULT_LEFT_EYE_PAN_DEGREES);
    TiltRightEye(DEFAULT_RIGHT_EYE_TILT_DEGREES);
    PanRightEye(DEFAULT_RIGHT_EYE_PAN_DEGREES);
    TiltEyelids(DEFAULT_EYELIDS_TILT_DEGREES);
    ChangeEyeOpenness(DEFAULT_EYELIDS_OPENNESS_DEGREES);
    
  #endif
}

int8_t EyeControl::TiltLeftEye(uint16_t value)
{
  if(EvaluateServoInputValie(value))
  {
    MoveServo(value,leftEyeTilt);
    return value;
  }
  return -1;
}
int8_t EyeControl::PanLeftEye(uint16_t value)
{
  if(EvaluateServoInputValie(value))
  {
    MoveServo(value,leftEyePan);
    return value;
  }
  return -1;
}
int8_t EyeControl::TiltRightEye(uint16_t value)
{
  if(EvaluateServoInputValie(value))
  {
    MoveServo(value,rightEyeTilt);
    return value;
  }
  return -1;
}
int8_t EyeControl::PanRightEye(uint16_t value)
{
  if(EvaluateServoInputValie(value))
  {
    MoveServo(value,rightEyePan);
    return value;
  }
  return -1;
}
int8_t EyeControl::TiltEyelids(uint16_t value)
{
  if(EvaluateServoInputValie(value))
  {
    MoveServo(value,eyelidsTilt);
    return value;    
  }
  return -1;
}
int8_t EyeControl::ChangeEyeOpenness(uint16_t value)
{
  if(EvaluateServoInputValie(value))
  {
    MoveServo(value,eyelidsOpennes);
    return value;
  }
  return -1;
}

// Private

bool EyeControl::EvaluateServoInputValie(uint16_t value)
{
  // if(value <= MAX_SERVO_VALUE && degrees >= MIN_SERVO_VALUE)
  // {
  //   return true;
  // }
  // else if(value > MAX_SERVO_VALUE && value < 2300 && value > 700)
  // return false;

  return true;
}

void EyeControl::MoveServo(uint16_t value, Servo servo)
{
  servo.writeMicroseconds(value);
}

uint16_t EyeControl::SmoothMotion(uint16_t oldValue, uint16_t newValue)
{
    // uint16_t switch1Smoothed = (newValue * 0.05) + (switch1Smoothed * 0.95);

    // switch1Prev = switch1Smoothed;

    // return switch1Smoothed;
    return 1;
}
