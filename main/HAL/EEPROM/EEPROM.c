/*
 * EEPROM.c
 *
 * Created: 01/07/2023 06:14:30 م
 *  Author: The7ag
 */ 
#include "EEPROM.h"
void EEPROM_voidInit(void)
{
	TWI_voidMasterInit();
}
uint8_t	EEPROM_u8WriteDataByte(uint8_t Copy_u8Data,uint16 Copy_u16ByteAddress)
{
	uint8_t Local_u8ErrorState     = STD_TYPES_OK;
	TWI_ErrorState Local_enuTWIErrorState = TWI_OK;
	/* Start Condition */
	Local_enuTWIErrorState = TWI_enuSendStartCondition();
	Local_u8ErrorState     = Private_u8ErrorStateCheck(Local_enuTWIErrorState);
	/* Send Slave Address with Write Bit */
	Local_enuTWIErrorState = TWI_enuSendSlaveWithWrite((EEPROM_u8_FIXED_ADDRESS)|(EEPROM_u8_A2_VALUE<<2)|((uint8_t)(Copy_u16ByteAddress>>8)));
	Local_u8ErrorState     = Private_u8ErrorStateCheck(Local_enuTWIErrorState);
	/* Send The Rest Of The Byte Address */
	Local_enuTWIErrorState = TWI_enuSendDataByte((uint8_t)Copy_u16ByteAddress);
	Local_u8ErrorState     = Private_u8ErrorStateCheck(Local_enuTWIErrorState);
	/* Send The Data Byte */
	Local_enuTWIErrorState = TWI_enuSendDataByte((uint8_t)Copy_u8Data);
	Local_u8ErrorState     = Private_u8ErrorStateCheck(Local_enuTWIErrorState);
	/* Send Stop Condition */
	TWI_voidSendStopCondition();
	_delay_ms(5);
	return Local_u8ErrorState;
}
uint8_t	EEPROM_u8ReadDataByte(uint8_t * Copy_pu8ReceivedData ,uint16 Copy_u16ByteAddress )
{
	uint8_t Local_u8ErrorState = STD_TYPES_OK;
	TWI_ErrorState Local_enuTWIErrorState = TWI_OK;
	if(Copy_pu8ReceivedData != NULL)
	{
		uint8_t Local_u8EEPROMAddress = (EEPROM_u8_FIXED_ADDRESS)|(EEPROM_u8_A2_VALUE<<2)|((uint8_t)(Copy_u16ByteAddress>>8));
		/* Send Start Condition */
		Local_enuTWIErrorState = TWI_enuSendStartCondition();
		Local_u8ErrorState     = Private_u8ErrorStateCheck(Local_enuTWIErrorState);
		/* Send Slave Address with Write Bit */
		Local_enuTWIErrorState = TWI_enuSendSlaveWithWrite(Local_u8EEPROMAddress);
		Local_u8ErrorState     = Private_u8ErrorStateCheck(Local_enuTWIErrorState);
		/* Send The Rest Of The Byte Address */
		Local_enuTWIErrorState = TWI_enuSendDataByte((uint8_t)Copy_u16ByteAddress);
		Local_u8ErrorState     = Private_u8ErrorStateCheck(Local_enuTWIErrorState);
		/* Send Repeated Start Condition */
		Local_enuTWIErrorState = TWI_enuSendRepeatedStartCondition();
		Local_u8ErrorState     = Private_u8ErrorStateCheck(Local_enuTWIErrorState);
		/* Send Slave Address with Read Bit */
		Local_enuTWIErrorState = TWI_enuSendSlaveWithRead(Local_u8EEPROMAddress);
		Local_u8ErrorState     = Private_u8ErrorStateCheck(Local_enuTWIErrorState);
		/* Read Data */
		Local_enuTWIErrorState = TWI_enuReceiveDataByte(Copy_pu8ReceivedData);
		Local_u8ErrorState     = Private_u8ErrorStateCheck(Local_enuTWIErrorState);
		/* Send Stop Condition */
		TWI_voidSendStopCondition();
		_delay_ms(5);
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
static uint8_t   Private_u8ErrorStateCheck(TWI_ErrorState Copy_enuErrorState)
{
	uint8_t Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_enuErrorState != TWI_OK)
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}