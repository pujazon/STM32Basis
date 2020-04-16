//High level functions API to use GPIO from STM32
#ifndef API_GPIO_H
#define API_GPIO_H

#include "../SLib/slib.h"
#include "./gpio.h"
#include "../Arch/RCC/RCC.h"

/************ STM32 *************************/
//No error handling becaus einputs are hardcoded, only should have 
//side channels security checks
//TODO: Issolate RCC register accesses and handlers
//			and rethink where to place that function(inside handlers, as a setup fuction, with flag...)
uint8_t STM32F446_GPIO_Setup(GPIOx *GPIO);
uint8_t STM32F446_LedOn(GPIOx *GPIO, uint8_t pin);
uint8_t STM32F446_ButtonSetup(GPIOx *GPIO, uint8_t pin);

/************ DISCOVER_1 ********************/
#define DISC_1_ORANGE_PIN 	13
#define DISC_1_GREEN_PIN 		12
#define DISC_1_RED_PIN 			14
#define DISC_1_BLUE_PIN 		15
#define DISC1_USER_BUTTON		0

/* OUTPUT */
uint8_t STM32F407G_DISC_1_OrangeLedOn(void);
uint8_t STM32F407G_DISC_1_GreenLedOn(void);
uint8_t STM32F407G_DISC_1_RedLedOn(void);
uint8_t STM32F407G_DISC_1_BlueLedOn(void);

/* INPUT */
uint8_t STM32F407G_DISC_1_UserButtonSetup(void);
uint8_t STM32F407G_DISC_1_IsUserButtonPushed(void);

/************* NUCLEO_F446RE **********************/
#define NUCLEO_GREEN_PIN 	5
uint8_t NUCLEO_F446RE_GreenLedOn(void);

#endif /* GPIO_H */
