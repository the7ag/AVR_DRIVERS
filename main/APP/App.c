/*
 * Test.c
 *
 * Created: 01/02/2023 08:30:35 م
 *  Author: The7ag
 */ 
#include "App.h"
void app(){
	LCD_Init(PORTA,PORTB,Pin0,Pin1,Pin0,Pin1,Pin2,Pin3);
	ButtonInit(PORTA,Pin6);
	ButtonInit(PORTA,Pin7);
	char message[]="Hello World";
	LCD_Print(message);
	_delay_ms(2500);
	LCD_Clear();
	while(1)
	{
		strcpy(message,"Hello");
		if (ReadButton(PORTA,Pin7)==HIGH)
		{
			_delay_ms(350);
			strcpy(message,"Hello");
		}
		if (ReadButton(PORTA,Pin6)==HIGH)
		{
			_delay_ms(350);
			strcpy(message,"GoodBye");
		}
		for (uint8_t i=0;i<16;i++)
		{
			LCD_Clear();
			LCD_SetCursor(1,i);
			LCD_Print(message);
			_delay_ms(100);
		}
	}
}