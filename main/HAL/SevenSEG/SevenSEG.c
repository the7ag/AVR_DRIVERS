/*
 * _7SEG.c
 *
 * Created: 02/02/2023 09:27:21 م
 *  Author: The7ag
 */ 
#include "SevenSEG.h"
void Seven_Init(DIO_PORT_ID Seven_Port,DIO_PIN_ID Start_Pin,DIO_PORT_ID Enble_Port,DIO_PIN_ID Enable_Pin)
{
for (uint32 i=0;i<4;i++)
{
	DIO_SetPinDirection(Seven_Port,Start_Pin+i,Output);
}
DIO_SetPinDirection(Enble_Port,Enable_Pin,Output);
}
void Seven_On(DIO_PORT_ID Enable_Port,DIO_PIN_ID Enable_Pin)
{
	DIO_SetPinValue(Enable_Port,Enable_Pin,HIGH);
}
void Seven_Off(DIO_PORT_ID Enable_Port,DIO_PIN_ID Enable_Pin)
{
	DIO_SetPinValue(Enable_Port,Enable_Pin,LOW);
}
/*void Seven_SendNumber(DIO_PORT_ID Seven_Port,DIO_PIN_ID Start_Pin,uint8_t number)
{
	if (number>=0	&&	number<10)
	{
		switch(Seven_Port)
		{
			case PORTA:PORTA_Reg=number; break;
			case PORTB:PORTB_Reg=number; break;
			case PORTC:PORTC_Reg=number; break;
			case PORTD:PORTD_Reg=number; break;
		}
	}
}*/
void Seven_SendLights(DIO_PORT_ID Seven_Port,DIO_PIN_ID Start_Pin,uint8_t A,uint8_t B,uint8_t C,uint8_t D,uint8_t E,uint8_t F,uint8_t G)
{
	DIO_SetPinValue(Seven_Port,Start_Pin,A);
	DIO_SetPinValue(Seven_Port,Start_Pin+1,B);
	DIO_SetPinValue(Seven_Port,Start_Pin+2,C);
	DIO_SetPinValue(Seven_Port,Start_Pin+3,D);
	DIO_SetPinValue(Seven_Port,Start_Pin+4,E);
	DIO_SetPinValue(Seven_Port,Start_Pin+5,F);
	DIO_SetPinValue(Seven_Port,Start_Pin+6,G);
}