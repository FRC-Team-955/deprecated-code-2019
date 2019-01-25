#include <diagnostic.h>


// increase or decrease ID number
void Diagnostic :: tickID (bool sign) {
	if(sign){
		currentID++;
	}else{
		currentID--;
	}
}

// change value of current talon
void Diagnostic :: writeToCurrentTalon (float speed) {
	talonCatalog[currentID]->Set(ControlMode::PercentOutput, speed );
}

// public handler for all diagnostic operations
void Diagnostic :: update () {
}
