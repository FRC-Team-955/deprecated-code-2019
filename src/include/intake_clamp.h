#ifndef INTAKE_CLAMP_H
#define INTAKE_CLAMP_H

#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>


class Intake_clamp {
public:
	// initialize intake_clamp
	Intake_clamp (
		// receive parameters
		Joystick *joy1,
		TalonSRX *talon_clamp
	):
		// initialize member variables
		joy1(joy1),
		talon_clamp(talon_clamp)
	{
		// run on initialization
		std::cout<<"initializing intake_clamp";
	};

	// run this in TeleopPeriodic
	void update();
private:
	Joystick *joy1;
	TalonSRX *talon_clamp;
	bool closeButton=false, openButton=false;
	float clampSpeed = intake_clamp_speed;
};

#endif
