/* Controller */

/* C libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

/* hardware platform libraries */
#include <mbed.h>

/* asteroids */
#include "model.h"
#include "asteroids.h"
#include "view.h"

/* Joystick 5-way switch
*/
enum position { left,down,right,up,centre };
DigitalIn joystick[] = {P5_0, P5_1, P5_4, P5_2, P5_3};
bool jsPrsdAndRlsd(position b);//joystick pollinhg method
bool jsPrsd(position b);//joystick polling method 2

/*list of booleans to check what button has been pressed*/
bool upOk=false;
bool downOk=false;
bool rightOk=false;
bool leftOk=false;
bool centreOk=false;

/*A bool method to see if joystick centre been pressed there is also a class for joystick up and joystick left 
which do the same thing but for different button*/
bool joystickcentre(){
	if(jsPrsd(centre)){
		downOk=true;
		rightOk=false;
		leftOk=false;
		return true;
		}
	else{
		return false;
	}
}

bool joystickup(){
	if(jsPrsd(up)){
		return true;
		}
	else{
		return false;
	}
}
bool joystickleft(){
	if(jsPrsd(left)){
		upOk=false;
		downOk=false;
		rightOk=false;
		leftOk=true;
		centreOk=false;
		return true;
		}
	else{
		return false;
	}
	}


void controls(void)
{
	/*the joystick right and down are both done in the controls method*/
	if(jsPrsdAndRlsd(right)){
		upOk=false;
		downOk=false;
		rightOk=true;
		leftOk=false;
		centreOk=false;
	}
	if(jsPrsdAndRlsd(down)){
		downOk=true;
		rightOk=false;
		leftOk=false;
		centreOk=false;
	}
}

/*the joystick polling method*/
bool jsPrsdAndRlsd(position b) {
	bool result = false;
	uint32_t state;
	static uint32_t savedState[4] = {1,1,1,1};
        //initially all 1s: nothing pressed
	state = joystick[b].read();
  if (savedState[b]==0 && (state==1)){
		result = true;
	}
	savedState[b] = state;
	return result;
}
bool jsPrsd(position b) {
	bool result = false;
	uint32_t state;
	static uint32_t savedState[5] = {1,1,1,1};
        //initially all 1s: nothing pressed
	state = joystick[b].read();
  if (savedState[b]==0 && (state==0)){
		result = true;
	}
	savedState[b] = state;
	return result;
}
