 #include "PWM_helper.h"

 int Period, Duty_Cycle, value;																														 //Initializes variables
 

 void PWM_setup(void)
 {
	 
   SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); //changed set the clock

   SysCtlPWMClockSet(SYSCTL_PWMDIV_1); //changed set the PWM clock with the system clock
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); //changed enabled module 1 of pwm to work with leds (may need to change)
	
  //Set GPIO to work with PWM
		
	GPIOPinConfigure(GPIO_PD0_M1PWM0);
	GPIOPinConfigure(GPIO_PD1_M1PWM1); 
	GPIOPinConfigure(GPIO_PA6_M1PWM2);
	GPIOPinConfigure(GPIO_PA7_M1PWM3);

	GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1);
	GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6|GPIO_PIN_7);
	
    PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);	 
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); // CHANGED configures gen modes

 
                                                               //Sets Duty_Cycle to 400Hz

    //Set the Period (expressed in clock ticks)
		PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, 5000); //changed
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, 5000); //changed


    //Set PWM duty-50% (Period /2)
 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 500);   
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 500); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 500); 
	  PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 500); 
		

		
    // Enable the PWM generator
		PWMGenEnable(PWM1_BASE, PWM_GEN_1); //enables gen 2
    PWMGenEnable(PWM1_BASE, PWM_GEN_0); //enables gen 2
  
		
		// Turn on the Output pins
    PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT, true);
		
	return;         																																				 //Return to project.c

 }

 