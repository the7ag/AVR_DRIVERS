/*
 * Servo.c
 *
 * Created: 23/06/2023 04:54:54 م
 *  Author: The7ag
 */ 
#include "Servo.h"

void Servo_Init(void)
{
	DIO_SetPinDirection(PORTD,Pin5,Output); /*OC1A*/
	TIMER1_INIT();
	TIMER1_ICR1A_Reg(19999); //for 50 Hz for the servo motor;
	Set_Duty_Cycle_TIMER_1_A(5);
	_delay_ms(100);
}
void Servo_Write(uint8_t angle)
{
if (angle<=180 && angle>=0)
{
	float32 duty=(((angle/180.0)+1)/20.0)*100;
	Set_Duty_Cycle_TIMER_1_A(duty);
}
}