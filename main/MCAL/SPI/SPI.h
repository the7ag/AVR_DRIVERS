/*
 * SPI.h
 *
 * Created: 25/06/2023 08:00:34 م
 *  Author: The7ag
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "SPI_Reg.h"
#include "SPI_Config.h"

void SPI_Initialize(void);
void SPI_SendData(uint8_t Data);
void SPI_SendString(uint8_t* Str);
/*{
	uint8 result;
	DIO_SetPinValue(portID,PinID,STD_LOW);
	SPDR_Reg = Data;
	while(transmission complete);
	result = SPDR_Reg;
	DIO_SetPinValue(portID,PinID,STD_HIGH);
	return result;
}*/
uint8_t SPI_DataReceived(void);
void SPI_SetSlaveData(uint8_t Data);
void SPI();
void SPI_Slave();
#endif /* SPI_H_ */