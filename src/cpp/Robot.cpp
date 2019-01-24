#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>
#include <drivebase.h>
#include <intake_wheels.h>
#include <intake_clamp.h>


// Robot modes
#define DRIVEBASE 0
#define WHEELS 0
#define CLAMP 1
#define DIAGNOSTIC 0


class Robot: public IterativeRobot{

	//Talons
	TalonSRX *talon_left, *talon_right, *talon_left_noenc, *talon_right_noenc, *talon_clamp;

	//Objects
	Drivebase *db;
	Intake_wheels *wheels;
	Intake_clamp *clamp;

	//Other Variables
	Joystick *joy1;

    void RobotInit(){

		joy1=new Joystick(0);

#if DRIVEBASE
		std::cout<<"andrew drivebase test- oohhh boy here we go"<<std::endl;
		talon_left=new TalonSRX( drivebase_left_enc_talonnum );
		talon_left_noenc=new TalonSRX( drivebase_left_noenc_talonnum );
		talon_right=new TalonSRX( drivebase_right_enc_talonnum );
		talon_right_noenc=new TalonSRX( drivebase_right_noenc_talonnum );

		db=new Drivebase(joy1,talon_left,talon_left_noenc,talon_right,talon_right_noenc);
#elif WHEELS
		std::cout<<"andrew intake_wheels test- oohhh boy here we go"<<std::endl;
		talon_left=new TalonSRX( intake_wheels_left_talonnum );
		talon_right=new TalonSRX( intake_wheels_right_talonnum );

		wheels=new Intake_wheels(joy1,talon_left,talon_right);
#elif CLAMP
		std::cout<<"andrew intake_clamp test- oohhh boy here we go"<<std::endl;
		talon_clamp=new TalonSRX( intake_clamp_talonnum );

		clamp=new Intake_clamp(joy1,talon_clamp);
#endif
    }

    void TeleopInit(){
		std::cout<<"lezgo"<<std::endl;
    }
    void TeleopPeriodic(){
		std::cout<<"periodic"<<std::endl;
#if DRIVEBASE
		db->update();
#elif WHEELS
		wheels->update();
#elif CLAMP
		clamp->update();
#endif
    }

    void AutonomousInit(){
    }
    void AutonomousPeriodic(){
    }

    void TestInit(){
    }
    void TestPeriodic(){
    }

    void DisabledInit(){
    }
    void DisabledPeriodic(){
    }

};
START_ROBOT_CLASS(Robot);
