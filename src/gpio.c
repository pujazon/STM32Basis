#include "gpio.h"
#include "slib.h"


SecVal GPIOx_MODER_set(GPIOx *GPIO, uint32_t pin, uint32_t value) {
	
	SecVal ret = SecTRUE;
	//TODO: Should be transparent to driver the calculus. Add the macro on .h 
	uint32_t mask = 0;
	
	if (value >= GPIOx_MODER_ERROR_VALUE) {
		ret = SecFALSE;
	}
	
	if (pin >= GPIOx_MODER_MAX_PIN) {
		ret = SecFALSE;
	}
	
	mask = (value << (pin-1));
	
	GPIO->MODER = (GPIO->MODER) | (mask);
	return ret;
}
