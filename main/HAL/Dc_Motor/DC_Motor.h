/*
 * DC_Motor.h
 *
 * Created: 06/02/2023 02:44:55 ص
 *  Author: The7ag
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "../../MCAL/DIO/DIO.h"
void DC_Motor_init(DIO_PORT_ID Motor_Port,DIO_PIN_ID Motor_Pin);
void DC_Motor_ON(DIO_PORT_ID Motor_Port,DIO_PIN_ID Motor_Pin);
void DC_Motor_OFF(DIO_PORT_ID Motor_Port,DIO_PIN_ID Motor_Pin);



#endif /* DC_MOTOR_H_ */