#ifndef CLIMBER_H
#define CLIMBER_H

#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>

class Climber {
public:
	Climber(
Joystick *joy1, TalonSRX* climber_talon_vertical_enc, TalonSRX* climber_talon_drive_enc)

: joy1(joy1), climber_talon_vertical_enc(climber_talon_vertical_enc), climber_talon_drive_enc(climber_talon_drive_enc){};


void run_climber(double max_speed);
private:
	Joystick* joy1;
	TalonSRX* climber_talon_vertical_enc;
	TalonSRX* climber_talon_drive_enc;

};


#endif
