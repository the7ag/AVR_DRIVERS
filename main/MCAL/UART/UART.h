/*
 * UART.h
 *
 * Created: 24/06/2023 09:29:58 م
 *  Author: The7ag
 */ 


#ifndef UART_H_
#define UART_H_
#include "UART_Reg.h"
#include "UART_Config.h"
#include "../DIO/DIO.h"
#include "../../UTIL/Algorithims/Algo.h"
#include <stdio.h>
#define F_CPU 8000000UL
#include "util/delay.h"
/* Initialize driver functionality */
void UART_Initialize(void);

/* Read data in UDR register, in case of receiving */
uint8_t UART_GetChar(void);

/* Write data in UDR register, in case of transmitting */
void UART_SendChar(uint8_t Data);

/* Send a Message */
void UART_SendMsg(uint8_t TxMsg[], uint8_t TxMsgSize);

/* Read a Message */
void UART_ReadMsg(uint8_t RxMsg[], uint8_t* RxMsgSize);

/* Functions to define interrupt functionality */
void UART_InterruptEnable(UART_Interrupt_Select_T Interrupt_Source);

void UART_InterruptDisable(UART_Interrupt_Select_T Interrupt_Source);
/* Send a Message */
void UART_SendMsg_NoINT(uint8_t TxMsg[], uint8_t TxMsgSize);
void UART_SendNumber(uint32 Number);
void UART_SendFloat(float64 Number);
void UART();
#endif /* UART_H_ */