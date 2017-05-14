/* Asteroids
    Sample solution for assignment
    Semester 2 -- Small Embedded Systems
    Dr Alun Moon
*/

/* C libraries */
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

/* hardware platform libraries */
#include <display.h>
#include <mbed.h>

/* Main game elements */
#include "model.h"
#include "view.h"
#include "controller.h"

/* Game state */
int   score;//thow long the game has been going on
int   lives;// howq many lives the ship has
bool started=false;//if the game has started or not

float Dt = 0.01f;//TIME FOR PHYSICS

Ticker model, view, controller;//the model,view and controller ticker


/* this is where yo0u 
intialise the start of the game and make it all smooth*/
int main()
{
    initialise_heap();//intialises the linked list
    init_DBuffer();// intialises the double buffering to make it smooth
	   view.attach( draw, 0.025);//view gets constantly called to make sure it looks ok
	 controller.attach( controls, 0.1);//controller gets constantly viewed every second to make sure you haven't pressed a button
	
	/*if started== true then
	you will call for model to start t=doing all the action and makes lives = to 5*/
    if(started==true){
    model.attach( physics, Dt);
    
    lives = 100;
		}
		
		/*if lives is less than or equal to 0 then the model gets detaached so it doesn't interfere 
		with anyother pages*/
	
	if(lives<=0){
		model.detach();
		//if joystick centre is pressed the model start again
	if(joystickcentre()==true){
		 model.attach( physics, Dt);
	}
}
	}
