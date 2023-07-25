/*
 * TestApp2.c
 *
 * Created: 06/02/2023 03:49:50 م
 *  Author: The7ag
 */ 
#include "ADC.h"
#include "../../HAL/PushButton/PushButton.h"
#include "../../HAL/LCD/LCD.h"
#include "../Global_INT/Global_INT.h"
#define F_CPU 1000000UL
#include <UTIL/delay.h>
//POT Channel 1
//LCD PORTA,PORTB,Pin0,Pin1,Pin3,Pin2,Pin1,Pin0
void ADC_Conversion_Compelete()
{
	uint16 val=ADC_GetResult();
	LCD_SetCursor(0,6);
	LCD_IntegerToString(val);
}
void ADC2()
{
	/*LCD Init*/
	LCD_Init(PORTA,PORTA,Pin7,Pin6,Pin5,Pin4,Pin3,Pin2);
	/*ADC init*/
	DIO_SetPinDirection(PORTA,Pin1,Input);
	ADC_Init();
	LCD_Print("Value:");
	Global_INT_Enable();
	ADC_INT_Enable();
	ADC_INT_SetCallback(ADC_Conversion_Compelete);
	ADC_StartConversion(ADC_Channel_1);
	while(1)
	{
	}
}