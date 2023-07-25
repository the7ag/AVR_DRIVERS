/*
 * Testapp.c
 *
 * Created: 01/07/2023 06:29:32 م
 *  Author: The7ag
 */ 
#include "EEPROM.h"
#include "../LCD/LCD.h"
void EEPROM()
{
	EEPROM_voidInit();
	LCD_Init(PORTD,PORTD,Pin0,Pin1,Pin2,Pin3,Pin4,Pin5);
	uint8_t recived;
	while(1)
	{
		EEPROM_u8WriteDataByte('A',0);
		_delay_ms(1000);
		EEPROM_u8ReadDataByte(&recived,0);
		LCD_SendData(recived);
		_delay_ms(1000);
		LCD_Clear();
	}
}