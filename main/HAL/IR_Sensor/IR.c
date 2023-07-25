/*
 * IR.c
 *
 * Created: 06/02/2023 02:39:19 ص
 *  Author: The7ag
 */ 
#include "IR.h"
void IR_Init(DIO_PORT_ID IR_Port,DIO_PIN_ID IR_Pin)
{
	DIO_SetPinDirection(IR_Port,IR_Pin,Input);
}
DIO_VALUE IR_Reading(DIO_PORT_ID IR_Port,DIO_PIN_ID IR_Pin)
{
	return DIO_GetPinValue(IR_Port,IR_Pin);
	
}
