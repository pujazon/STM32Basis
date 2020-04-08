#include "gpio.h"
#include "slib.h"
#include <stdio.h>

int OSMain(void) 
{
	SecVal ret;
	
	GPIOx_MODER_set(GPIO_D,13,GPIOx_MODER_OUTPUT);
	
	return ret;
}
