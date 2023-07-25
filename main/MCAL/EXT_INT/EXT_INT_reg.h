/*
 * EXT_INT_reg.h
 *
 * Created: 04/02/2023 11:09:53 م
 *  Author: The7ag
 */ 


#ifndef EXT_INT_REG_H_
#define EXT_INT_REG_H_
#include "../DIO/DIO.h"
#include "../Global_INT/Global_INT.h"
#define MCUCR_Reg			(*((volatile uint8_t*) 0x55))
#define MCUCSR_Reg			(*((volatile uint8_t*) 0x54))
#define GICR_Reg			(*((volatile uint8_t*) 0x5B))
#define GIFR_Reg			(*((volatile uint8_t*) 0x5A))



#endif /* EXT_INT_REG_H_ */