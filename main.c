#include "main.h"	


int main (void)
{
GPIO_setup();
PWM_setup();
	
while (1)
{	
functions();
}

}