/*
 * Testapp.c
 *
 * Created: 23/06/2023 06:39:29 م
 *  Author: The7ag
 */ 
#include "Servo.h"
void testServo(void)
{
	Servo_Init();
	while(1)
	{
		Servo_Write(45);
		_delay_ms(1000);
		Servo_Write(90);
		_delay_ms(1000);
		Servo_Write(180);
		_delay_ms(1000);
		Servo_Write(0);
		_delay_ms(1000);
	}
}
