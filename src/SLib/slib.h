//Security utils applied to our OS
#ifndef SLIB_H
#define SLIB_H

/*
	Defined type due to using memory instead of constant precompiled macros
	in order to increase security against fault injection atacs (inmediate easy to attack).
*/
typedef unsigned int SecVal;

/* TRUE status value used for all functions in OS */
//TODO: Generate randomly each build (rand()). Analise if has bennefits or not
extern SecVal SecTRUE;

/* FALSE status value used for all functions in OS */
//TODO: Generate randomly each build (rand()). Analise if has bennefits or not
extern SecVal SecFALSE;

/* Endless loop when security issue is not satisfied */
//TODO: Evaluate when should be raised too
SecVal Die(void);

#endif /* SLIB_H */
