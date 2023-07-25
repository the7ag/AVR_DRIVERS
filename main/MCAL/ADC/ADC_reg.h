/*
 * ADC_reg.h
 *
 * Created: 03/02/2023 10:04:30 م
 *  Author: The7ag
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_

#include "../DIO/DIO.h"
#define SFIOR_Reg	*((volatile uint8_t*)0x50)
#define ADMUX_Reg	*((volatile uint8_t*)0x27)
#define ADCSRA_Reg	*((volatile uint8_t*)0x26)
#define ADCH_Reg	*((volatile uint8_t*)0x25)
#define ADCL_Reg	*((volatile uint8_t*)0x24)
#define ADCLH_Reg	*((volatile uint16*)0x24)



#endif /* ADC_REG_H_ */