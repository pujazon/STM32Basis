#include "./DrvGPIO/api_gpio.h"
#include "./SLib/slib.h"
#include "./ModesStates/state_snippet.h"
#include <stdio.h>
#include <stdint.h>

int OSMain(void) 
{
	uint8_t ret, isButtonPushed = 0;	
	
	//GPIO Outputs 
	STM32F446_GPIO_Setup(GPIO_D);
	ret = STM32F407G_DISC_1_BlueLedOn();	
	ret = STM32F407G_DISC_1_RedLedOn();	
	
	while(1);
	/*
	//If NUCLEO_
	//ret = NUCLEO_F446RE_GreenLedOn();
	if(ret != 0x00) {
		Die();
	}
	
	//Input
	STM32F407G_DISC_1_UserButtonSetup();	
	isButtonPushed = STM32F407G_DISC_1_IsUserButtonPushed();
	while(isButtonPushed) {		
		isButtonPushed = STM32F407G_DISC_1_IsUserButtonPushed();
	}		
	
	//Chapter 7. ARM Porcessor modes and states.
	state_snippet();
	*/
	return 0;
}
