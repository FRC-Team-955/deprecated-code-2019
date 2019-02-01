//NEEDS TO BE PID TUNED
#include <intake_pivot.h>

void Intake_pivot::run_intake_pivot (int toggle, int toggle_two) {
if (joystick->GetRawButton(5)==1 and toggle == 0 and toggle_two==0){

	talon_intake_pivot->Set(ControlMode::Position, 20000);
	toggle = 1;
}
if (joystick->GetRawButton(5)==0 and toggle == 1) {

	toggle = 2;
}
if (joystick->GetRawButton(5)==1 and toggle_two == 2) {

	talon_intake_pivot->Set(ControlMode::Position, -20000);
	toggle_two = 1;
}
if (joystick->GetRawButton(5)==0 and toggle_two==1){
	toggle_two =0;
	toggle = 0;
}
}