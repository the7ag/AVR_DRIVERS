﻿/*
 * DIO_REG.h
 *
 * Created: 01/02/2023 07:38:11 م
 *  Author: The7ag
 */ 


#ifndef DIO_REG_H_
#define DIO_REG_H_
#include "DIO.h"

#define DDRA_Reg	*((volatile uint8_t*) 0x3A)
#define PORTA_Reg	*((volatile uint8_t*) 0x3B)
#define PINA_Reg	*((volatile uint8_t*) 0x39)

#define DDRB_Reg	*((volatile uint8_t*) 0x37)
#define PORTB_Reg	*((volatile uint8_t*) 0x38)
#define PINB_Reg	*((volatile uint8_t*) 0x36)

#define DDRC_Reg	*((volatile uint8_t*) 0x34)
#define PORTC_Reg	*((volatile uint8_t*) 0x35)
#define PINC_Reg	*((volatile uint8_t*) 0x33)

#define DDRD_Reg	*((volatile uint8_t*) 0x31)
#define PORTD_Reg	*((volatile uint8_t*) 0x32)
#define PIND_Reg	*((volatile uint8_t*) 0x30)




#endif /* DIO_REG_H_ */