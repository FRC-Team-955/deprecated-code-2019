#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <intake_pivot.h>
#include <elevator.h>
#include <climber.h>
class Robot: public IterativeRobot{
public:

Robot(){}
Joystick *joy1;
TalonSRX *talon_elevator_enc;
TalonSRX *yeet;
Elevator *elevator;

    void RobotInit(){
        talon_elevator_enc= new TalonSRX(3);
        yeet = new TalonSRX(4);
        yeet->Set(ControlMode::Follower, 3);
        
        joy1 = new Joystick(0);
        elevator = new Elevator (talon_elevator_enc, joy1);
        talon_elevator_enc->Config_kP(0, 6.420360, 10);
        talon_elevator_enc->Config_kI(0, 0, 10);
        talon_elevator_enc->Config_kD(0, 0, 10);

        std::cout<<"Megalovania v197"<<std::endl;
        
    }

    void TeleopInit(){

    }
    void TeleopPeriodic(){
elevator->run_elevator(20000, 10000, 40000, 30000, 60000, 50000);
std::cout<<"Pos="<<talon_elevator_enc->GetSelectedSensorPosition(0)- 3333<<std::endl;





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
talon_elevator_enc->SetSelectedSensorPosition(0,0,10);
    }
    void DisabledPeriodic(){
        
    }

};
START_ROBOT_CLASS(Robot);




































































// OLD CODE
/*
#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <intake_pivot.h>
#include <elevator.h>
#include <climber.h>
class Robot: public IterativeRobot{
public:
//TalonSRX* talon_elevator_enc;
//TalonSRX* talon_elevator_noenc;
Joystick* joy1;
TalonSRX* climber_talon_vertical_enc;
TalonSRX* climber_talon_drive_enc;

//Elevator* elevator;
Climber*climber;

   /* Intake Pivot Code
   TalonSRX* talon_intake_pivot;
   TalonSRX* follower_moter;
   Joystick* joystick;
   Intake_pivot* intake_pivot;
   

    

    void RobotInit(){
        /*intakepivot code
        talon_intake_pivot = new TalonSRX(2);
        //false motor
        follower_moter = new TalonSRX(1);
        follower_moter->Set(ControlMode::Follower, 2);
        //false motor
        talon_intake_pivot->Config_kP(0, 10, 10);
        talon_intake_pivot->Config_kI(0, 0, 10);
        talon_intake_pivot->Config_kD(0, 0, 10);
        joystick = new Joystick (0);
        intake_pivot = new Intake_pivot(talon_intake_pivot, joystick);
        
        joy1= new Joystick(1);
        //talon_elevator_enc = new TalonSRX(2);
        //talon_elevator_noenc = new TalonSRX(1);
        climber_talon_vertical_enc= new TalonSRX(4);
        climber_talon_drive_enc= new TalonSRX(3);
        
        //talon_elevator_noenc->Set(ControlMode::Follower, 2);
        climber = new Climber (joy1, climber_talon_vertical_enc, climber_talon_drive_enc);
        
        //elevator = new Elevator(talon_elevator_enc, talon_elevator_noenc, joy1);


        std::cout<<"Megalovania v180"<<std::endl;
        
    }

    void TeleopInit(){

    }
    void TeleopPeriodic(){
//elevator->run_elevator(1,1);
climber->run_climber(1);
//talon_intake_pivot->Set(ControlMode::Position, 20000);
//std::cout<<"error"<<20000-talon_intake_pivot->GetSelectedSensorPosition(0)<<std::endl;







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
        //talon_intake_pivot->SetSelectedSensorPosition(0,0,10);
    }
    void DisabledPeriodic(){
        
    }

};
START_ROBOT_CLASS(Robot);
*/









