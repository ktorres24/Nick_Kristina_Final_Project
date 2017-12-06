#include "GPIO_helper.h"

//This function sets up GPIO pins:
//	Inputs:  SW1 (left), SW2 (Right), PD6 (Forward), PD7 (Backwards)
//  Outputs: PD0 (front right motor), PD1 (back right motor), PA6 (front left motor), PA7 (back left motor), PD1 (red led indicates forward movement),
//	PD2 (blue led indicates backwards movement), PD3 (green led indicates left and right movement
//	The LEDs are simply used to show that the proper loops are being taken in the main function. 

void Gpio_setup()
	{
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);  // Enables the use of PORTF
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);  // Enables the use of PORTA
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);  // Enables the use of PORTD
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);  // Enables the use of PORTC
			SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);  // Enables the use of PORTE
		
			GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3); // Defines the RGB Leds as outputs
			GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3); // Defines 3 motor driver inputs for direction
		  GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7); // Defines 3 motor driver inputs for direction 
			GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE, GPIO_PIN_0|GPIO_PIN_1);  // Defines outputs for the 2 right motors 
			GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_6|GPIO_PIN_7);  // Defines outputs for the 2 left motors
			GPIOPinTypeGPIOInput (GPIO_PORTD_BASE, GPIO_PIN_6|GPIO_PIN_7);  // Defines two pins as inputs to be used for the two MOM switches
		  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4);   // Defines 2 on board switches as inputes


//TM4C123 Devices Port-C

HWREG(GPIO_PORTC_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;                   

HWREG(GPIO_PORTC_BASE+GPIO_O_CR) |= (GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);   //unlocks PC 0,1,2,3 for GPIO use
		
//TM4C123 Devices Port-D

HWREG(GPIO_PORTD_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;

HWREG(GPIO_PORTD_BASE+GPIO_O_CR) |= GPIO_PIN_7;																			//unlocks PD7 for GPIO use        																	                   

//TM4C123 Devices Port-F

HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;

HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= GPIO_PIN_0;																			//unlocks PF0 for GPIO use
		
		
			GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_DIR_MODE_IN);													//Configures on board switches
			GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4|GPIO_PIN_0,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

		
			GPIOPadConfigSet(GPIO_PORTD_BASE,GPIO_PIN_6|GPIO_PIN_7,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU); //Configures MOM switches
			GPIODirModeSet(GPIO_PORTD_BASE, GPIO_PIN_6|GPIO_PIN_7, GPIO_DIR_MODE_IN);												 
																																																		   

			
	} 
