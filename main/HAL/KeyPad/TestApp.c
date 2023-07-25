/*
 * TestApp.c
 *
 * Created: 12/02/2023 03:40:14 ص
 *  Author: The7ag
 */ 
#include "KeyPad.h"
#include "../LCD/LCD.h"
void KeyPad()
{
	uint8_t Key;
	LCD_Init(PORTA,PORTA,Pin4,Pin5,Pin3,Pin2,Pin1,Pin0);
	Keypad_Init(PORTC,Pin0,Pin1,Pin2,Pin3,Pin4,Pin5,Pin6,Pin7);
	LCD_Print("KEY:");
	LCD_SetCursor(0,5);
	while(1)
	{
		Key=Read_Keypad();
		LCD_SendData(Key);
	}
}