/*
 * SPI.c
 *
 * Created: 25/06/2023 08:00:42 م
 *  Author: The7ag
 */ 
#include "SPI.h"

void SPI_Initialize(void)
{
	/*to clear all bit
	 * and set bit 7 to enable SPI Interrupt
	*/
	SPCR_Reg = 0x00;
	SPDR_Reg = 0x00;
#if (SPI_DATA_ORDER == SPI_MSB_FIRST)
	SPCR_Reg |= SPI_MSB_FIRST;
#elif( SPI_LSB_FIRST == SPI_LSB_FIRST )
	 SPCR_Reg |= SPI_LSB_FIRST;
#endif
#if ( SPI_MASTER_SLAVE_SELECT == SPI_MASTER)
	 DIO_SetPinDirection(PORTB , Pin5 ,Output); // if it master (Send Data)				 //pin5 MOSI
	 DIO_SetPinDirection(PORTB , Pin6 ,Input); //input signal from slave				 //pin6 MISO
	 DIO_SetPinDirection(PORTB , Pin4 ,Output); // SS output to slave					 //pin4	SS
	 DIO_SetPinDirection(PORTB , Pin7 ,Output); //clock generate from master to slave	 //pin7	SCK
	 DIO_SetPinValue(PORTB , Pin4 ,HIGH);  // SS HIGH
	#if ( SPI_CLK_PHASE_SELECT == SPI_CLK_PRESCALER_4)
		 SPCR_Reg |= SPI_CLK_PRESCALER_4;
	#elif( SPI_CLK_PHASE_SELECT == SPI_CLK_PRESCALER_16 )
		 SPCR_Reg |= SPI_CLK_PRESCALER_16;
	#elif( SPI_CLK_PHASE_SELECT == SPI_CLK_PRESCALER_64 )
		 SPCR_Reg |= SPI_CLK_PRESCALER_64;
	#elif( SPI_CLK_PHASE_SELECT ==  SPI_CLK_PRESCALER_128)
		 SPCR_Reg |= SPI_CLK_PRESCALER_128;
	#endif
	#if ( SPI_CLK_SPEED_SELECT == SPI_CLK_NORMAL_SPEED)
		 SPCR_Reg |= SPI_CLK_NORMAL_SPEED;
	#elif( SPI_CLK_SPEED_SELECT == SPI_CLK_DOUBLE_SPEED )
		 SPCR_Reg |= SPI_CLK_DOUBLE_SPEED;
	#endif
		 SPCR_Reg |= SPI_MASTER ;
#elif( SPI_MASTER_SLAVE_SELECT ==  SPI_SLAVE)
	 DIO_SetPinDirection(PORTB , Pin5 ,Input); // input signal from MASTER	 			 //pin5 MOSI
	 DIO_SetPinDirection(PORTB , Pin6 ,Output); //if it Slave (Send Data)				 //pin6 MISO
	 DIO_SetPinDirection(PORTB , Pin4 ,Input); // SS Input from master					 //pin4	SS
	 DIO_SetPinDirection(PORTB , Pin7 ,Input); //clock generate from master to slave	 //pin7	SCK
	 SPCR_Reg |= SPI_SLAVE;
	 //SPDR_Reg = 0b00110100;
#endif
#if (SPI_CLK_POLARITY_SELECT == SPI_CLK_POL_RISING)
	 SPCR_Reg |=SPI_CLK_POL_RISING ;
#elif(SPI_CLK_POLARITY_SELECT == SPI_CLK_POL_FALLING )
	 SPCR_Reg |= SPI_CLK_POL_FALLING;
#endif
#if (SPI_CLK_PHA_SELECT == SPI_CLK_PHASE_SETUP_FIRST)
	 SPCR_Reg |= SPI_CLK_PHASE_SETUP_FIRST;
#elif( SPI_CLK_PHA_SELECT == SPI_CLK_PHASE_SAMPLE_FIRST )
	 SPCR_Reg |= SPI_CLK_PHASE_SAMPLE_FIRST;
#endif
	 SetBit(SPCR_Reg , 6);
}
void SPI_SendData(uint8_t Data)
{
	//uint8_t flush_buffer;
	SPDR_Reg = Data ;
	//DIO_SetPinValue(PORTB , Pin4 ,LOW);  // SS LOW
	/* Wait for transmission complete */
	while(ReadBit(SPSR_Reg , 7 ) != 1 );
	//DIO_SetPinValue(PORTB , Pin4 ,HIGH);  // SS HIGH
	//flush_buffer = SPDR_Reg;
	 /* Note: SPIF flag is cleared by first reading SPSR (with SPIF set) and
	   then accessing SPDR hence flush buffer used here to access SPDR after SPSR read
	  */
	//return SPDR_Reg;
}
void SPI_SendString( uint8_t* Str)
{
	//uint8_t flush_buffer 
	uint8_t index = 0;
	while(Str[index] != '\0')
	{
	SPDR_Reg = Str[index] ;
	//DIO_SetPinValue(PORTB , Pin4 ,LOW);  // SS LOW
	/* Wait for transmission complete */
	while(ReadBit(SPSR_Reg , 7 ) != 1 );
	//DIO_SetPinValue(PORTB , Pin4 ,HIGH);  // SS HIGH
	// flush_buffer = SPDR_Reg;
	 /* Note: SPIF flag is cleared by first reading SPSR (with SPIF set) and
	   then accessing SPDR hence flush buffer used here to access SPDR after SPSR read
	  */
	 index++;
	 //_delay_ms(2000);
	}
	//return SPDR_Reg;
}
uint8_t SPI_DataReceived()
{
	/* Wait for transmission complete */
	while(ReadBit(SPSR_Reg , 7 ) != 1 );
	return SPDR_Reg;
}
void SPI_SetSlaveData(uint8_t Data)
{
	SPDR_Reg = Data;
}