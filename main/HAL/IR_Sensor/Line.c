/*
 * Line.c
 *
 * Created: 06/02/2023 02:44:16 ص
 *  Author: The7ag
 */ 
#include "IR.h"
#include "../Dc_Motor/DC_Motor.h"
void Forward();
void Backward();
void TurnRight();
void TurnLeft();
void All_Forward_Off();
void All_Backward_Off();
void Line_Following_Robot()
{
	IR_Init(PORTA,Pin5); //Left
	IR_Init(PORTA,Pin4); //Right
	DC_Motor_init(PORTA,Pin3); //L 1 F
	DC_Motor_init(PORTA,Pin2); //L 1 B
	DC_Motor_init(PORTA,Pin1); //L 2 F
	DC_Motor_init(PORTA,Pin0); //L 2 B
	DC_Motor_init(PORTD,Pin3); //R 1 F
	DC_Motor_init(PORTD,Pin2); //R 1 B
	DC_Motor_init(PORTD,Pin1); //R 2 F
	DC_Motor_init(PORTD,Pin0); //R 2 B
	while (1)
	{
		if (IR_Reading(PORTA,Pin5) == LOW && IR_Reading(PORTA,Pin4) == LOW)
		{
			Forward();
		}
		else if (IR_Reading(PORTA,Pin5) == HIGH && IR_Reading(PORTA,Pin4) == LOW)
		{
			TurnLeft();
		}
		else if (IR_Reading(PORTA,Pin5) == LOW && IR_Reading(PORTA,Pin4) == HIGH)
		{
			TurnRight();
		}
		else if (IR_Reading(PORTA,Pin5) == HIGH && IR_Reading(PORTA,Pin4) == HIGH)
		{
			Backward();
		}
	}
}
void Forward()
{
	All_Backward_Off();
	DC_Motor_ON(PORTA,Pin3); //L 1 F
	DC_Motor_ON(PORTA,Pin1); //L 2 F
	DC_Motor_ON(PORTD,Pin3); //R 1 F
	DC_Motor_ON(PORTD,Pin1); //R 2 F
}
void Backward()
{
	All_Forward_Off();
	DC_Motor_ON(PORTA,Pin2); //L 1 B
	DC_Motor_ON(PORTA,Pin0); //L 2 B
	DC_Motor_ON(PORTD,Pin2); //R 1 B
	DC_Motor_ON(PORTD,Pin0); //R 2 B
}
void TurnRight()
{
	All_Backward_Off();
	All_Forward_Off();
	DC_Motor_ON(PORTD,Pin2); //R 1 B
	DC_Motor_ON(PORTD,Pin0); //R 2 B
	DC_Motor_ON(PORTA,Pin3); //L 1 F
	DC_Motor_ON(PORTA,Pin1); //L 2 F
}
void TurnLeft()
{
	All_Backward_Off();
	All_Forward_Off();
	DC_Motor_ON(PORTA,Pin2); //L 1 B
	DC_Motor_ON(PORTA,Pin0); //L 2 B
	DC_Motor_ON(PORTD,Pin3); //R 1 F
	DC_Motor_ON(PORTD,Pin1); //R 2 F
}

void All_Forward_Off()
{
	DC_Motor_OFF(PORTA,Pin3); //L 1 F
	DC_Motor_OFF(PORTA,Pin1); //L 2 F
	DC_Motor_OFF(PORTD,Pin3); //R 1 F
	DC_Motor_OFF(PORTD,Pin1); //R 2 F
}
void All_Backward_Off()
{
	DC_Motor_OFF(PORTA,Pin2); //L 1 B
	DC_Motor_OFF(PORTA,Pin0); //L 2 B
	DC_Motor_OFF(PORTD,Pin2); //R 1 B
	DC_Motor_OFF(PORTD,Pin0); //R 2 B
}