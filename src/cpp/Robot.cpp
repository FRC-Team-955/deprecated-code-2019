#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <constants.h>
#include <drivebase.h>

class Robot: public IterativeRobot{

	//Talons
	TalonSRX *talon_left, *talon_right, *talon_left_noenc, *talon_right_noenc;

	//Objects
	Drivebase *db;

	//Other Variables
	Joystick *joy;

    void RobotInit(){
		std::cout<<"oohhh boy here we go andrew drivebase test"<<std::endl;
		talon_left=new TalonSRX(3);
		talon_right=new TalonSRX(2);
		talon_left_noenc=new TalonSRX(4);
		talon_right_noenc=new TalonSRX(1);

		joy=new Joystick(0);

		db=new Drivebase(joy,talon_left,talon_left_noenc,talon_right,talon_right_noenc);
    }

    void TeleopInit(){
		std::cout<<"lezgo"<<std::endl;
    }
    void TeleopPeriodic(){
		std::cout<<"periodic"<<std::endl;
		db->update();
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
