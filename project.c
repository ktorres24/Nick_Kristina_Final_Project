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

		//FORWARD RIGHT TURN
		if((GPIO_FWD & GPIO_PIN_6) == 0)	//If Forward button is pressed
		{

			if((GPIO_RIGHT & GPIO_PIN_0)== 0)	//If Forward and Right is pressed
			{
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);	//set AI1 high 
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);					//set AI2 low   (AI1 high + AI2 low = FWD)
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);	//set BI1 high
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);					//set BI2 low 	(BI1 high + BI2 low = FWD)
				
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, GPIO_PIN_1);	//Turn LED on for debugging purposes
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	//Turn LED on for debugging purposes
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);	//Turn LED off
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);	//Turn LED off
				
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 500); //send 50% duty PWM signal on front right wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 500); //send 50% duty PWM signal on back right wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 900); //send 90% duty PWM signal on front left wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 900); //send 90% duty PWM signal on back left wheel
			 
				
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 	//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 	//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 	//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0); 	//set PWM signals low
				
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);	//set AI1 low 
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);	//set BI1 low
			

			}
		}
		
		//FORWARD LEFT TURN
		if((GPIO_FWD & GPIO_PIN_6) == 0)	//If Forward button is pressed
		{
			if ( (GPIO_LEFT & GPIO_PIN_4)==0)	//If Forward and Left is pressed
			{
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);	//set AI1 high 
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);					//set AI2 low   (AI1 high + AI2 low = FWD)
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);	//set BI1 high
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);					//set BI2 low 	(BI1 high + BI2 low = FWD)
				
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, GPIO_PIN_1);	//Turn LED on for debugging purposes
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	//Turn LED on for debugging purposes
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);	//Turn LED off
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);	//Turn LED off
				
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 900); //send 90% duty PWM signal on front right wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 900); //send 90% duty PWM signal on back right wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 500); //send 50% duty PWM signal on front left wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 500); //send 50% duty PWM signal on back left wheel
			

				
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 	//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 	//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 	//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0); 	//set PWM signals low
			
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);	//set AI1 low 
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);	//set BI1 low 
			}
		}
	


		//FORWARD
		if((GPIO_FWD & GPIO_PIN_6) == 0)	//If Forward button is pressed
		{
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);	//set AI1 high 
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);					//set AI2 low   (AI1 high + AI2 low = FWD)
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);	//set BI1 high
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);					//set BI2 low 	(BI1 high + BI2 low = FWD)
			
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, GPIO_PIN_1);	//Turn LED on for debugging purposes
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);	//Turn LED off
			
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 900); //send 90% duty PWM signal on front right wheel
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 900); //send 90% duty PWM signal on back right wheel
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 900); //send 90% duty PWM signal on front left wheel
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 900); //send 90% duty PWM signal on back left wheel
		

			
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 	//set PWM signals low
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 	//set PWM signals low
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 	//set PWM signals low
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0); 	//set PWM signals low

		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);	//set AI1 low 
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);	//set BI1 low 
		
		}
		
		
//BACK & RIGHT
		if((GPIO_BACK & GPIO_PIN_7) == 0)                       //If Back button is pressed
		{		
	
			if((GPIO_RIGHT & GPIO_PIN_0)==0)												//If Back and Right buttons are pressed
			{
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);            //set AI1 low
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);		//set AI2 high (AI1 low + AI2 high= BKWD)
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);						//set BI1 low 
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);		//set BI2 high (BI1 low + BI2 high=BKWD)
			
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 500);            //send 50% duty PWM signal on front right wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 500); 	          //send 50% duty PWM signal on back right wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 900);						//send 90% duty PWM signal on front left wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 900); 						//send 90% duty PWM signal on back left wheel

			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	 //Turn LED on for debugging purposes	
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, GPIO_PIN_2);  //Turn LED on for debugging purposes
				
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);		//Turn off LED	
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);	  //Turn off LED
				

				
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0);						//set PWM signals low 
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 						//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 						//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0);						//set PWM signals low
			
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);    			//SET AI2 low
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);					//SET BI2 low

			}
		}
		
		//BACK & LEFT
		if((GPIO_BACK & GPIO_PIN_7) == 0)                       //If Back button is pressed
		{		

			if((GPIO_LEFT & GPIO_PIN_4)==0)												//If Back and LEFT buttons are pressed
			{
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);            //set AI1 low
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);		//set AI2 high (AI1 low + AI2 high= BKWD)
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);						//set BI1 low 
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);		//set BI2 high (BI1 low + BI2 high=BKWD)
			
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 900);            //send 90% duty PWM signal on front right wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 900); 	          //send 90% duty PWM signal on back right wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 500);						//send 50% duty PWM signal on front left wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 500); 						//send 50% duty PWM signal on back left wheel

			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	 //Turn LED on for debugging purposes	
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, GPIO_PIN_2);  //Turn LED on for debugging purposes
				
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);		//Turn off LED	
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_2, 0);	  //Turn off LED
				
	
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0);						//set PWM signals low 
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 						//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 						//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0);						//set PWM signals low

			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);    			//SET AI2 low
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);					//SET BI2 low
				
				//send pwm signal, (Negative Left side speed > Negative Right side speed)
			}
		}


		//BACKWARDS
		if((GPIO_BACK & GPIO_PIN_7) == 0)                       //If Back button is pressed
		{		

			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);            //set AI1 low
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);		//set AI2 high (AI1 low + AI2 high= BKWD)
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, 0);						//set BI1 low 
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);		//set BI2 high (BI1 low + BI2 high=BKWD)
			
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 900);            //send 90% duty PWM signal on front right wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 900); 	          //send 90% duty PWM signal on back right wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 900);						//send 90% duty PWM signal on front left wheel
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 900); 						//send 90% duty PWM signal on back left wheel

			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	 //Turn LED on for debugging purposes	

				
			GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);		//Turn off LED	

				

			
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0);						//set PWM signals low 
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0); 						//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0); 						//set PWM signals low
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0);						//set PWM signals low
			
			GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);    			//SET AI2 high
			GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);					//SET BI2 high

			}
	

		
		//LEFT (0 turn)
		if((GPIO_LEFT & GPIO_PIN_4) == 0)
		{ 
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);	//set BI1 high
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, 0);					//set BI2 low 	(BI1 high + BI2 low = FWD)
			
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 900);          //send 90% duty PWM signal on front right wheel 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 900); 					//send 90% duty PWM signal on back right wheel
			
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	//Turn LED on for debugging purposes	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);	//Turn of LED
		

		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 0);						//set PWM signals low 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 0);						//set PWM signals low
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_5, GPIO_PIN_5);					//SET BI1 high
		GPIOPinWrite(GPIO_PORTC_BASE,GPIO_PIN_6, GPIO_PIN_6);					//SET BI2 high
		}
		
		//RIGHT (0 turn)
		if((GPIO_RIGHT & GPIO_PIN_0)== 0)
		{
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);	//set AI1 high 
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);					//set AI2 low   (AI1 high + AI2 low = FWD)
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 900); 					//send 90% duty PWM signal on front left wheel
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 900); 					//send 90% duty PWM signal on back left wheel
			
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, GPIO_PIN_3);	
		GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3, 0);	
			
		PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 0); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 0);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, GPIO_PIN_1);
		GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, GPIO_PIN_2);	
		
		}
		
		}
		
	}
