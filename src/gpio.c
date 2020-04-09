#include "gpio.h"
#include "slib.h"

//TODO: UnitTests must be done
//TODO: Except GPIO field, all code is the same, replicated.
//		  Encapsulate them and use them on setters and getters

SecVal GPIOx_MODER_set(GPIOx *GPIO, uint32_t pin, uint32_t value) {
	
	SecVal ret = SecTRUE;
	//TODO: Should be transparent to driver the calculus. Add the macro on .h 
	uint32_t mask = 0;
	
	if (value >= GPIOx_MODER_ERROR_VALUE) {
		ret = SecFALSE;
	}
	
	if (pin >= GPIOx_MAX_PIN) {
		ret = SecFALSE;
	}
	
	mask = (value << (pin-1));
	
	GPIO->MODER = (GPIO->MODER) | (mask);
	return ret;
}


SecVal GPIOx_OTYPER_set(GPIOx *GPIO, uint32_t pin, uint32_t value) {
	
	SecVal ret = SecTRUE;
	//TODO: Should be transparent to driver the calculus. Add the macro on .h 
	uint32_t mask = 0;
	
	if (value >= GPIOx_OTYPER_ERROR_VALUE) {
		ret = SecFALSE;
	}
	
	if (pin >= GPIOx_MAX_PIN) {
		ret = SecFALSE;
	}
	
	mask = value << pin;
	
	GPIO->OTYPER = (GPIO->OTYPER) | (mask);
	return ret;
}


SecVal GPIOx_OSPEEDR_set(GPIOx *GPIO, uint32_t pin, uint32_t value) {
	
	SecVal ret = SecTRUE;
	//TODO: Should be transparent to driver the calculus. Add the macro on .h 
	uint32_t mask = 0;
	
	if (value >= GPIOx_PUPDR_RESERVED) {
		ret = SecFALSE;
	}
	
	if (pin >= GPIOx_MAX_PIN) {
		ret = SecFALSE;
	}
	
	mask = (value << (pin-1));
	
	GPIO->OSPEEDR = (GPIO->OSPEEDR) | (mask);
	return ret;
}
SecVal GPIOx_PUPDR_set(GPIOx *GPIO, uint32_t pin, uint32_t value) {
	
	SecVal ret = SecTRUE;
	//TODO: Should be transparent to driver the calculus. Add the macro on .h 
	uint32_t mask = 0;
	
	if (value >= GPIOx_PUPDR_RESERVED) {
		ret = SecFALSE;
	}
	
	if (pin >= GPIOx_MAX_PIN) {
		ret = SecFALSE;
	}
	
	mask = (value << (pin-1));
	
	GPIO->PUPDR = (GPIO->PUPDR) | (mask);
	return ret;
}

SecVal GPIOx_ODR_set(GPIOx *GPIO, uint32_t pin, uint32_t value) {
	
	SecVal ret = SecTRUE;
	//TODO: Should be transparent to driver the calculus. Add the macro on .h 
	uint32_t mask = 0;
	
	if (value >= GPIOx_OTYPER_ERROR_VALUE) {
		ret = SecFALSE;
	}
	
	if (pin >= GPIOx_MAX_PIN) {
		ret = SecFALSE;
	}
	
	mask = value << pin;
	
	GPIO->ODR = (GPIO->ODR) | (mask);
	return ret;
}
