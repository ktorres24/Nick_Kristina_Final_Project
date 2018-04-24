 #include "PWM_helper.h"

 int Period, Duty_Cycle, value;																														 //Initializes variables
 

 void PWM_setup(void)
 {
	 
    //Set the clock
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

   //Configure PWM Clock to match system
   SysCtlPWMClockSet(SYSCTL_PWMDIV_64);
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); //changed enabled module 1 of pwm
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); //changed enabled module 0 of pwm
  //Set GPIO to work with PWM
		
		GPIOPinConfigure(GPIO_PD0_M0PWM6); //configure right motor pwm
		GPIOPinConfigure(GPIO_PA6_M1PWM2); //configures left motor


		GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0); //define pin type as PWM for PD0 and PD1
		GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6); //define pin type as PWM for PA6 and PA7
	
    PWMGenConfigure(PWM0_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); //Configure GEN1	 
    PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); //Configure GEN0
                    
    //Set the Period (expressed in clock ticks)
		PWMGenPeriodSet(PWM0_BASE, PWM_GEN_3, 1000); //2Khz frequency
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, 1000); //2Khz frequency
		
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6, 500); 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 500);
   
		PWMGenEnable(PWM0_BASE, PWM_GEN_3); //Enables GEN1
    PWMGenEnable(PWM1_BASE, PWM_GEN_1); //Enables GEN0
  
    PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT, true);		// Turn on the Output pins
		PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, true);
	return;         																																				 //Return to project.c

 }

 