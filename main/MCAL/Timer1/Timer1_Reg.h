/*
 * Timer1_Reg.h
 *
 * Created: 23/06/2023 04:15:26 م
 *  Author: The7ag
 */ 


#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

#include "../DIO/DIO.h"
#define TCCR1A_Reg  	(*((volatile uint8_t*)0x4F))
#define TCCR1B_Reg   	(*((volatile uint8_t*)0x4E))
#define TCNT1_Reg   	(*((volatile uint16*) 0x4C))
#define OCR1A_Reg   	(*((volatile uint16*)0x4A))
#define OCR1B_Reg   	(*((volatile uint16*)0x48))
#define ICR1A_Reg      	(*((volatile uint16*)0x46))
#define TIMSK_Reg	   	(*((volatile uint8_t*)0x59))



#endif /* TIMER1_REG_H_ */