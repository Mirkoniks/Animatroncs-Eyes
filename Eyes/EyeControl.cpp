#include "EyeControl.h"

uint16_t EyeControl::getLeftEyeTiltOldValue()
{
  uint16_t* value = this->leftEyeTiltOldValue;
  return *value;
}

uint16_t* EyeControl::getLeftEyePanOldValue()
{
  uint16_t* value = this->leftEyePanOldValue;
  return value;
}

uint16_t EyeControl::getRightEyeTiltOldValue()
{
  uint16_t* value = this->rightEyeTiltOldValue;
  return *value;
}

uint16_t EyeControl::getRightEyePanOldValue()
{
  uint16_t* value = this->rightEyePanOldValue;
  return *value;  
}

uint16_t EyeControl::getEyelidsTiltOldValue()
{
  uint16_t* value = this->eyelidsTiltOldValue;
  return *value;
}

uint16_t EyeControl::getEyelidsOpennessOldValue()
{
  uint16_t* value = this->eyelidsOpennessOldValue;
  return *value;
}

void EyeControl::setLeftEyeTiltOldValue(uint16_t value)
{
  *leftEyeTiltOldValue = value;
}

void EyeControl::setLeftEyePanOldValue(uint16_t value)
{
  *leftEyePanOldValue = value;
}

void EyeControl::setRightEyeTiltOldValue(uint16_t value)
{
  *rightEyeTiltOldValue = value;
}

void EyeControl::setRightEyePanOldValue(uint16_t value)
{
  *rightEyePanOldValue = value;
}

void EyeControl::setEyelidsTiltOldValue(uint16_t value)
{ 
  *eyelidsTiltOldValue = value;
}

void EyeControl::setEyelidsOpennessOldValue(uint16_t value)
{
  *eyelidsOpennessOldValue = value;
}

void EyeControl::init(ServoConfig* servoConfig)
{
  this->servoConfig = *servoConfig;
  *eyelidsTiltOldValue = DEFAULT_SERVO_VALUE;
  *leftEyeTiltOldValue = DEFAULT_SERVO_VALUE;
  *leftEyePanOldValue = DEFAULT_SERVO_VALUE;
  *rightEyeTiltOldValue = DEFAULT_SERVO_VALUE;
  *rightEyePanOldValue = DEFAULT_SERVO_VALUE;
  *eyelidsOpennessOldValue = DEFAULT_SERVO_VALUE;

  SetupServos();
}

void EyeControl::SetupServos()
{
  leftEyeTilt.attach(servoConfig.LeftEyeTiltPin);
  leftEyePan.attach(servoConfig.LeftEyePanPin);
  rightEyeTilt.attach(servoConfig.RightEyeTiltPin);
  rightEyePan.attach(servoConfig.RightEyePanPin);
  eyelidsTilt.attach(servoConfig.EyelidsTiltPin);
  eyelidsOpenness.attach(servoConfig.EyelidsOpennessPin);
  
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
    MoveServo(value,eyelidsOpenness);
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

uint16_t EyeControl::SmoothMotion(uint16_t* oldValue, uint16_t newValue)
{
    uint16_t smoothed = (newValue * SMOOTHING_CONSTANT) + (smoothed * SMOOTHING_CONSTANT_OLD_VALUE);

    *oldValue = smoothed;

    return smoothed;
}
