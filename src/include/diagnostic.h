#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>
#include <typeinfo> // we may need this for type differentiation


class Diagnostic {
private:
	void tickID(bool sign);
	void writeToCurrentTalon(float speed);

	int currentID=0;
	TalonSRX* talonCatalog[10]={};
	Joystick *joy;

public:
	void update();

	// initialize diagnostic
	Diagnostic (
		// receive parameters
		Joystick *joy,
		TalonSRX *drivebase_left_enc,
		TalonSRX *drivebase_left_noenc,
		TalonSRX *drivebase_right_enc,
		TalonSRX *drivebase_right_noenc,
		TalonSRX *intake_wheels,
		TalonSRX *intake_clamp,
		TalonSRX *elevator_enc,
		TalonSRX *elevator_noenc
	):
		// initialize member variables
		joy(joy),// joystick
		talonCatalog({// all the talons arranged in an array
			drivebase_left_enc,
            drivebase_left_noenc,
            drivebase_right_enc,
            drivebase_right_noenc,
            intake_wheels,
            intake_clamp,
            elevator_enc,
            elevator_noenc
		})
	{
		// run on initialization
		std::cout<<"initializing diagnostic";
	};
};

#endif
