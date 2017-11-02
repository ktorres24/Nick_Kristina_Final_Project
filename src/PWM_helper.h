#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "../inc/hw_ints.h"
#include "../inc/hw_memmap.h"
#include "../driverlib/pin_map.h"
#include "../inc/hw_timer.h"
#include "../inc/hw_gpio.h"
#include "../driverlib/sysctl.h"
#include "timer.h"
<<<<<<< HEAD:src/PWM.h
//#include "gpio.h"
=======
#include "gpio.h"
#include "hw_pwm.h"
#include "pwm.h"
>>>>>>> master:src/PWM_helper.h

#define time 56666


void PWM_setup(void);
void functions(void);
