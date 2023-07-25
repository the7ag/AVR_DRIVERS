/*
 * DC_Motor.c
 *
 * Created: 06/02/2023 02:45:08 ص
 *  Author: The7ag
 */ 
#include "DC_Motor.h"
void DC_Motor_init(DIO_PORT_ID Motor_Port,DIO_PIN_ID Motor_Pin)
{
	DIO_SetPinDirection(Motor_Port,Motor_Pin,Output);
}
void DC_Motor_ON(DIO_PORT_ID Motor_Port,DIO_PIN_ID Motor_Pin)
{
	DIO_SetPinValue(Motor_Port,Motor_Pin,HIGH);
}
void DC_Motor_OFF(DIO_PORT_ID Motor_Port,DIO_PIN_ID Motor_Pin)
{
	DIO_SetPinValue(Motor_Port,Motor_Pin,LOW);
}