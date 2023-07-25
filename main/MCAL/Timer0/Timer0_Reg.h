/*
 * Timer0_Reg.h
 *
 * Created: 07/02/2023 02:15:16 م
 *  Author: The7ag
 */ 


#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_

#include "../DIO/DIO.h"
#define OCR0_Reg	(*((volatile uint8_t*)0x5C))
#define TIFR_Reg	(*((volatile uint8_t*)0x58))
#define TCCR0_Reg	(*((volatile uint8_t*) 0x53))
#define TCNT0_Reg	(*((volatile uint8_t*)0x52))
#define TIMSK_Reg	(*((volatile uint8_t*)0x59))



#endif /* TIMER0_REG_H_ */