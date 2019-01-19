#include <elevator.h>

void Elevator::run_elevator (double upspeed, double downspeed) {

if (joy1->GetRawAxis(1) < 0) {
talon_elevator_enc->Set(ControlMode::PercentOutput, upspeed*-1*joy1->GetRawAxis(1));

}
if (joy1->GetRawAxis(1) > 0) {
talon_elevator_enc->Set(ControlMode::PercentOutput, downspeed*-1*joy1->GetRawAxis(1));

}




}


