#include "./api_gpio.h"

uint8_t STM32F446_LedOn(GPIOx *GPIO, uint8_t pin)
{
  GPIOx_MODER_set(GPIO,pin,GPIOx_MODER_OUTPUT);
	GPIOx_OTYPER_set(GPIO,pin,GPIOx_OTYPER_PUSH_PULL);
	GPIOx_OSPEEDR_set(GPIO,pin,GPIOx_OSPEEDR_MEDIUM);
	GPIOx_PUPDR_set(GPIO,pin,GPIOx_PUPDR_NO_PULL);
	GPIOx_ODR_set(GPIO,pin,GPIO_HIGH);
	
	return 0;
}

uint8_t STM32F446_ButtonSetup(GPIOx *GPIO, uint8_t pin)
{
  GPIOx_MODER_set(GPIO,pin,GPIOx_MODER_INPUT);
	//TODO: Must be clarified why doesnt matter value (x)
	//GPIOx_OTYPER_set(GPIO,pin,GPIOx_OTYPER_PUSH_PULL);
	//GPIOx_OSPEEDR_set(GPIO,pin,GPIOx_OSPEEDR_MEDIUM);
	GPIOx_PUPDR_set(GPIO,pin,GPIOx_PUPDR_PULL_DOWN);
	
	return 0;
}

uint8_t STM32F407G_DISC_1_OrangeLedOn()
{
	return STM32F446_LedOn(GPIO_D, DISC_1_ORANGE_PIN);
}

uint8_t STM32F407G_DISC_1_GreenLedOn()
{
	return STM32F446_LedOn(GPIO_D, DISC_1_GREEN_PIN);
}

uint8_t STM32F407G_DISC_1_RedLedOn()
{
	return STM32F446_LedOn(GPIO_D, DISC_1_RED_PIN);
}

uint8_t STM32F407G_DISC_1_BlueLedOn()
{
	return STM32F446_LedOn(GPIO_D, DISC_1_BLUE_PIN);
}

uint8_t NUCLEO_F446RE_GreenLedOn()
{
	return STM32F446_LedOn(GPIO_A, NUCLEO_GREEN_PIN);
}


uint8_t STM32F407G_DISC_1_UserButtonSetup()
{
	STM32F446_ButtonSetup(GPIO_A, DISC1_USER_BUTTON);
	return 0;
}

uint8_t STM32F407G_DISC_1_IsUserButtonPushed()
{
	//if pushed, return 1 else return 0
	return GPIOx_IDR_get(GPIO_A, DISC1_USER_BUTTON);	
}
