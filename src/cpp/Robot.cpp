#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>
#include <drivebase.h>
#include <intake_wheels.h>
#include <intake_clamp.h>
#include <diagnostic.h>


// Robot modes
#define DRIVEBASE 0
#define WHEELS 0 //TODO
#define CLAMP 0
#define DIAGNOSTIC 1


class Robot: public IterativeRobot{

	//Talons
	TalonSRX *talon_drivebase_left_enc, *talon_drivebase_right_enc, *talon_drivebase_left_noenc, *talon_drivebase_right_noenc,
		*talon_intake_wheels, *talon_intake_clamp, *talon_intake_pivot,
		*talon_elevator_enc, *talon_elevator_noenc,
		*talon_climber_wheels;

	//Objects
	Drivebase *db;
	Intake_wheels *wheels;
	Intake_clamp *clamp;
	Diagnostic *diagnostic;

	//Other Variables
	Joystick *joy;

    void RobotInit(){

		joy=new Joystick(0);

		talon_drivebase_left_enc=new TalonSRX( drivebase_left_enc_talonnum );
		talon_drivebase_left_noenc=new TalonSRX( drivebase_left_noenc_talonnum );
		talon_drivebase_right_enc=new TalonSRX( drivebase_right_enc_talonnum );
		talon_drivebase_right_noenc=new TalonSRX( drivebase_right_noenc_talonnum );

		talon_intake_wheels=new TalonSRX( intake_wheels_talonnum );
		talon_intake_clamp=new TalonSRX( intake_clamp_talonnum );
		talon_intake_pivot=new TalonSRX( intake_pivot_talonnum );

		talon_elevator_enc=new TalonSRX( elevator_enc_talonnum );
		talon_elevator_noenc=new TalonSRX( elevator_noenc_talonnum );

		talon_climber_wheels=new TalonSRX( climber_wheels_talonnum );

#if DRIVEBASE
		std::cout<<"andrew drivebase test- oohhh boy here we go"<<std::endl;
		db=new Drivebase(joy,talon_drivebase_left_enc,talon_drivebase_left_noenc,talon_drivebase_right_enc,talon_drivebase_right_noenc);
#elif WHEELS
		std::cout<<"andrew intake_wheels test- oohhh boy here we go"<<std::endl;
		wheels=new Intake_wheels(joy,talon_intake_wheels);
#elif CLAMP
		std::cout<<"andrew intake_clamp test- oohhh boy here we go"<<std::endl;
		clamp=new Intake_clamp(joy,talon_intake_clamp);
#elif DIAGNOSTIC
		std::cout<<"andrew diagnostic test- oohhh boy here we go"<<std::endl;
		diagnostic=new Diagnostic(
			joy,
			talon_drivebase_left_enc,
			talon_drivebase_left_noenc,
			talon_drivebase_right_enc,
			talon_drivebase_right_noenc,
			talon_intake_wheels,
			talon_intake_clamp,
			talon_intake_pivot,
			talon_elevator_enc,
			talon_elevator_noenc,
			talon_climber_wheels
		);
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
		std::cout<<"aiight we gon' diagnose dis nau"<<std::endl;
    }
    void TestPeriodic(){
#if DIAGNOSTIC
		diagnostic->update();
#endif
    }

    void DisabledInit(){
    }
    void DisabledPeriodic(){
    }

};
START_ROBOT_CLASS(Robot);
