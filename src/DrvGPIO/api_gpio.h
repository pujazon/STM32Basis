//High level functions API to use GPIO from STM32
#ifndef API_GPIO_H
#define API_GPIO_H

#include "../SLib/slib.h"
#include "./gpio.h"

//No error handling becaus einputs are hardcoded, only should have 
//side channels security checks
uint8_t STM32F407G_DISC_1_OrangeLedOn(void);

#endif /* GPIO_H */
