//GPIO address declaration and driver functionalities
#ifndef RCC_H
#define RCC_H

#include <stdint.h>
#include "../../SLib/slib.h"

/**
RCC struct 
Now only defined needed one.
Done it byte addresable, should be bit addressable
Last GPIO only 1 bit legal
*/
typedef struct RCC {
	uint8_t volatile PORTS1;
	uint8_t volatile PORTS2;
	uint8_t volatile PORTS3;
	uint8_t volatile PORTS4;
} RCCx;

/* GPIO addressing */
#define PERIPH_BASE ((uint32_t) 0x40000000)

/* Peripheral base address in the bit-band region AHB1ENR */
#define AHB1ENR_BASE (PERIPH_BASE + 0x23800)

/* RCC base address */
#define dirRCC_AHB1ENR (AHB1ENR_BASE+0x30)
	
/* RCC pointers */
#define RCC_AHB1ENR ((RCCx *) dirRCC_AHB1ENR)

#endif /* RCC_H */
