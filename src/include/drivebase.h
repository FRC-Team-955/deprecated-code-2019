#ifndef DRIVEBASE_H
#define DRIVEBASE_H

#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>


class Drivebase {
public:
	Drivebase(
		Joystick *joy,
		TalonSRX *talon_left_enc,
		TalonSRX *talon_left_noenc,
		TalonSRX *talon_right_enc,
		TalonSRX *talon_right_noenc
	):
		joy(joy),
		talon_left_enc(talon_left_enc),
		talon_left_noenc(talon_left_noenc),
		talon_right_enc(talon_right_enc),
		talon_right_noenc(talon_right_noenc)
	{
	};

	void update();
private:
	TalonSRX *talon_left_enc, *talon_left_noenc;
	TalonSRX *talon_right_enc, *talon_right_noenc;
	Joystick *joy;
};

#endif
