#pragma once
#include <Arduino.h>

#define WRITE_DEFAULT_POSITON_ON_POWER_ON 0

#define LEFT_EYE_TILT 3
#define LEFT_EYE_PAN 5

#define RIGHT_EYE_TILT 6 
#define RIGHT_EYE_PAN 9

#define EYELIDS_TILT 10 
#define EYELIDS_OPENNESS 11


#define DEFAULT_LEFT_EYE_TILT 90
#define DEFAULT_LEFT_EYE_PAN 90

#define DEFAULT_RIGHT_EYE_TILT 90
#define DEFAULT_RIGHT_EYE_PAN 90

#define DEFAULT_EYELIDS_TILT 90
#define DEFAULT_EYELIDS_OPENNESS 90


#define MIN_LEFT_EYE_TILT 90
#define MAX_LEFT_EYE_TILT 90

#define MIN_LEFT_EYE_PAN 90
#define MAX_LEFT_EYE_PAN 90

#define MIN_RIGHT_EYE_TILT 90
#define MAX_RIGHT_EYE_PAN 90

#define MIN_EYELIDS_TILT 90
#define MAX_EYELIDS_TILT 90

#define MIN_EYELIDS_OPENNESS 90
#define MAX_EYELIDS_OPENNESS 90

#define SMOOTHING_CONSTANT  0.5
#define SMOOTHING_CONSTANT_OLD_VALUE 0.95

#define RX_NANO A5
#define TX_NANO A4

const int DEFAULT_SERVO_VALUE = 1500;