#include <PID.h>


void PID::run_pid (){
drive_talon_right_enc->Config_kP(0,0,10);
drive_talon_right_enc->Config_kI(0,0,10);
drive_talon_right_enc->Config_kD(0,0,10);
drive_talon_right_enc->Config_kF(0,0,10);

drive_talon_left_enc->Config_kP(0,0,10);
drive_talon_left_enc->Config_kI(0,0,10);
drive_talon_left_enc->Config_kD(0,0,10);
drive_talon_left_enc->Config_kF(0,0,10);

claw_pivot_talon_enc->Config_kP(0,0,10);
claw_pivot_talon_enc->Config_kI(0,0,10);
claw_pivot_talon_enc->Config_kD(0,0,10);
claw_pivot_talon_enc->Config_kF(0,0,10);

climber_talon_enc->Config_kP(0,0,10);
climber_talon_enc->Config_kI(0,0,10);
climber_talon_enc->Config_kD(0,0,10);
climber_talon_enc->Config_kF(0,0,10);

elevator_talon_enc->Config_kP(0,0,10);
elevator_talon_enc->Config_kI(0,0,10);
elevator_talon_enc->Config_kD(0,0,10);
elevator_talon_enc->Config_kF(0,0,10);

seat_talon_enc->Config_kP(0,0,10);
seat_talon_enc->Config_kI(0,0,10);
seat_talon_enc->Config_kD(0,0,10);
seat_talon_enc->Config_kF(0,0,10);

//talon->Config_kP(0, SmartDashboard::GetNumber ("DB/Slider 0"),10);
//talon->Config_kI(0, SmartDashboard::GetNumber ("DB/Slider 1"),10);
//talon->Config_kD(0, SmartDashboard::GetNumber ("DB/Slider 2"),10);
//talon->Config_kF(0, SmartDashboard::GetNumber ("DB/Slider 3"),10);


}
