/*
 * TestApp.c
 *
 * Created: 07/02/2023 05:08:36 م
 *  Author: The7ag
 */ 
#include "Timer0.h"
#include "../../HAL/LED/LED.h"
#include "../Global_INT/Global_INT.h"
#include "UTIL/delay.h"
void timer()
{
	LED_Init(PORTA,Pin3);
	LED_Init(PORTB,Pin3);
	LED_On(PORTB,Pin3);
	TIMER0_voidInitializeTimer0();
	while(1)
	{
	LED_Toggle(PORTA,Pin3);
	LED_Toggle(PORTB,Pin3);
	delay_T0(1000);
	}
}