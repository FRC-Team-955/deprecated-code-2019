#ifndef PID_H
#define PID_H

#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>


class PID {
public:
	PID(
TalonSRX*drive_talon_right_enc,
TalonSRX*drive_talon_left_enc,
TalonSRX*claw_pivot_talon_enc,
TalonSRX*climber_talon_enc,
TalonSRX*elevator_talon_enc,
TalonSRX*seat_talon_enc
		)
	:
	drive_talon_right_enc(drive_talon_right_enc),
	drive_talon_left_enc(drive_talon_left_enc),
	claw_pivot_talon_enc(claw_pivot_talon_enc),
	climber_talon_enc(climber_talon_enc),
	elevator_talon_enc(elevator_talon_enc),
	seat_talon_enc(seat_talon_enc){};
	void run_pid ();
private:
TalonSRX*drive_talon_right_enc;
TalonSRX*drive_talon_left_enc;
TalonSRX*claw_pivot_talon_enc;
TalonSRX*climber_talon_enc;
TalonSRX*elevator_talon_enc;
TalonSRX*seat_talon_enc;

};

#endif
