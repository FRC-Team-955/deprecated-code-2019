#include <elevator.h>


// run this in TeleopPeriodic
void Elevator :: update () {

	std::cout<<"updating elevator";

	// collect values from joystick
	float upspeed = joy1->GetRawAxis( elevator_up_joynum );
	float downspeed = joy1->GetRawAxis( elevator_down_joynum );

	std::cout<<"\tup throttle="<<upspeed;
	std::cout<<"\tdown throttle="<<downspeed;

	// skew the values to get tiny motion with the belly of the joystick range and high values at the extremes
	upspeed = signedpow(upspeed, elevator_up_exp );
	downspeed = signedpow(downspeed, elevator_down_exp );

	// write to motor; add directions together so switching between up and down is smooth
	talon_enc->Set(ControlMode::PercentOutput, upspeed-downspeed );

	std::cout<<"\televator speed="<<upspeed-downspeed<<std::endl;
};
