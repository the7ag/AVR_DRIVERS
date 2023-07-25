/*
 * ADC.h
 *
 * Created: 03/02/2023 10:03:15 م
 *  Author: The7ag
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "../DIO/DIO.h"
#include "ADC_reg.h"
#include "ADC_types.h"
#include "ADC_config.h"
typedef enum {
	ADC_Channel_0,
	ADC_Channel_1,
	ADC_Channel_2,
	ADC_Channel_3,
	ADC_Channel_4,
	ADC_Channel_5,
	ADC_Channel_6,
	ADC_Channel_7
}ADC_Channel_types;
void ADC();
void ADC2();

void ADC_Init();
void ADC_StartConversion(ADC_Channel_types Channel);
uint16 ADC_GetResult();
uint16 analogRead(ADC_Channel_types Channel);
/*Enable*/
void ADC_INT_Enable();
/*Disable */
void ADC_INT_Disable();
/*CallBack Functions*/
void ADC_INT_SetCallback(void (*CopyFuncPtr) (void));

#endif /* ADC_H_ */