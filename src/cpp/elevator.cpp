//PID TUNE
#include <elevator.h>


void Elevator::run_elevator (double rocket_low_hatch_pos, double rocket_low_ball_pos, double rocket_medium_hatch_pos, double rocket_medium_ball_pos,double rocket_high_hatch_pos,double rocket_high_ball_pos) {
//Auto Mode
if (mode==0){
//Switching Pos
	std::cout<<"AUTO MODE ON"<<std::endl;
	std::cout<<"current_elevator_pos="<<current_elevator_pos<<std::endl;
	if (joy1->GetRawButton(2)==1 and toggle1 ==0) {
	current_elevator_pos = current_elevator_pos +1;
	toggle1 = 1;
	}
	if (joy1->GetRawButton(2)==0 and toggle1 ==1){
	toggle1 = 0;
	}
	if (joy1->GetRawButton(1)==1 and toggle2==0) {
	current_elevator_pos = current_elevator_pos -1;
	toggle2=1;
	}
	if (joy1->GetRawButton(1)==0 and toggle2 ==1){
	toggle2 = 0;
	}
//Determining Ball Pos
	if (toggle_hatch1 == 0){
		if (current_elevator_pos >= 4){
		current_elevator_pos =3;
		}
		if (current_elevator_pos <=0){
		current_elevator_pos = 1;
		}
		if (current_elevator_pos ==1){
		talon_elevator_enc->Set(ControlMode::Position, rocket_low_ball_pos);
		}
		if (current_elevator_pos ==2){
		talon_elevator_enc->Set(ControlMode::Position, rocket_medium_ball_pos);
		}
		if (current_elevator_pos==3){
		talon_elevator_enc->Set(ControlMode::Position, rocket_high_ball_pos);
		}
	}
//Determining Hatch Pos
	if (joy1->GetRawButton(3)==1 and toggle_hatch1==0){
		if (current_elevator_pos == 1) {
		talon_elevator_enc->Set(ControlMode::Position, rocket_low_hatch_pos);
		}
		if (current_elevator_pos == 2){
		talon_elevator_enc->Set(ControlMode::Position, rocket_medium_hatch_pos);
		}
		if (current_elevator_pos ==3 ){
		talon_elevator_enc->Set(ControlMode::Position, rocket_high_hatch_pos);
		}
	toggle_hatch1 = 1;
	}
	if (toggle_hatch1 == 1 and joy1->GetRawButton(1)==1 or joy1->GetRawButton(2)== 1){
		if (current_elevator_pos >= 4){
		current_elevator_pos =3;
		}
		if (current_elevator_pos <=0){
		current_elevator_pos = 1;
		}
		if (current_elevator_pos ==1){
		talon_elevator_enc->Set(ControlMode::Position, rocket_low_ball_pos);
		}
		if (current_elevator_pos ==2){
		talon_elevator_enc->Set(ControlMode::Position, rocket_medium_ball_pos);
		}
		if (current_elevator_pos==3){
		talon_elevator_enc->Set(ControlMode::Position, rocket_high_ball_pos);
		}
	toggle_hatch1 =0;	
	}

}
//Manual Mode
if (joy1->GetRawButton(7)==1 and mode_toggle1 == 0 and mode_toggle2 ==0){
	mode= 1;
	mode_toggle1 = 1;
}
if (joy1->GetRawButton(7)==0 and mode_toggle1){
	mode_toggle2=1;
}
if (joy1->GetRawButton(7)== 1 and mode_toggle2 == 1){
	mode = 0;
	mode_toggle2 =2;
}
if (joy1->GetRawButton(7)==0 and mode_toggle2 == 2){
	mode_toggle1=0;
	mode_toggle2=0;
}
if (mode ==1){
	talon_elevator_enc->Set(ControlMode::PercentOutput, joy1->GetRawAxis(1)* -1 *joy1->GetRawAxis(1)* joy1->GetRawAxis(1));
	std::cout<<"MANUAL MODE ON"<<std::endl;
}


}




