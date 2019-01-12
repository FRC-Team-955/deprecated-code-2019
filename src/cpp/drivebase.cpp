#include <drivebase.h>


void Drivebase :: update () {
	// collect values from joystick
	float move = joy->GetRawAxis( joynum_drivebase_move );
	float turn = joy->GetRawAxis( joynum_drivebase_turn );

	// skew the values to get tiny motion with the belly of the joystick range and high values at the extremes
	move = signedpow(move,drivebase_move_exp);
	turn = signedpow(turn,drivebase_turn_exp);

	// write to motors
	talon_left_enc->Set(ControlMode::PercentOutput,  move-turn);
	talon_right_enc->Set(ControlMode::PercentOutput, -move-turn);
};
