/*
 * TestPWM.c
 *
 * Created: 23/06/2023 03:14:37 م
 *  Author: The7ag
 */ 
#include "Timer0.h"
#define F_CPU 1000000UL
#include <util/delay.h>
void pwm()
{
	TIMER0_voidInitializeTimer0();
	DIO_SetPinDirection(PORTB,Pin3,Output);
	while(1)
	{
		for (int i=0;i<100;i++)
		{
		TIMER0_voidFastPWM(i);
		_delay_ms(150);
		}
	}
	
}
