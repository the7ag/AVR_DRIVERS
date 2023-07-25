/*
 * _7SEG.h
 *
 * Created: 02/02/2023 09:27:10 م
 *  Author: The7ag
 */ 


#ifndef SevenSEG_H_
#define SevenSEG_H_
#include "../../MCAL/DIO/DIO.h"
void Seven_Init(DIO_PORT_ID Seven_Port,DIO_PIN_ID Start_Pin,DIO_PORT_ID Enble_Port,DIO_PIN_ID Enable_Pin);
void Seven_On(DIO_PORT_ID Enable_Port,DIO_PIN_ID Enable_Pin);
void Seven_Off(DIO_PORT_ID Enable_Port,DIO_PIN_ID Enable_Pin);
void Seven_SendNumber(DIO_PORT_ID Seven_Port,DIO_PIN_ID Start_Pin,uint8_t number);
void Seven_SendLights(DIO_PORT_ID Seven_Port,DIO_PIN_ID Start_Pin,uint8_t A,uint8_t B,uint8_t C,uint8_t D,uint8_t E,uint8_t F,uint8_t G);
#endif /* SevenSEG_H_ */