/*
 * UART_Reg.h
 *
 * Created: 24/06/2023 09:29:34 م
 *  Author: The7ag
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_
#include "../DIO/DIO.h"

#define  UDR_Reg           *((volatile uint8_t*) 0x2C)
#define  UCSRA_Reg         *((volatile uint8_t*) 0x2B)
#define  UCSRB_Reg         *((volatile uint8_t*) 0x2A)
#define  UCSRC_Reg         *((volatile uint8_t*) 0x40)
#define  UBRRL_Reg         *((volatile uint8_t*) 0x29)
#define  UBRRH_Reg         *((volatile uint8_t*) 0x40)


#endif /* UART_REG_H_ */