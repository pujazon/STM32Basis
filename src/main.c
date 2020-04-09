#include "gpio.h"
#include "slib.h"
#include <stdio.h>

int OSMain(void) 
{
	SecVal ret;
	
	//Check that different GPIO are well mapped
	GPIOx_MODER_set(GPIO_A,13,GPIOx_MODER_OUTPUT);
	GPIOx_MODER_set(GPIO_B,13,GPIOx_MODER_OUTPUT);
	GPIOx_MODER_set(GPIO_C,13,GPIOx_MODER_OUTPUT);
	
	return ret;
}
