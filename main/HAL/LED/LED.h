/*
 * LED.h
 *
 * Created: 02/02/2023 06:52:13 م
 *  Author: The7ag
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"

void LED_Init(DIO_PORT_ID LED_PORT,DIO_PIN_ID LED_PIN);
void LED_On(DIO_PORT_ID LED_PORT,DIO_PIN_ID LED_PIN);
void LED_Off(DIO_PORT_ID LED_PORT,DIO_PIN_ID LED_PIN);
void LED_Toggle(DIO_PORT_ID LED_PORT,DIO_PIN_ID LED_PIN);

#endif /* LED_H_ */