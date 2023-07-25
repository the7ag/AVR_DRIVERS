/*
 * TestApp.c
 *
 * Created: 04/02/2023 03:41:28 م
 *  Author: The7ag
 */ 
#include "ADC.h"
#include "../../HAL/PushButton/PushButton.h"
#include "../../HAL/LCD/LCD.h"
#define F_CPU 1000000UL
#include <UTIL/delay.h>
//PB Pin3 port b
// POT Channel 4
//LCD PORTA,PORTB,Pin0,Pin1,Pin3,Pin2,Pin1,Pin0
void ADC()
{
	uint16 value=0;
	/*LCD Init*/
	LCD_Init(PORTA,PORTB,Pin0,Pin1,Pin3,Pin2,Pin1,Pin0);
	/*Button Init*/
	ButtonInit(PORTB,Pin3);
	/*ADC init*/
	DIO_SetPinDirection(PORTA,Pin4,Input);
	ADC_Init();
	LCD_Print("Value:");
	while(1)
	{
		if (ReadButton(PORTB,Pin3)==HIGH)
		{
			LCD_SetCursor(0,6);
			value=analogRead(ADC_Channel_4);
			LCD_IntegerToString(value);		
			_delay_ms(500);
		}else
		{
			LCD_SetCursor(0,6);
			LCD_Print("    ");
		}
	}
}