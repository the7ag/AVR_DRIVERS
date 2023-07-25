/*
 * Buzzer.c
 *
 * Created: 05/02/2023 10:19:44 م
 *  Author: The7ag
 */ 
#include "Buzzer.h"
void BuzzerInit(DIO_PORT_ID BuzzerPort,DIO_PIN_ID BuzzerPin)
{
	DIO_SetPinDirection(BuzzerPort,BuzzerPin,Output);
}
void Buzzer_TurnOn(DIO_PORT_ID BuzzerPort,DIO_PIN_ID BuzzerPin)
{
	DIO_SetPinValue(BuzzerPort,BuzzerPin,HIGH);
}
void Buzzer_TurnOff(DIO_PORT_ID BuzzerPort,DIO_PIN_ID BuzzerPin)
{
		DIO_SetPinValue(BuzzerPort,BuzzerPin,LOW);
}
void Buzzer_Tune(DIO_PORT_ID BuzzerPort,DIO_PIN_ID BuzzerPin)
{
	
}