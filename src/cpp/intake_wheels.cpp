#include <intake_wheels.h>


// run this in TeleopPeriodic
void Intake_wheels :: update () {
	
	std::cout<<"updating intake_wheels";

	// collect values from joystick
	bool inButton = joy1->GetRawAxis( intake_wheels_in_joynum );
	bool outButton = joy1->GetRawAxis( intake_wheels_out_joynum );

	std::cout<<"\tin-"<<inButton<<"  out-"<<outButton;

	// container variable for sucking speed; default is being still
	float suckSpeed = 0.0;

	// if either button is pressed, change the sucking velocity from zero
	if(inButton) suckSpeed = intake_wheels_speed;
	// if both buttons are pressed, "out" overwrites "in"
	if(outButton) suckSpeed =-intake_wheels_speed;

	std::cout<<"\tsuckSpeed="<<suckSpeed;

	// write value to motors
	talon_left->Set(ControlMode::PercentOutput, suckSpeed );
	talon_right->Set(ControlMode::PercentOutput,-suckSpeed );//this one is backwards

	std::cout<<std::endl;
};
