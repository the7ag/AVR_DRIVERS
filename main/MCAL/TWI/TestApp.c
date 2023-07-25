/*
 * TestApp.c
 *
 * Created: 26/06/2023 06:51:16 م
 *  Author: The7ag
 */ 
#include "TWI.h"
#include "../Global_INT/Global_INT.h"
#include "../../HAL/LCD/LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>
void TWI()
{
	TWI_voidMasterInit();
	Global_INT_Enable();
	LCD_Init(PORTD,PORTD,Pin0,Pin1,Pin2,Pin3,Pin4,Pin5);
	uint8_t err;
	err=TWI_enuSendStartCondition();
	LCD_IntegerToString(err);
	LCD_SendData(',');
	err=TWI_enuSendSlaveWithWrite(0x10); //"Sent addresses are shifted sof 0x10 == 0x20 in adress"
	LCD_IntegerToString(err);
	LCD_SendData(',');
	while(1)
	{
		err=TWI_enuSendDataByte('A');
		LCD_IntegerToString(err);
		_delay_ms(1000);
		LCD_Clear();
		//TWI_enuSendDataByte('B');
	}
}
