/*
 * UART_Config.h
 *
 * Created: 24/06/2023 09:29:46 م
 *  Author: The7ag
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
#include "UART_Types.h"


/*
 * MODE_SELECT options:
 *
 * UART_ASYNCHRONOUS
 * UART_SYNCHRONOUS
 *
 * */

#define UART_MODE_SELECT            UART_ASYNCHRONOUS
/*
 * Parity_Mode options:
 *
 * UART_PARITY_DISABLED
 * UART_PARITY_EVEN
 * UART_PARITY_ODD
 *
 * */

#define UART_PARITY_SELECT          UART_PARITY_DISABLED
/*
 * Stop_bit options:
 *
 * UART_STOP_BIT_ONE
 * UART_STOP_BIT_TWO
 *
 * */

#define UART_STOP_BIT_SELECT        UART_STOP_BIT_ONE
/*
 * Data_bits options:
 *
 * UART_DATA_BITS_FIVE
 * UART_DATA_BITS_SIX
 * UART_DATA_BITS_SEVEN
 * UART_DATA_BITS_EIGHT
 * UART_DATA_BITS_NINE
 *
 * */

#define UART_DATA_BITS_SELECT       UART_DATA_BITS_EIGHT
/*
 * Refer to DATA sheet Table 70-71 Page 167-168
 * For F_CPU 16MHz in Normal Mode:
 * Baud Rate = 4800   ==> UBRRL = 207
 * Baud Rate = 9600   ==> UBRRL = 103
 * Baud Rate = 57600  ==> UBRRL = 16
 * Baud Rate = 115200 ==> UBRRL = 8
  * For F_CPU 16MHz in Double Data Mode:
  * Baud Rate = 4800   ==> UBRRL = 416
  * Baud Rate = 9600   ==> UBRRL = 207
  * Baud Rate = 57600  ==> UBRRL = 34
  * Baud Rate = 115200 ==> UBRRL = 16
  
  * For F_CPU 8MHz in Normal Mode:
  * Baud Rate = 4800   ==> UBRRL = 103
  * Baud Rate = 9600   ==> UBRRL = 51
  * Baud Rate = 57600  ==> UBRRL = 8
  * Baud Rate = 115200 ==> UBRRL = 3
   * For F_CPU 8MHz in Double data Mode:
   * Baud Rate = 4800   ==> UBRRL = 207
   * Baud Rate = 9600   ==> UBRRL = 103
   * Baud Rate = 57600  ==> UBRRL = 16
   * Baud Rate = 115200 ==> UBRRL = 8
 * */

#define UART_BAUD_RATE_UBRR_VAL     51

#define UART_RX_BUFFER_SIZE         100
#define UART_TX_BUFFER_SIZE         100


#endif /* UART_CONFIG_H_ */