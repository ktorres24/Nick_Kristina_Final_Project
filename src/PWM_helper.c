 #include "PWM_helper.h"

 int Period, Duty_Cycle, value;																														 //Initializes variables
 

 void PWM_setup(void)
 {
	 
   SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); //changed set the clock

   SysCtlPWMClockSet(SYSCTL_PWMDIV_64); //changed set the PWM clock with the system clock
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); //changed enabled module 1 of pwm to work with leds (may need to change)
	
  //Set GPIO to work with PWM
  GPIOPinConfigure(GPIO_PF1_M1PWM5);  //CHANGED                                                     //Configures PF1 with TIMER 0 B
	GPIOPinConfigure(GPIO_PF2_M1PWM6);  //CHANGED                                                     //Configures PF2 with TIMER 1 A
  GPIOPinConfigure(GPIO_PF3_M1PWM7);  //CHANGED 
	GPIOPinConfigure(GPIO_PA6_M1PWM2);
	GPIOPinConfigure(GPIO_PA7_M1PWM3);
	GPIOPinConfigure(GPIO_PD0_M1PWM0);
	GPIOPinConfigure(GPIO_PD1_M1PWM1);
  GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3); //CHANGED
	GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1);
	GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6|GPIO_PIN_7);
	
    PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); // CHANGED configures gen modes
    PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); // CHANGED configures gen modes
 
	 //Define Period and Duty_Cycle
  uint32_t Period;
  Period = PWMClockGet()/100000;  //changed                                                //Gets the PWM clock rate and devides it by 100kHz. Period=800Hz
  Duty_Cycle = Period/2;                                                                   //Sets Duty_Cycle to 400Hz

    //Set the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, Period); //changed
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, Period); //changed

    //Set PWM duty-50% (Period /2)
 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, Duty_Cycle); //changed   
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, Duty_Cycle); //changed
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, Duty_Cycle); //changed
	  PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, Duty_Cycle); //changed
		
    // Enable the PWM generator
    PWMGenEnable(PWM1_BASE, PWM_GEN_2); //enables gen 2
    PWMGenEnable(PWM1_BASE, PWM_GEN_3); //enables gen 3
		
		// Turn on the Output pins
    PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT, true);
		
	return;         																																				 //Return to project.c

 }

  void functions()
	{
	  int value= GPIOPinRead(GPIO_PORTD_BASE,GPIO_PIN_7);
    if( (value & GPIO_PIN_7)==0)                                                                //Repeat this sequence of light dimming 10 times
	 {
		 //Blue brightness goes up
		for(int i=Period-2; i > 0; i--)                                                       //This for loop will decrement the duty cycle starting
		 {          																																					//from Period-2 until the duty cycle is 0 and the BLUE LED
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, i);                                             //will become progressively brighter.
			SysCtlDelay(time);
	   } 
	 }

	  int value1= GPIOPinRead(GPIO_PORTD_BASE,GPIO_PIN_6);
    if( (value1 & GPIO_PIN_6)==0) 
    { 
		//Blue brightness goes down
    for(int i=1; i < Period-1; i++)																											  //This for loop will increment the duty cycle starting
		 {         																																						//from 1 until the duty cycle is equal to the period 
      PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6, i);                                             //and the BLUE LED will dim until its off.
      SysCtlDelay(time);
		 }  
		}
		
		int value2= GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_5);
    if( (value2 & GPIO_PIN_5)==0)
		{
		//Red brightness goes up
		for(int i=Period-2; i > 0; i--)																												//This for loop will decrement the duty cycle starting
		 {           																																					//from Period-2 until the duty cycle is 0 and the RED LED
			PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, i);                                             //will become progressively brighter.                        
			SysCtlDelay(time);
		 }  
		}
			
		int value3= GPIOPinRead(GPIO_PORTD_BASE, GPIO_PIN_4);
    if( (value3 & GPIO_PIN_4)==0)
		{
		//Red brightness goes down              
    for(int i=1; i < Period-1; i++)                                                       //This for loop will increment the duty cycle starting
		 {																																										//from 1 until the duty cycle is equal to the period 
      PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5, i);                                      //and the RED LED will dim until its off.	
      SysCtlDelay(time);
		 }
	  }

	  return;																																								//Return to project.c
  }