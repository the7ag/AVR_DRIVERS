/*
 * RTO.h
 *
 * Created: 16/07/2023 04:21:27 م
 *  Author: The7ag
 */ 


#ifndef RTO_H_
#define RTO_H_
#include "RTO_config.h"
#include "RTO_private.h"
#include "../../MCAL/DIO/DIO.h"

#include "../../MCAL/Timer0/Timer0.h"
#include "../../HAL/LED/LED.h"

void RTO_Init(void);
/*Timer config 
CTC MODE
CPU 8 MHZ
Prescalar 8
OCR0 value 199
vector 10 
{
	static uint16 counter=0;
	counter++;
	if(counter == 5 ) //for 1 ms delay
	{
		//clear counter
		counter=0;
		if(TIMER0_CTCCallBackPointer != NULL)
		{
			TIMER0_CTCCallBackPointer();
		}
	}
}
*/

void RTO_StartScheduler(void);

void RTO_CreateTask(uint8_t Priority, uint16 Periodicity , uint16 Firstdelay,void(*ptrtofun)(void));
void RTO();

#endif /* RTO_H_ */