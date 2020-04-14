#include "./DrvGPIO/api_gpio.h"
#include "./SLib/slib.h"
#include <stdio.h>

int OSMain(void) 
{
	uint8_t ret, isButtonPushed = 0;	
	
	//Turn on STM32F407G-DISC1 Orange led
	ret = STM32F407G_DISC_1_OrangeLedOn();	
	
	//If NUCLEO_
	//ret = NUCLEO_F446RE_GreenLedOn();
	if(ret != 0x00) {
		Die();
	}
	
	//Input
	STM32F407G_DISC_1_UserButtonSetup();
	
	while(!isButtonPushed) {		
		isButtonPushed = STM32F407G_DISC_1_IsUserButtonPushed();
	}		
	
	return 0;
}
