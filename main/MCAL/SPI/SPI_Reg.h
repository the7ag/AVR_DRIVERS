/*
 * SPI_Reg.h
 *
 * Created: 25/06/2023 08:00:05 م
 *  Author: The7ag
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_
#include "../DIO/DIO.h"

#define  SPCR_Reg           (*((volatile uint8_t*) 0x2D))
#define  SPSR_Reg           (*((volatile uint8_t*) 0x2E))
#define  SPDR_Reg         	(*((volatile uint8_t*) 0x2F))


#endif /* SPI_REG_H_ */