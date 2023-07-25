/*
 * LED.c
 *
 * Created: 02/02/2023 06:55:06 م
 *  Author: The7ag
 */ 
#include "LED.h"
void LED_Init(DIO_PORT_ID LED_PORT,DIO_PIN_ID LED_PIN)
{
	DIO_SetPinDirection(LED_PORT,LED_PIN,Output);
}
void LED_On(DIO_PORT_ID LED_PORT,DIO_PIN_ID LED_PIN)
{
	DIO_SetPinValue(LED_PORT,LED_PIN,HIGH);
}
void LED_Off(DIO_PORT_ID LED_PORT,DIO_PIN_ID LED_PIN)
{
	DIO_SetPinValue(LED_PORT,LED_PIN,LOW);
}
void LED_Toggle(DIO_PORT_ID LED_PORT,DIO_PIN_ID LED_PIN)
{
	DIO_TogglePinValue(LED_PORT,LED_PIN);
}