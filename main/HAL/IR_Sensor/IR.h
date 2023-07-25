/*
 * IR.h
 *
 * Created: 06/02/2023 02:39:09 ص
 *  Author: The7ag
 */ 


#ifndef IR_H_
#define IR_H_
#include "../../MCAL/DIO/DIO.h"
void IR_Init(DIO_PORT_ID IR_Port,DIO_PIN_ID IR_Pin);
DIO_VALUE IR_Reading(DIO_PORT_ID IR_Port,DIO_PIN_ID IR_Pin);
void Line_Following_Robot();

#endif /* IR_H_ */