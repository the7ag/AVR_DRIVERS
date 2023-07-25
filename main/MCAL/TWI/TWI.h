/*
 * TWI.h
 *
 * Created: 26/06/2023 06:35:17 م
 *  Author: The7ag
 */ 


#ifndef TWI_H_
#define TWI_H_
#include "TWI_Config.h"
#include "TWI_Reg.h"
/**
/* Initialize driver functionality 
void TWI_Initialize(void);

/* Enable TWI interrupt 
void TWI_InterruptEnable(void);

/* Disable TWI interrupt 
void TWI_InterruptDisable(void);

/* Enable Acknowledgment 
void TWI_AckEnable(void);

/* Disable Acknowledgment 
void TWI_AckDisable(void);

/* Generate a start condition 
void TWI_GenerateStartCondition(void);

/* Clear start condition 
void TWI_ClearStartCondition(void);

/* Generate a stop condition 
void TWI_GenerateStopCondition(void);

/* Send one byte of data 
void TWI_SendData(uint8_t Data);

/* Read one byte of data 
void TWI_ReadData(uint8_t* Data);

/* Get the current bus status 
uint8_t TWI_GetStatus(void);

/* Clear the interrupt flag 
void TWI_ClearInterruptFlag(void);

/* Send a message 
uint8_t TWI_SendMsg(uint8_t SlaveAddress, uint8_t TxMsg[], uint8_t TxMsgSize);

/* Start reading operation 
void TWI_StartReading(uint8_t SlaveAddress, uint8_t SizeCpy);

/* Get last received message 
uint8_t TWI_GetLastRxMsg(uint8_t RxMsg[], uint8_t* RxMsgSize);
*/
void TWI();
void TWI_voidMasterInit(void);

void TWI_u8SlaveInit(uint8_t Copy_u8SlaveAddress);

TWI_ErrorState   TWI_enuSendStartCondition(void);

TWI_ErrorState   TWI_enuSendRepeatedStartCondition(void);

TWI_ErrorState   TWI_enuSendSlaveWithWrite(uint8_t Copy_u8SlaveAddress);

TWI_ErrorState   TWI_enuSendSlaveWithRead(uint8_t Copy_u8SlaveAddress);

TWI_ErrorState   TWI_enuSendDataByte(uint8_t Copy_u8Data);

TWI_ErrorState   TWI_enuReceiveDataByte(uint8_t * Copy_pu8ReceivedData);

void TWI_voidSendStopCondition(void);
#endif /* TWI_H_ */