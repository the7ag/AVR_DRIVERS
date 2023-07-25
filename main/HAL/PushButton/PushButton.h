/*
 * PushButton.h
 *
 * Created: 02/02/2023 07:02:25 م
 *  Author: The7ag
 */ 


#ifndef PUSHBUTTON_H_
#define PUSHBUTTON_H_
#include "../../MCAL/DIO/DIO.h"

void ButtonInit(DIO_PORT_ID Button_Port,DIO_PIN_ID Button_PIN);
DIO_VALUE ReadButton(DIO_PORT_ID Button_Port,DIO_PIN_ID Button_PIN);


#endif /* PUSHBUTTON_H_ */