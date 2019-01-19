#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>

class Elevator {
public:
	Elevator(
TalonSRX* talon_elevator_enc,
TalonSRX* talon_elevator_noenc,
Joystick* joy1
)
:
talon_elevator_enc(talon_elevator_enc),
talon_elevator_noenc(talon_elevator_noenc),
joy1(joy1){};
void run_elevator (double upspeed, double downspeed);
private:
	TalonSRX* talon_elevator_enc;
TalonSRX* talon_elevator_noenc;
Joystick* joy1;







};



#endif
