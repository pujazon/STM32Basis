//GPIO address declaration and driver functionalities
#ifndef GPIOx_H
#define GPIOx_H

#include <stdint.h>
#include "slib.h"

/**
GPIOx struct 
Each registry is 32bit (so 0x04 bytes of offest, use uint32_t)
Also they will be volatile because can change unexpected any moment (generally, are RW)
(peripherals, memory potentally be modfied by multiple tasks or global potentally modified by ISR).
https://barrgroup.com/embedded-systems/how-to/c-volatile-keyword
*/
typedef struct GPIO {
	uint32_t volatile MODER;
	uint32_t volatile OTYPER;
	uint32_t volatile OSPEEDR;
	uint32_t volatile PUPDR;
	uint32_t volatile IDR;
	uint32_t volatile ODR;
	uint32_t volatile BSRR;
	uint32_t volatile LCKR;
	uint32_t volatile AFRL;
	uint32_t volatile AFRH;
} GPIOx;

/* GPIO addressing */
#define PERIPH_BASE ((uint32_t) 0x40000000)

/* Peripheral base address in the bit-band region APBH1 BUS */
#define APB1PERIPH_BASE (PERIPH_BASE + 0x20000)

/* GPIOx base address */
#define GPIO_A_addr (APB1PERIPH_BASE)
#define GPIO_B_addr (APB1PERIPH_BASE + sizeof(GPIOx))
#define GPIO_C_addr (APB1PERIPH_BASE + sizeof(GPIOx)*2 )
#define GPIO_D_addr (APB1PERIPH_BASE + sizeof(GPIOx)*3 )
#define GPIO_E_addr (APB1PERIPH_BASE + sizeof(GPIOx)*4 )
#define GPIO_F_addr (APB1PERIPH_BASE + sizeof(GPIOx)*5 )
#define GPIO_G_addr (APB1PERIPH_BASE + sizeof(GPIOx)*6 )
#define GPIO_H_addr (APB1PERIPH_BASE + sizeof(GPIOx)*7 )
#define GPIO_I_addr (APB1PERIPH_BASE + sizeof(GPIOx)*8 )
#define GPIO_J_addr (APB1PERIPH_BASE + sizeof(GPIOx)*9  )
#define GPIO_K_addr (APB1PERIPH_BASE + sizeof(GPIOx)*10 )
	
/* GPIOx pointers */
#define GPIO_A ((GPIOx *) GPIO_A_addr)
#define GPIO_B ((GPIOx *) GPIO_B_addr)
#define GPIO_C ((GPIOx *) GPIO_C_addr)
#define GPIO_D ((GPIOx *) GPIO_D_addr)
#define GPIO_E ((GPIOx *) GPIO_E_addr)
#define GPIO_F ((GPIOx *) GPIO_F_addr)
#define GPIO_G ((GPIOx *) GPIO_G_addr)
#define GPIO_H ((GPIOx *) GPIO_H_addr)
#define GPIO_I ((GPIOx *) GPIO_I_addr)
#define GPIO_J ((GPIOx *) GPIO_J_addr)
#define GPIO_K ((GPIOx *) GPIO_K_addr)

/* Value in GPIOx_MODER which means pin set as input GPIO */
#define GPIOx_MODER_INPUT 0x00

/* Value in GPIOx_MODER which means pin set as output GPIO */
#define GPIOx_MODER_OUTPUT 0x01

/* Value in GPIOx_MODER which means pin set as alternate GPIO */
#define GPIOx_MODER_ALTERNATE 0x02

/* Value in GPIOx_MODER which means pin set as analog GPIO */
#define GPIOx_MODER_ANALOG 0x03

/* Boundary of possible input values */
#define GPIOx_MODER_ERROR_VALUE 0x04

/* Boundary of possible input values */
#define GPIOx_MODER_MAX_PIN 16

//TODO: no plain values, diferent value ones. 
//TODO: Use pointers (passed by reference) instead passing on parameter  
/**
       * Sets to value the GPIO[pin]_MODER set
       * @param pin: pin number from 0..15
       * @param value: 2 bits value write on GPIO[pin]_MODER[1:0]
			 *				00: Input (reset value)
			 *				01: GP output 
			 *				10: Alternate
			 *				11: Analog
			 *				other value will be threat as security issue
       * @return SecTRUE if okey, SecFLASE otherwise
       */
SecVal GPIOx_MODER_set(GPIOx *GPIO, uint32_t pin, uint32_t value);

/**
       * Gets the value the GPIO[pin]_MODER set
       * @param pin: pin number from 0..15
       * @param Stores the 2 bits value read from GPIO[pin]_MODER[1:0]
			 *				00: Input (reset value)
			 *				01: GP output 
			 *				10: Alternate
			 *				11: Analog
			 *				other value will be threat as security issue
       * @return SecTRUE if okey, SecFALSE otherwise
       */
SecVal GPIOx_MODER_get(uint8_t pin, uint8_t* value);
			 
/**
				Bits from 31..16 mustn't have any other value, if referenced to them, security error.
			  OTy: Port x configuration bits (y = 0..15)
				These bits are written by software to configure the output type of the I/O port.
				0: Output push-pull (reset state)
				1: Output open-drain
				*/

SecVal GPIOx_OTYPER_set(uint8_t pin, uint8_t value);

//Same, Bit 31..16 cannot be addressed

SecVal GPIOx_OTYPER_get(uint8_t pin, uint8_t* value);

/**
				Bits 2y:2y+1 OSPEEDRy[1:0]: Port x configuration bits (y = 0..15)
				These bits are written by software to configure the I/O output speed.
				00: Low speed
				01: Medium speed
				10: High speed
				11: Very high speed
				*/
SecVal GPIOx_OSPEEDR_set(uint8_t pin, uint8_t value);


SecVal GPIOx_OSPEEDR_get(uint8_t pin, uint8_t* value);

/**
				PUPDRy[1:0]: Port x configuration bits (y = 0..15)
				These bits are written by software to configure the I/O pull-up or pull-down
				00: No pull-up, pull-down
				01: Pull-up
				10: Pull-down
				11: Reserved
				*/
SecVal GPIOx_PUPDR_set(uint8_t pin, uint8_t value);

SecVal GPIOx_PUPDR_get(uint8_t pin, uint8_t* value);

/**
				Bits 31:16 Reserved, must be kept at reset value. Else, addressing them, security error
				Bits 15:0 IDRy: Port input data (y = 0..15)
				These bits are read-only and can be accessed in word mode only. They contain the input
				value of the corresponding I/O port.
				*/
SecVal GPIOx_IDR_set(uint8_t pin, uint8_t value);

SecVal GPIOx_IDR_get(uint8_t pin, uint8_t* value);

/**
				Bits 31:16 Reserved, must be kept at reset value. Else, addressing them, security error
				Bits 15:0 IDRy: Port input data (y = 0..15)
				These bits are read-only and can be accessed in word mode only. They contain the input
				value of the corresponding I/O port.
				*/
SecVal GPIOx_ODR_set(uint8_t pin, uint8_t value);

SecVal GPIOx_ODR_get(uint8_t pin, uint8_t* value);

//TODO: Still missing 4 of them


#endif /* GPIOx_H */