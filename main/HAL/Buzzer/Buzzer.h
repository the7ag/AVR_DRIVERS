/*
 * Buzzer.h
 *
 * Created: 05/02/2023 10:19:53 م
 *  Author: The7ag
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_
#include "../../MCAL/DIO/DIO.h"
void BuzzerInit(DIO_PORT_ID BuzzerPort,DIO_PIN_ID BuzzerPin);
void Buzzer_TurnOn(DIO_PORT_ID BuzzerPort,DIO_PIN_ID BuzzerPin);
void Buzzer_TurnOff(DIO_PORT_ID BuzzerPort,DIO_PIN_ID BuzzerPin);
void Buzzer_Tune(DIO_PORT_ID BuzzerPort,DIO_PIN_ID BuzzerPin);


#endif /* BUZZER_H_ */