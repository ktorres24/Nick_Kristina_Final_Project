#include <stdio.h>
#include <stdbool.h>
#include "main.h"

int x = 1;
int GPIO_LEFT;
int GPIO_FWD;
int GPIO_RIGHT;
int GPIO_BACK;

int main();
{
	Gpio_setup();
	PWM_setup();
	
	//need to set up some sort of delay/checking period after a button is pressed so that our code can check and see 
	//if another button is also pressed (buttons won't be pressed "simultaneously", right?)
	
	//psuedo code for now
	while x == 1
	{
		//FORWARD
		if(GPIO_FWD == 1)
		{ 
		// FORWARD RIGHT TURN
		if(GPIO_FWD == 1 & GPIO_RIGHT ==1)
		{
			//send pwm signal, (Left side speed > Right side speed)
		}
		//FORWARD RIGHT TURN
		else if ( (GPIO_FWD == 1 & GPIO_LEFT ==1)
		{
			//send pwm signal, (Right side speed > Left side speed)
		}
		//FORWARD
		else 
		{
			//send pwm signal
		}
		}
		
		//BACKWARDS
		if(GPIO_BACK == 1)
		{		
		//BACK & RIGHT
		if(GPIO_BACK == 1 & GPIO_RIGHT ==1)
		{
			//send pwm signal, (Negative Left side speed > Negative Right side speed)
		}
		//BACK & LEFT
		else if(GPIO_BACK == 1 & GPIO_LEFT ==1)
		{
			//send pwm signal, (Negative Right side speed > Negative Left side speed)
		}
		//BACKWARDS
		else
		{
			//send pwm signal
		}
		}
		
		//LEFT (0 turn)
		if(GPIO_LEFT == 1)
		{
			//send pwm signal
		}
		
		//RIGHT (0 turn)
		if(GPIO_RIGHT == 1)
		{
			//send pwm signal
		}
	
		
	
		
	}
}