#include "./gpio.h"
#include "./utils_gpio.h"
#include "../SLib/slib.h"

//TODO: UnitTests must be done

uint8_t GPIOx_MODER_set(GPIOx *GPIO, uint32_t pin, uint32_t value) 
{	
	uint8_t ret, step;
	uint32_t mask;
	
	ret = GPIO_SUCCESSFULL;
	
	step = UtilsGPIO_CheckValues(value,pin,GPIOx_MODER_ERROR_VALUE,GPIOx_MAX_PIN);
	
	if (step > utilsGpioSuccessfull) {
	  ret = GPIO_WRONG_INPUTS;
	} 
	else {
		mask = UtilsGPIO_GetMask(value,pin,GPIO_TWO_BIT_VALUE);
		GPIO->MODER = (GPIO->MODER) | (mask);
	}
	
	return ret;
}


uint8_t GPIOx_OTYPER_set(GPIOx *GPIO, uint32_t pin, uint32_t value) 
{
	uint8_t ret, step;
	uint32_t mask;
	
	ret = GPIO_SUCCESSFULL;
	
	step = UtilsGPIO_CheckValues(value,pin,GPIOx_OTYPER_ERROR_VALUE,GPIOx_MAX_PIN);
	
	if (step > utilsGpioSuccessfull) {
	  ret = GPIO_WRONG_INPUTS;
	} 
	else {
		mask = UtilsGPIO_GetMask(value,pin,GPIO_ONE_BIT_VALUE);
		GPIO->OTYPER = (GPIO->OTYPER) | (mask);
	}
	
	return ret;
}


uint8_t GPIOx_OSPEEDR_set(GPIOx *GPIO, uint32_t pin, uint32_t value) 
{
	uint8_t ret, step;
	uint32_t mask;
	
	ret = GPIO_SUCCESSFULL;
	//Wrong check value
	step = UtilsGPIO_CheckValues(value,pin,GPIOx_PUPDR_RESERVED,GPIOx_MAX_PIN);
	
	if (step > utilsGpioSuccessfull) {
	  ret = GPIO_WRONG_INPUTS;
	} 
	else {
		mask = UtilsGPIO_GetMask(value,pin,GPIO_TWO_BIT_VALUE);
		GPIO->OSPEEDR = (GPIO->OSPEEDR) | (mask);
	}
	
	return ret;
}

uint8_t GPIOx_PUPDR_set(GPIOx *GPIO, uint32_t pin, uint32_t value)
{
	uint8_t ret, step;
	uint32_t mask;
	
	ret = GPIO_SUCCESSFULL;
	//Wrong check value
	step = UtilsGPIO_CheckValues(value,pin,GPIOx_PUPDR_RESERVED,GPIOx_MAX_PIN);
	
	if (step > utilsGpioSuccessfull) {
	  ret = GPIO_WRONG_INPUTS;
	} 
	else {
		mask = UtilsGPIO_GetMask(value,pin,GPIO_TWO_BIT_VALUE);
		GPIO->PUPDR = (GPIO->PUPDR) | (mask);
	}
	
	return ret;
}

uint8_t GPIOx_ODR_set(GPIOx *GPIO, uint32_t pin, uint32_t value)
{

	uint8_t ret, step;
	uint32_t mask;
	
	ret = GPIO_SUCCESSFULL;
	
	step = UtilsGPIO_CheckValues(value,pin,GPIOx_OTYPER_ERROR_VALUE,GPIOx_MAX_PIN);
	
	if (step > utilsGpioSuccessfull) {
	  ret = GPIO_WRONG_INPUTS;
	} 
	else {
		mask = UtilsGPIO_GetMask(value,pin,GPIO_ONE_BIT_VALUE);
		GPIO->ODR = (GPIO->ODR) | (mask);
	}
	
	return ret;
}
