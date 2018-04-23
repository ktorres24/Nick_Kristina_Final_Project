 #include "PWM_helper.h"

 int Period, Duty_Cycle, value;																														 //Initializes variables
 

 void PWM_setup(void)
 {
	 
    //Set the clock
   SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC |   SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_8);
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); //changed enabled module 1 of pwm
	
  //Set GPIO to work with PWM
		
		GPIOPinConfigure(GPIO_PD0_M1PWM0); //configure right motor pwm
		GPIOPinConfigure(GPIO_PA6_M1PWM2); //configures left motor


		GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0); //define pin type as PWM for PD0 and PD1
		GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6); //define pin type as PWM for PA6 and PA7
	
    PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); //Configure GEN1	 
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); //Configure GEN0
                    
    //Set the Period (expressed in clock ticks)
		PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, 1000); //2Khz frequency
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, 1000); //2Khz frequency
		
		PWMGenEnable(PWM1_BASE, PWM_GEN_1); //Enables GEN1
    PWMGenEnable(PWM1_BASE, PWM_GEN_0); //Enables GEN0
  
    PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT |PWM_OUT_2_BIT, true);		// Turn on the Output pins
		
	return;         																																				 //Return to project.c

 }

 