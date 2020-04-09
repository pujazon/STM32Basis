#include "api_gpio.h"
#include "slib.h"
#include <stdio.h>

int OSMain(void) 
{
	SecVal ret;	
	
	//Turn on STM32F407G-DISC1 Orange led
	ret = AGPIO_Turn_On_Orange_Led();	

	if(ret != SecTRUE) {
		Die();
	}
	return 0;
}
