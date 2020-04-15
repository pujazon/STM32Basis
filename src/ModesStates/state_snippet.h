//Snippet code working with Cortex Mx Operational modes and states
#ifndef STATE_SNIPPET_H
#define STATE_SNIPPET_H

#include <stdint.h>

uint8_t state_snippet(void);

//Dummy ISR used to change operational state in Thread mode
uint8_t ModeState_ISR(void);

//Software interruption trigger, should be moved from here
extern uint8_t Call_ModeState_ISR(void);

#endif /* STATE_SNIPPET_H */
