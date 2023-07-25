/*
 * TestApp_Slave.c
 *
 * Created: 25/06/2023 10:25:07 م
 *  Author: The7ag
 */ 
/*Need to change the config for it*/
#include "SPI.h"
void SPI_Slave()
{
	uint8_t a;
	SPI_Initialize();
	DIO_SetPinDirection(PORTA,Pin0,Output);
	while(1)
	{
		a=SPI_DataReceived();
		if (a=='h')
		{
			DIO_SetPinValue(PORTA,Pin0,HIGH);
		}else
		{
			DIO_SetPinValue(PORTA,Pin0,LOW);
		}
	}
}