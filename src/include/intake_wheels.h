#ifndef INTAKE_WHEELS_H
#define INTAKE_WHEELS_H

#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>


class Intake_wheels {
public:
	// initialize intake_wheels
	Intake_wheels(
		// receive parameters
		Joystick *joy,
		TalonSRX *talon_left,
		TalonSRX *talon_right
	):
		// initialize member variables
		joy(joy),
		talon_left(talon_left),
		talon_right(talon_right)
	{
		// run on initialization
		std::cout<<"initializing intake_wheels";
	};

	// run this in TeleopPeriodic
	void update();
private:
	Joystick *joy;
	TalonSRX *talon_left, *talon_right;
};

#endif
