/*
 * TestAPP.c
 *
 * Created: 25/06/2023 08:19:10 م
 *  Author: The7ag
 */ 
#include "SPI.h"
#define F_CPU 8000000UL
#include <util/delay.h>
void SPI()
{
	SPI_Initialize();
	while(1)
	{
	DIO_SetPinValue(PORTB,Pin4,LOW);
	SPI_SendData('h');
	DIO_SetPinValue(PORTB,Pin4,HIGH);
	_delay_ms(1000);
	}
}