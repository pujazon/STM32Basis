#include "../SLib/slib.h"
#include "./state_snippet.h"
#include <stdio.h>
#include <stdint.h>

uint8_t state_snippet(void) 
{	
	//1. Change from priveleged to unprivileged
	//TODO: Encapsulate that
	
	Call_ModeState_ISR();
	
	//Try to do privileged access
	
	//2. Change to privileged 
	
	//Try to do same action again
	
	return 0;
}
