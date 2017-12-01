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
	PWM_setup();
	
	//need to set up some sort of delay/checking period after a button is pressed so that our code can check and see 
	//if another button is also pressed (buttons won't be pressed "simultaneously", right?)
	
	//psuedo code for now
	while (1)
	{

		GPIO_LEFT = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4);
		GPIO_FWD = GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_6);
		GPIO_RIGHT = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);
		GPIO_BACK = GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_7);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_3, GPIO_PIN_3);	
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_7, GPIO_PIN_7);	
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);
		//FORWARD
		if((GPIO_FWD & GPIO_PIN_6) == 0)
		{
		// FORWARD RIGHT TURN
		if((GPIO_RIGHT & GPIO_PIN_0)== 0)
		{
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, GPIO_PIN_1);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 500);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 500); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 250); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 250); 	
//MIGHT NEED A DELAY HERE?			
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0); 	
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);
	   
		}
		
		//FORWARD LEFT TURN
		else if ( (GPIO_LEFT & GPIO_PIN_4)==0)
		{
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, GPIO_PIN_1);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 500);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 500); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 250); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 250); 	
//MIGHT NEED A DELAY HERE?	
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);
		}
		//FORWARD
		else 
		{
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, GPIO_PIN_1);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 500);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 500); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 500); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 500); 	
//MIGHT NEED A DELAY HERE?		
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);

		}
		}
			//BACKWARDS
		if((GPIO_BACK & GPIO_PIN_7) == 0)
		{		
		//BACK & RIGHT
		if((GPIO_RIGHT & GPIO_PIN_0)==0)
		{
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);		
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 500);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 500); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 250); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 250); 	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, GPIO_PIN_2);
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);	
			
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);	
//MIGHT NEED A DELAY HERE?		
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);
			//send pwm signal, (Negative Left side speed > Negative Right side speed)
		}
		//BACK & LEFT
		else if((GPIO_LEFT & GPIO_PIN_4) ==0)
		{
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);		
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 500);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 500); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 250); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 250); 
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, GPIO_PIN_2);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);	
//MIGHT NEED A DELAY HERE?		
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 	
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);	
			//send pwm signal, (Negative Right side speed > Negative Left side speed)
		}
		//BACKWARDS
		else
		{
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);	
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 500);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 500); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 500); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 500); 	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, GPIO_PIN_2);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);	
//MIGHT NEED A DELAY HERE?		
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0); 
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);	
			//send pwm signal
		}
		}

		
		//LEFT (0 turn)
		if((GPIO_LEFT & GPIO_PIN_4) == 0)
		{ 
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);	
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 500); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 500); 	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);	
//MIGHT NEED A DELAY HERE?		
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);

		}
		
		//RIGHT (0 turn)
		if((GPIO_RIGHT & GPIO_PIN_0)== 0)
		{
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);	
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 500); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 500); 
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);	
//MIGHT NEED A DELAY HERE?		
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0);
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_2, 0);	
		}
		
	}

}
