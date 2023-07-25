/*
 * LCD.c
 *
 * Created: 03/02/2023 03:39:34 م
 *  Author: The7ag
 */ 
#include "LCD.h"
static uint8_t initdone=0;
static DIO_PORT_ID LCD_Data,LCD_Control;
static DIO_PIN_ID RS, E, D4, D5, D6, D7;
void LCD_Init(DIO_PORT_ID LCD_Data_Port,DIO_PORT_ID LCD_Control_Port ,DIO_PIN_ID rs,DIO_PIN_ID e,DIO_PIN_ID d4,DIO_PIN_ID d5,DIO_PIN_ID d6,DIO_PIN_ID d7)
{
	LCD_Data=LCD_Data_Port;
	LCD_Control=LCD_Control_Port;
	RS=rs;
	E=e;
	D4=d4;
	D5=d5;
	D6=d6;
	D7=d7;
	DIO_SetPinDirection(LCD_Control_Port,RS,Output);
	DIO_SetPinDirection(LCD_Control_Port,E,Output);
	DIO_SetPinDirection(LCD_Data_Port,D4,Output);
	DIO_SetPinDirection(LCD_Data_Port,D5,Output);
	DIO_SetPinDirection(LCD_Data_Port,D6,Output);
	DIO_SetPinDirection(LCD_Data_Port,D7,Output);
	_delay_ms(30);
	LCD_SendInstruction(0x20);
	LCD_SendInstruction(0x20);
	LCD_SendInstruction(0x80); //Send 2 Line Mode with 5*7 Pixel
	_delay_ms(1);
	LCD_SendInstruction(0x00); 
	LCD_SendInstruction(0xC0); //Send Display on Cursor on Blink off
	_delay_ms(1);

	LCD_SendInstruction(0x00);
	LCD_SendInstruction(0x10);
	_delay_ms(2);
	initdone=1;
}
void LCD_SendData(uint8_t Data)
{
	//RW LOW
	DIO_SetPinValue(LCD_Control,RS,HIGH);
	//High Nibble
	DIO_SetPinValue(LCD_Data,D4,ReadBit(Data,4));
	DIO_SetPinValue(LCD_Data,D5,ReadBit(Data,5));
	DIO_SetPinValue(LCD_Data,D6,ReadBit(Data,6));
	DIO_SetPinValue(LCD_Data,D7,ReadBit(Data,7));
	DIO_SetPinValue(LCD_Control,E,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_Control,E,LOW);
	//Lower Nibble
	DIO_SetPinValue(LCD_Data,D4,ReadBit(Data,0));
	DIO_SetPinValue(LCD_Data,D5,ReadBit(Data,1));
	DIO_SetPinValue(LCD_Data,D6,ReadBit(Data,2));
	DIO_SetPinValue(LCD_Data,D7,ReadBit(Data,3));
	DIO_SetPinValue(LCD_Control,E,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_Control,E,LOW);
	_delay_ms(2);
}

void LCD_SendInstruction(uint8_t CMD)
{ 
	//RW LOW
	DIO_SetPinValue(LCD_Control,RS,LOW);
	//High Nibble
	DIO_SetPinValue(LCD_Data,D4,ReadBit(CMD,4));
	DIO_SetPinValue(LCD_Data,D5,ReadBit(CMD,5));
	DIO_SetPinValue(LCD_Data,D6,ReadBit(CMD,6));
	DIO_SetPinValue(LCD_Data,D7,ReadBit(CMD,7));
	DIO_SetPinValue(LCD_Control,E,HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_Control,E,LOW);
	if(initdone){
		//Lower Nibble
		DIO_SetPinValue(LCD_Data,D4,ReadBit(CMD,0));
		DIO_SetPinValue(LCD_Data,D5,ReadBit(CMD,1));
		DIO_SetPinValue(LCD_Data,D6,ReadBit(CMD,2));
		DIO_SetPinValue(LCD_Data,D7,ReadBit(CMD,3));
		DIO_SetPinValue(LCD_Control,E,HIGH);
		_delay_ms(1);
		DIO_SetPinValue(LCD_Control,E,LOW);
	}
	_delay_ms(2);
}
void LCD_Print(uint8_t* Data)
{
	while(*Data!='\0')
	{
		LCD_SendData(*Data);
		Data++;
	}
}
void LCD_SetCursor(uint8_t row,uint8_t column)
{
	uint8_t Address=0;
	if (row<2	&&	column<16)
	{
		Address=(row*0x40)+column;
		Address=SetBit(Address,7);
		LCD_SendInstruction(Address);
	}
}
void LCD_Clear()
{
	LCD_SendInstruction(0x01);
}
void LCD_IntegerToString(uint16 data)
{
	uint8_t BUFF[16];
	itoa(data,BUFF,10); //Base 10
	LCD_Print(BUFF);
}
void LCD_StoreCutomChar(uint8_t* Pattern,uint8_t CGRAM_index)
{
	if (CGRAM_index<8)
	{
		LCD_SendInstruction((0x40)|(CGRAM_index*8));
		for (uint8_t index=0;index<8;index++)
		{
			LCD_SendData(Pattern[index]);
		}
	}
	LCD_SendInstruction(0x02); //return home
}
void LCD_DisplayCutomChar(uint8_t CGRAM_index)
{
	if (CGRAM_index<8)
	{
		LCD_SendData(CGRAM_index);
	}
}