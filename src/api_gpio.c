#include "api_gpio.h"

SecVal AGPIO_Turn_On_Orange_Led() {

	//Todo: Error handling
	
	GPIOx_MODER_set(GPIO_D,13,GPIOx_MODER_OUTPUT);
	GPIOx_OTYPER_set(GPIO_D,13,GPIOx_OTYPER_PUSH_PULL);
	GPIOx_OSPEEDR_set(GPIO_D,13,GPIOx_OSPEEDR_MEDIUM);
	GPIOx_PUPDR_set(GPIO_D,13,GPIOx_PUPDR_NO_PULL);
	GPIOx_ODR_set(GPIO_D,13,GPIO_HIGH);
	
	return SecTRUE;
}

