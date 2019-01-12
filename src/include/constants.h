#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <math.h>


// joystick button/axis numbers
const int joynum_drivebase_move = 1;
const int joynum_drivebase_turn = 1;


// exponents for driving- this way, most of the joystick's range will correspond to low values, and only the extremes will make high speeds
const int drivebase_move_exp = 2;
const int drivebase_turn_exp = 3;

// raise number to given exponent, but preserve its sign
#define signedpow(val,exp) copysignf(powf(val,exp),val)

#endif
