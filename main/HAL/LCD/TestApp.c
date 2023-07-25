/*
 * TestApp.c
 *
 * Created: 03/02/2023 04:38:32 م
 *  Author: The7ag
 */
#include "LCD.h" 
#include "../PushButton/PushButton.h"
uint8_t man[8] = {
	0b00100,
	0b01010,
	0b00100,
	0b01110,
	0b10101,
	0b01110,
	0b01010,
	0b00000
};
uint8_t GUN[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b01010,
	0b01001,
	0b00000,
	0b00000
};
uint8_t bulletStart[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b11000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};
uint8_t bulletMID[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b00110,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};
uint8_t bulletEND[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b00011,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};
uint8_t deadHead[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b10110,
	0b11101,
	0b10110,
	0b00000,
	0b00000
};

uint8_t deadBody[8] = {
	0b00000,
	0b00000,
	0b00001,
	0b01100,
	0b00111,
	0b01100,
	0b00001,
	0b00000
};
void shoot()
{
	LCD_Clear();
	LCD_DisplayCutomChar(0);
	LCD_SetCursor(0,1);
	LCD_DisplayCutomChar(1);
	LCD_SetCursor(0,15);
	LCD_DisplayCutomChar(0);
	for (int i=2;i<14;i++)
	{
		LCD_SetCursor(0,i);
		LCD_DisplayCutomChar(4);
		_delay_ms(100);
		LCD_SetCursor(0,i);
		LCD_Print(" ");
		LCD_DisplayCutomChar(2);
		_delay_ms(100);
		LCD_SetCursor(0,i);
		LCD_Print(" ");
		LCD_DisplayCutomChar(3);
		_delay_ms(100);
		LCD_SetCursor(0,i);
		LCD_Print(" ");
	}
	LCD_SetCursor(0,15);
	LCD_Print(" ");
	LCD_SetCursor(0,14);
	LCD_DisplayCutomChar(5);
	LCD_SetCursor(0,15);
	LCD_DisplayCutomChar(6);
	LCD_SetCursor(0,2);
	LCD_Print("You Died");
	_delay_ms(5000);
	LCD_Clear();
}

void idle()
{
	LCD_Clear();
	LCD_DisplayCutomChar(0);
	LCD_SetCursor(0,1);
	LCD_DisplayCutomChar(1);
	LCD_SetCursor(0,15);
	LCD_DisplayCutomChar(0);
	LCD_SetCursor(0,2);
	LCD_Print("Press it");
	_delay_ms(30);
}



void LCD()
{
LCD_Init(PORTA,PORTB,Pin0,Pin1,Pin0,Pin1,Pin2,Pin3);
ButtonInit(PORTA,Pin7);
LCD_StoreCutomChar(man,0);
LCD_StoreCutomChar(GUN,1);
LCD_StoreCutomChar(bulletStart,2);
LCD_StoreCutomChar(bulletMID,3);
LCD_StoreCutomChar(bulletEND,4);
LCD_StoreCutomChar(deadBody,5);
LCD_StoreCutomChar(deadHead,6);
while (1)
{
	DIO_VALUE x=ReadButton(PORTA,Pin7);
	_delay_ms(150);
	if (x==HIGH)
	{
		shoot();
	}else
	{
		idle();
	}
}

}