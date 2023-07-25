/*
 * EEPROM.h
 *
 * Created: 01/07/2023 06:10:30 م
 *  Author: The7ag
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "EEPROM_Config.h"
#include "EEPROM_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TWI/TWI.h"
#define  F_CPU 8000000UL
#include "util/delay.h"

void			 EEPROM_voidInit(void);
uint8_t			 EEPROM_u8WriteDataByte(uint8_t Copy_u8Data,uint16 Copy_u16ByteAddress);
uint8_t			 EEPROM_u8ReadDataByte(uint8_t * Copy_pu8ReceivedData ,uint16 Copy_u16ByteAddress );
static uint8_t   Private_u8ErrorStateCheck(TWI_ErrorState Copy_enuErrorState);
void EEPROM();

#endif /* EEPROM_H_ */