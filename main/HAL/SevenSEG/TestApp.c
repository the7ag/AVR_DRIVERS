/*
 * TestApp.c
 *
 * Created: 02/02/2023 10:54:24 م
 *  Author: The7ag
 */ 
#include "../../APP/App.h"
#define  F_CPU 1000000UL
#include <util/delay.h>
void seven(){
	Seven_Init(PORTA,Pin0,PORTB,Pin1);
	Seven_Init(PORTA,Pin0,PORTB,Pin0);
	while (1)
	{
		for(uint32 i=0;i<=99;i++)
		{
			uint8_t Right=i%10;
			uint8_t Left=i/10;
			for(uint8_t i=0;i<50;i++)
			{
				Seven_Off(PORTB,Pin0);
				Seven_Off(PORTB,Pin1);
				Seven_SendNumber(PORTA,Pin0,Right);
				Seven_On(PORTB,Pin0);
				_delay_ms(10);
				Seven_Off(PORTB,Pin0);
				Seven_SendNumber(PORTA,Pin0,Left);
				Seven_On(PORTB,Pin1);
				_delay_ms(10);
			}
		}
	}
}