/*
 * UART_Types.h
 *
 * Created: 24/06/2023 09:29:05 م
 *  Author: The7ag
 */ 


#ifndef UART_TYPES_H_
#define UART_TYPES_H_


#define  UART_ASYNCHRONOUS        0b00000000      //0x00
#define  UART_SYNCHRONOUS         0b01000000      //0x40

#define  UART_PARITY_DISABLED     0b00000000      //0x00
#define  UART_PARITY_EVEN         0b00100000      //0x20
#define  UART_PARITY_ODD          0b00110000      //0x30

#define  UART_STOP_BIT_ONE        0b00000000      //0x00
#define  UART_STOP_BIT_TWO        0b00001000      //0x08

#define  UART_DATA_BITS_FIVE      0b00000000      //0x00
#define  UART_DATA_BITS_SIX       0b00000010      //0x02
#define  UART_DATA_BITS_SEVEN     0b00000100      //0x04
#define  UART_DATA_BITS_EIGHT     0b00000110      //0x06
#define  UART_DATA_BITS_NINE      0b11111111      //0xFF

typedef enum
{
	UART_Receive_Complete_Int,
	UART_Data_Register_Empty_Int,
	UART_Transmit_Complete_Int
} UART_Interrupt_Select_T ;
#endif /* UART_TYPES_H_ */