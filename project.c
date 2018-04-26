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

//*****************************************************************************
//
// This code is first used to call the function that sets up GPIO and PWM. It then 
// goes into a continuous while loop. This while loop checks the conditions of the buttons.
// Depending on which button is pressed PWM signals of different duty cycles will be sent
// to each motor, this is called skid steering. This process is repeated for forwards, backwards, sharp right turn, and 
// sharp left turn. The duty cycles for each case are as follows:
//
//		Forward motion: left motor 90% right motor 90% 
//		Backward motion: left motor 90% right motor 90% 
//		Sharp right: left motor 90% right motor 0% 
//		Sharp left: left motor 0% right motor 90% 
// 
// In order to create forward vs. backwards (CW/CCW) AIN1/AIN2 and BIN1/BIN2 must be set high/low properly. They
// must be set as follows:
//
//		IN1 L  IN2 H CCW
//		IN1 H  IN2 L CW
//
//
//*****************************************************************************
int GPIO_LEFT;
int GPIO_FWD;
int GPIO_RIGHT;
int GPIO_BACK;


int main()
{
	Gpio_setup();
	PWM_setup();
		
	//Set Motor Driver input pins low to start 
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);						//set AI1 low to start (Left wheels)
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);						//Set AI2 low to start (Left wheels)
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);						//set BI1 low to start (Right wheels)
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);						//set BI2 low to start (Right wheels)
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_3, GPIO_PIN_3);		//Set Standby Pin for motor driver1
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_7, GPIO_PIN_7);		//Set Standby Pin for motor driver2
	
while (1)
	{
		
		

		GPIO_LEFT = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4);		//Read Left button (SW1 on board)
		GPIO_FWD = GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_6);		//Read Forward button	(Top MOM switch)
		GPIO_RIGHT = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_0);	//Read Right button (SW2 on board)
		GPIO_BACK = GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_7);		//Read Back button (bottom MOM switch)

	
		//FORWARD
		if((GPIO_FWD & GPIO_PIN_6) == 0)	//If Forward button is pressed
		{
		//SysCtlDelay( (SysCtlClockGet()/(3*1000)));	
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);	//set AI1 high 
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);					//set AI2 low   (AI1 high + AI2 low = FWD)
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);	//set BI1 high
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);					//set BI2 low 	(BI1 high + BI2 low = FWD)
			
		
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, GPIO_PIN_1);	//Turn LED on for debugging purposes
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 900); //send 90% duty PWM signal on right wheel
	  PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 900); //send 90% duty PWM signal on left wheel
		SysCtlDelay( (SysCtlClockGet()/(100)));	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);	//Turn LED off
			
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 	//set PWM signals low
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 0); 	//set PWM signals low

		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);	//set AI1 low 
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);	//set BI1 low 
		
		}
		

		//BACKWARDS
		if((GPIO_BACK & GPIO_PIN_7) == 0)                       //If Back button is pressed
		{		
			//SysCtlDelay( (SysCtlClockGet()/(3*1000)));	
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);            //set AI1 low
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);		//set AI2 high (AI1 low + AI2 high= BKWD)
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);						//set BI1 low 
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);		//set BI2 high (BI1 low + BI2 high=BKWD)
		
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	 //Turn LED on for debugging purposes	
			
			PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 900);            //send 90% duty PWM signal on right wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 900);						//send 90% duty PWM signal on left whee
			SysCtlDelay( (SysCtlClockGet()/(100)));	
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);					//Turn off LED	
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0);						//set PWM signals low 
			PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 0); 						//set PWM signals low
			
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);    			//SET AI2 high
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);					//SET BI2 high

			}
	
		
		//LEFT (90 turn)
		if((GPIO_LEFT & GPIO_PIN_4) == 0)
		{ 
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);	//set BI1 high
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);					//set BI2 low 	(BI1 high + BI2 low = FWD)
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);            //set AI1 low
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);		//set AI2 high (AI1 low + AI2 high= BKWD)
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 900);          //send 90% duty PWM signal on right wheel 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 900); 					//send 90% duty PWM signal on left wheel
		SysCtlDelay( (SysCtlClockGet()/(100)));	
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 0);						//set PWM signals low 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 					//set PWM signals low
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);					//SET BI1 high
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);					//SET BI2 high
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);  		//SET AI1 high
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);			//SET AI2 high
		}
		
		//RIGHT (90 turn)
		if((GPIO_RIGHT & GPIO_PIN_0)== 0)
		{
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);	//set AI1 high 
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);					//set AI2 low   (AI1 high + AI2 low = FWD)
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);						//set BI1 low 
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);		//set BI2 high (BI1 low + BI2 high=BKWD)	
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 900); 					//send 90% duty PWM signal on left wheel
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 900);          //send 90% duty PWM signal on right wheel 
		SysCtlDelay( (SysCtlClockGet()/(100)));	
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 0);						//set PWM signals low 
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 					//set PWM signals low
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);  		//SET AI1 high
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);			//SET AI2 high
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);					//SET BI1 high
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);					//SET BI2 high
		
		}
		
		}
		
	}

