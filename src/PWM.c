 #include "PWM.h"

 int Period, Duty_Cycle, value;																														 //Initializes variables
 

 void PWM_setup(void)
 {
	
  //Set GPIO to work with timers
  GPIOPinConfigure(GPIO_PF1_T0CCP1);                                                       //Configures PF1 with TIMER 0 B
	GPIOPinConfigure(GPIO_PF2_T1CCP0);                                                       //Configures PF2 with TIMER 1 A
  GPIOPinConfigure(GPIO_PF3_T1CCP1);                                                       //Configures PF3 with TIMER 1 B
  GPIOPinTypeTimer(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);                     //Configures pins PF1,PF2, and PF3 for use by the timer peripheral
	 
  //Define Period and Duty_Cycle
  Period = SysCtlClockGet()/100000;                                                        //Gets the processor clock rate and devides it by 100kHz. Period=800Hz
  Duty_Cycle = Period/2;                                                                   //Sets Duty_Cycle to 400Hz

  ///Setup TIMER 0 B and TIMER 1 A & B
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);                                            //Enables the TIMER 0 peripheral
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);                                            //Enables the timer 1 peripheral

  TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_B_PWM);                       //Configures TIMER 0 B into PWM mode
  TimerLoadSet(TIMER0_BASE, TIMER_B, Period -1);                                           //Sets the value that TIMER 0 B will load to when it hits 0
  TimerMatchSet(TIMER0_BASE, TIMER_B, Duty_Cycle);                                         //Sets the value that TIMER 0 B will be low
  TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PWM|TIMER_CFG_B_PWM);       //Configures TIMER 1 A & B into PWM mode  
  TimerLoadSet(TIMER1_BASE, TIMER_A, Period -1);                                           //Sets the value that TIMER 1 A will load to when it hits 0
  TimerLoadSet(TIMER1_BASE, TIMER_B, Period -1);                                					 //Sets the value that TIMER 1 B will load to when it hits 0
  TimerMatchSet(TIMER1_BASE, TIMER_A, Duty_Cycle);                                         //Sets the value that TIMER 1 A will be low
  TimerMatchSet(TIMER1_BASE, TIMER_B, Duty_Cycle);  																			 //Sets the value that TIMER 1 B will be low
	
	//Turn on timers
  TimerEnable(TIMER0_BASE, TIMER_B);                																			 //Enables TIMER 0 B for use
  TimerEnable(TIMER1_BASE, TIMER_A|TIMER_B);                             									 //Enables TIMER 1 A & B for use

	return;         																																				 //Return to project.c

 }

  void PWM_example()
	{
	 
	for (int x=0; x<10; x++)                                                                //Repeat this sequence of light dimming 10 times
	 {
		 //Blue brightness goes up
		for(int i=Period-2; i > 0; i--)                                                       //This for loop will decrement the duty cycle starting
		 {          																																					//from Period-2 until the duty cycle is 0 and the BLUE LED
			TimerMatchSet(TIMER1_BASE, TIMER_A, i);                                             //will become progressively brighter.
			SysCtlDelay(time);
	   }  
      
		//Blue brightness goes down
    for(int i=1; i < Period-1; i++)																											  //This for loop will increment the duty cycle starting
		 {         																																						//from 1 until the duty cycle is equal to the period 
      TimerMatchSet(TIMER1_BASE, TIMER_A, i);                                             //and the BLUE LED will dim until its off.
      SysCtlDelay(time);
		 }  
		
		//Red brightness goes up
		for(int i=Period-2; i > 0; i--)																												//This for loop will decrement the duty cycle starting
		 {           																																					//from Period-2 until the duty cycle is 0 and the RED LED
			TimerMatchSet(TIMER0_BASE, TIMER_B, i);                                             //will become progressively brighter.                        
			SysCtlDelay(time);
		 }  
			
		//Red brightness goes down              
    for(int i=1; i < Period-1; i++)                                                       //This for loop will increment the duty cycle starting
		 {																																										//from 1 until the duty cycle is equal to the period 
      TimerMatchSet(TIMER0_BASE, TIMER_B, i); 																						//and the RED LED will dim until its off.	
      SysCtlDelay(time);
		 } 

	  //Green brightness goes up         
    for(int i=Period-2; i > 0; i--)																												//This for loop will decrement the duty cycle starting
		 {																																										//from Period-2 until the duty cycle is 0 and the GREEN LED
      TimerMatchSet(TIMER1_BASE, TIMER_B, i); 																						//will become progressively brighter. 
      SysCtlDelay(time);
		 }  
 
	  //Green brightness goes down              
    for(int i=1; i < Period-1; i++)                                                       //This for loop will increment the duty cycle starting
		 {																																										//from 1 until the duty cycle is equal to the period																									
      TimerMatchSet(TIMER1_BASE, TIMER_B, i);																							//and the GREEN LED will dim until its off. 			
      SysCtlDelay(time);
		 }
		}		
		
	  return;																																								//Return to project.c
  }
