/*
 * RTO.c
 *
 * Created: 16/07/2023 04:21:38 م
 *  Author: The7ag
 */ 
#include "RTO.h"

Task_TCB TASKS[RTO_NUMBER_OF_TASKS];

void RTO_StartScheduler(void)
{
	TIMER0_voidInitializeTimer0();
}
void RTO_Init(void)
{
	TIMER0_voidCTCCallBackfunction(&RTO_Scheduler);
}
void RTO_CreateTask(uint8_t Priority, uint16 Periodicity , uint16 Firstdelay,void(*ptrtofun)(void))
{
	TASKS[Priority].Periodicity = Periodicity;
	TASKS[Priority].FirstDelay  = Firstdelay;
	TASKS[Priority].pfun        = ptrtofun;
}
static void RTO_Scheduler(void)
{
	/* for loop to check on every TCB */
	uint8_t counter;
	for(counter = 0; counter < RTO_NUMBER_OF_TASKS ; counter++)
	{
		if(TASKS[counter].FirstDelay == 0)
		{
			//Call function
			TASKS[counter].pfun();
			//Periodicity-1 => firstdelay
			TASKS[counter].FirstDelay = TASKS[counter].Periodicity - 1;
		}
		else
		{
			TASKS[counter].FirstDelay--;
		}
	}

}