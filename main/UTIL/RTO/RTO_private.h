/*
 * RTO_private.h
 *
 * Created: 16/07/2023 04:21:21 م
 *  Author: The7ag
 */ 


#ifndef RTO_PRIVATE_H_
#define RTO_PRIVATE_H_

#include "../../MCAL/DIO/DIO.h"
typedef struct
{
	/* periodicity*/
	uint16 Periodicity;
	/* FirstDleay */
	uint16 FirstDelay;
	/* pointer to function */
	void(*pfun)(void);
}Task_TCB;

//To protect it from calling from other than timer int
static void RTO_Scheduler(void);


#endif /* RTO_PRIVATE_H_ */