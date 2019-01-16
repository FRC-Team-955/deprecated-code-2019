#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>


class Elevator {
public:
	// initialize elevator
	Elevator(
		// receive parameters
		Joystick *joy1,
		TalonSRX *talon_enc,
		TalonSRX *talon_noenc
	):
		// initialize member variables
		joy1(joy1),
		talon_enc(talon_enc),
		talon_noenc(talon_noenc)
	{
		// run on initialization
		std::cout<<"initializing elevator";
		// setup the talons so they run together
		talon_noenc->Set(ControlMode::Follower, talon_enc->GetDeviceID() );
	};

	// run this in TeleopPeriodic
	void update();
private:
	Joystick *joy1;
	TalonSRX *talon_enc, *talon_noenc;
};

#endif
