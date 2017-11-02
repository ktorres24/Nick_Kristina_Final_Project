#include "project.h"
#include <stdio.h>
#include <stdint.h>
//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************

#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


int x = 1;
int GPIO_LEFT;
int GPIO_FWD;
int GPIO_RIGHT;
int GPIO_BACK;

int main()
{
	Gpio_setup();
	//PWM_setup();
	
	//need to set up some sort of delay/checking period after a button is pressed so that our code can check and see 
	//if another button is also pressed (buttons won't be pressed "simultaneously", right?)
	
	//psuedo code for now
	while (x == 1)
	{
		GPIO_LEFT = GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_6);
		GPIO_FWD = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4);
		GPIO_RIGHT = GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_7);
		GPIO_BACK = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);
		
		if(GPIO_FWD == 1)
		{ 
		// FORWARD RIGHT TURN
		if(GPIO_FWD == 1 & GPIO_RIGHT ==1 )
		{
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 1);
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 1);
			//send pwm signal, (Left side speed > Right side speed)
		}
		//FORWARD LEFT TURN
		else if (GPIO_FWD == 1 & GPIO_LEFT ==1)
		{
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 1);
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 1);
			//send pwm signal, (Right side speed > Left side speed)
		}
		//FORWARD
		else 
		{
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 1);
			//send pwm signal
		}
		}
		
		//BACKWARDS
		if(GPIO_BACK == 1)
		{		
		//BACK & RIGHT
		if(GPIO_BACK == 1 & GPIO_RIGHT ==1)
		{
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 1);
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 1);
			//send pwm signal, (Negative Left side speed > Negative Right side speed)
		}
		//BACK & LEFT
		else if(GPIO_BACK == 1 & GPIO_LEFT ==1)
		{
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 1);
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 1);
			//send pwm signal, (Negative Right side speed > Negative Left side speed)
		}
		//BACKWARDS
		else
		{
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 1);
			//send pwm signal
		}
		}
		
		//LEFT (0 turn)
		if(GPIO_LEFT == 1)
		{
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 1);
			//send pwm signal
		}
		
		//RIGHT (0 turn)
		if(GPIO_RIGHT == 1)
		{
			GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 1);
			//send pwm signal
		}
	
		
	
		
	}
}
