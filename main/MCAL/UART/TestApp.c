/*
 * TestApp.c
 *
 * Created: 24/06/2023 09:55:28 م
 *  Author: The7ag
 */ 
#include "UART.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../Global_INT/Global_INT.h"
void UART()
{
	UART_Initialize();
	Global_INT_Enable();

	while(1)
	{
		_delay_ms(1000);
		UART_SendMsg("HelloWorld",13);
		_delay_ms(1000);
		UART_SendNumber(1543);
		_delay_ms(1000);
	}
}