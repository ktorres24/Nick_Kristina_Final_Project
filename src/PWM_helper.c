 #include "PWM_helper.h"

 int Period, Duty_Cycle, value;																														 //Initializes variables
 

 void PWM_setup(void)
 {
	 
   SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ); //Sets clock frequency at 80Mhz

   SysCtlPWMClockSet(SYSCTL_PWMDIV_1); //set the PWM clock with the system clock
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); //changed enabled module 1 of pwm
	
  //Set GPIO to work with PWM
		
		GPIOPinConfigure(GPIO_PD0_M1PWM0); //configure front right motor pwm
		GPIOPinConfigure(GPIO_PD1_M1PWM1); //configure back right motor pwm
		GPIOPinConfigure(GPIO_PA6_M1PWM2); //configure front left
		GPIOPinConfigure(GPIO_PA7_M1PWM3); //configure back left

		GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1); //define pin type as PWM for PD0 and PD1
		GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6|GPIO_PIN_7); //define pin type as PWM for PA6 and PA7
	
    PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); //Configure GEN1	 
    PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); //Configure GEN0

 
                                                              

    //Set the Period (expressed in clock ticks)
		PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, 1000); //80Khz frequency
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, 1000); //80Khz frequency


    //Set PWM duty-50% (Period /2)
 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1, 500); //Set pulse to 50% 
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2, 500); //Set pulse to 50%
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3, 500); //Set pulse to 50%
	  PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0, 500); //Set pulse to 50% 
		
		PWMGenEnable(PWM1_BASE, PWM_GEN_1); //Enables GEN1
    PWMGenEnable(PWM1_BASE, PWM_GEN_0); //Enables GEN0
  
    PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT, true);		// Turn on the Output pins
		
	return;         																																				 //Return to project.c

 }

 