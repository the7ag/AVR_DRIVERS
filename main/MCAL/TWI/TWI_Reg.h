/*
 * TWI_Reg.h
 *
 * Created: 26/06/2023 06:34:46 م
 *  Author: The7ag
 */ 


#ifndef TWI_REG_H_
#define TWI_REG_H_
#include "../DIO/DIO.h"
#define  TWBR_Reg           *((volatile uint8_t*) 0x20)
#define  TWCR_Reg           *((volatile uint8_t*) 0x56)
#define  TWSR_Reg         	*((volatile uint8_t*) 0x21)
#define  TWDR_Reg         	*((volatile uint8_t*) 0x23)
#define  TWAR_Reg         	*((volatile uint8_t*) 0x22)


#endif /* TWI_REG_H_ */