#include "./gpio.h"
#include "./utils_gpio.h"
#include "../SLib/slib.h"

uint8_t UtilsGPIO_CheckValues(uint32_t value, uint32_t pin, uint32_t errorValue, uint32_t errorPin) 
{
	uint8_t ret = utilsGpioSuccessfull;
	
	if (value >= errorValue) {
		ret += utilsGpioError;
	}
	
	if (pin >= errorPin) {
		ret += 2*utilsGpioError;
	}
	
	return ret;
}

uint32_t UtilsGPIO_GetMask(uint32_t value, uint32_t pin, uint8_t bitsPerValue)
{	
	uint32_t mask = 0;
	mask = value << (pin*bitsPerValue);
	return mask;
}
