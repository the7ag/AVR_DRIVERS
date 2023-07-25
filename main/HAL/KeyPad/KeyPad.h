/*
 * KeyPad.h
 *
 * Created: 12/02/2023 02:56:25 ص
 *  Author: The7ag
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 8000000UL
#include "../../MCAL/DIO/DIO.h"
#include "util/delay.h"
#define Number_Of_Columns 4
#define Number_Of_Rows 4

void Keypad_Init(DIO_PORT_ID Keypad_Port,DIO_PIN_ID A,DIO_PIN_ID B,DIO_PIN_ID C,DIO_PIN_ID D,DIO_PIN_ID one,DIO_PIN_ID two,DIO_PIN_ID three,DIO_PIN_ID four);
uint8_t Read_Keypad();
void KeyPad();

#endif /* KEYPAD_H_ */