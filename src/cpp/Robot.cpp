#include "WPILib.h"
#include <ctre/Phoenix.h>
#include <iostream>
#include <intake_pivot.h>
#include <elevator.h>

class Robot: public IterativeRobot{

TalonSRX* talon_elevator_enc;
TalonSRX* talon_elevator_noenc;
Joystick* joy1;
Elevator* elevator;

   /* Intake Pivot Code
   TalonSRX* talon_intake_pivot;
   TalonSRX* follower_moter;
   Joystick* joystick;
   Intake_pivot* intake_pivot;
   */

	

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
        */
        talon_elevator_enc = new TalonSRX(2);
        talon_elevator_noenc = new TalonSRX(1);
        talon_elevator_noenc->Set(ControlMode::Follower, 2);
        joy1= new Joystick(1);
        elevator = new Elevator(talon_elevator_enc, talon_elevator_noenc, joy1);

        std::cout<<"Megalovania v12.0"<<std::endl;
        
    }

    void TeleopInit(){

    }
    void TeleopPeriodic(){
elevator->run_elevator(1,1);
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
