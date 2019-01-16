#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <math.h>


// talon numbers
const int drivebase_left_enc_talonnum = 0;
const int drivebase_left_noenc_talonnum = 1;
const int drivebase_right_enc_talonnum = 2;
const int drivebase_right_noenc_talonnum = 3;
const int intake_wheels_left_talonnum = 4;
const int intake_wheels_right_talonnum = 5;
const int intake_clamp_talonnum = 6;
const int elevator_enc_talonnum = 7;
const int elevator_noenc_talonnum = 8;


/*			Joystick #0
	  A2           A3			  0,1=	out/in climber
   _/III\4_______/III\5				2=	
  /  A1             3  \			3=	
 /  (8)A0  6 H 7  2   1 \<-trg		4=	
 \       ^          0   /<-top		5=	
 /     <POV>    A5      \			6=	
/        v     (9)A4     \			7=	
\      ____________      /		A1,A4=	drive
 \____/            \____/
*/
// joystick 0 axis numbers
const int drivebase_move_joynum = 1;
const int drivebase_turn_joynum = 4;
//joystick 0 button numbers


/*			Joystick #1
	  A2           A3			  0,1=	suck out/in intake_wheels
   _/III\4_______/III\5				2=	
  /  A1             3  \			3=	
 /  (8)A0  6 H 7  2   1 \<-trg		4=	
 \       ^          0   /<-top		5=	
 /     <POV>    A5      \		   A1=	up/down intake_pivot
/        v     (9)A4     \		A2,A3=	elevator
\      ____________      /		   A5=	close/open intake_clamp
 \____/            \____/
*/
// joystick 1 axis numbers
const int elevator_up_joynum = 2;
const int elevator_down_joynum = 3;
// joystick 1 button numbers
const int intake_wheels_in_joynum = 4;
const int intake_wheels_out_joynum = 5;
const int intake_clamp_close_joynum = 3;
const int intake_clamp_open_joynum = 4;


// wheel velocities
const float drivebase_max_speed = 0.8;
const float intake_wheels_speed = 0.4;
const float intake_clamp_speed  = 0.2;


// exponents for variable motion values- this way, most of the joystick's range will correspond to low values, and only the extremes will make high speeds
const int drivebase_move_exp = 2;
const int drivebase_turn_exp = 3;
const int elevator_up_exp = 2;
const int elevator_down_exp = 2;

// raise number to given exponent, but preserve its sign. I made it a preproccessor macro so the compiler wouldn't complain about defining a function multiple times, and it is faster anyway.
#define signedpow(val,exp) copysignf(powf(val,exp),val)

#endif
