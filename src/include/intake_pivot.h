//NEEDS TO BE PID TUNED
#ifndef INTAKE_PIVOT_H
#define INTAKE_PIVOT_H

#include <WPILib.h>
#include <ctre/Phoenix.h>
#include <iostream>

class Intake_pivot {
public:
	Intake_pivot(
TalonSRX* talon_intake_pivot,
Joystick* joystick
)
:
talon_intake_pivot(talon_intake_pivot),
joystick (joystick){};

void run_intake_pivot (int toggle, int toggle_two);

private:
TalonSRX* talon_intake_pivot;
Joystick* joystick;

		






};
#endif