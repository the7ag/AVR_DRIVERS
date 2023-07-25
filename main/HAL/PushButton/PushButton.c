/*
 * PushButton.c
 *
 * Created: 02/02/2023 07:02:37 م
 *  Author: The7ag
 */ 
#include "PushButton.h"
void ButtonInit(DIO_PORT_ID Button_Port,DIO_PIN_ID Button_PIN){
	DIO_SetPinDirection(Button_Port,Button_PIN,Input);
}
DIO_VALUE ReadButton(DIO_PORT_ID Button_Port,DIO_PIN_ID Button_PIN)
{
	DIO_VALUE Reading=DIO_GetPinValue(Button_Port,Button_PIN);
	return Reading;
}