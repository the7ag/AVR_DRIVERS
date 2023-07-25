/*
 * LCD.h
 *
 * Created: 03/02/2023 03:39:23 م
 *  Author: The7ag
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../MCAL/DIO/DIO.h"
#define F_CPU 8000000UL
#include "util/delay.h"
void LCD_Init(DIO_PORT_ID LCD_Data_Port,DIO_PORT_ID LCD_Control_Port ,DIO_PIN_ID RS,DIO_PIN_ID E,DIO_PIN_ID D4,DIO_PIN_ID D5,DIO_PIN_ID D6,DIO_PIN_ID D7);
void LCD_SendInstruction(uint8_t CMD);
void LCD_SendData(uint8_t Data);
void LCD_Print(uint8_t* Data);
void LCD_SetCursor(uint8_t row,uint8_t column);
void LCD_Clear();
void LCD_StoreCutomChar(uint8_t* Pattern,uint8_t CGRAM_index);
void LCD_DisplayCutomChar(uint8_t CGRAM_index);
void LCD_IntegerToString(uint16 data);
void LCD();
void Calculator();

#endif /* LCD_H_ */