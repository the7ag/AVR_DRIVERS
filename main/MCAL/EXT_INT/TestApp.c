/*
 * TestApp.c
 *
 * Created: 05/02/2023 10:11:34 م
 *  Author: The7ag
 */ 
#include "EXT_INT.h"
#include "../../HAL/LED/LED.h"
#include "../../HAL/PushButton/PushButton.h"
#include "../../HAL/Buzzer/Buzzer.h"

#define F_CPU 1000000UL
#include <util/delay.h>
void EXT_INT_0_ISR();

void Interrupt()
{
	ButtonInit(PORTD,Pin3);
	LED_Init(PORTA,Pin1);
	BuzzerInit(PORTB,Pin4);
	/*interrupt EXT Int 0*/
	EXT_INT_init();
	EXT_INT0_SetCallback(EXT_INT_0_ISR);
	/*Enable prephiral interrupts*/
	EXT_INT0_Enable();
	/*Enable Globla interrupts*/
	EXT_INT_Enable();
	
	while(1)
	{
		LED_Toggle(PORTA,Pin1);
		_delay_ms(500);
	}
}
void EXT_INT_0_ISR()
{
	Buzzer_TurnOn(PORTB,Pin4);
	_delay_ms(5000);
	Buzzer_TurnOff(PORTB,Pin4);
	_delay_ms(1000);
}