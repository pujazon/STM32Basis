//Utils functionalities used on GPIO driver implementation
#ifndef UTILS_GPIOx_H
#define UTILS_GPIOx_H

#include <stdint.h>
#include "../SLib/slib.h"

//TODO: change values
#define utilsGpioError 1
#define utilsGpioSuccessfull 0


/**
				Function to check input values 
				@return: 0 meands Successfull, 
								 1 means error in vlue, 
								 2 means error in pin, 
								 3 means both errors
								 */
uint8_t UtilsGPIO_CheckValues(uint32_t value, uint32_t pin, uint32_t errorValue, uint32_t errorPin);

/**
				Function to generate input mask value written on GPIO registers
				@paramm: twoBitsRange, 0 means only one bit, 1 means value is two bits
								 */
uint32_t UtilsGPIO_GetMask(uint32_t value, uint32_t pin, uint8_t twoBitsRange);

#endif /* UTILS_GPIOx_H */
