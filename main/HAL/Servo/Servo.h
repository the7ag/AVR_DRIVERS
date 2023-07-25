/*
 * Servo.h
 *
 * Created: 23/06/2023 04:54:42 م
 *  Author: The7ag
 */ 


#ifndef SERVO_H_
#define SERVO_H_
#include "../../MCAL/Timer1/Timer1.h"
#include "../../MCAL/DIO/DIO.h"
#define F_CPU 8000000UL
#include "util/delay.h"
void Servo_Init(void);
void Servo_Write(uint8_t angle);
void testServo(void);

#endif /* SERVO_H_ */