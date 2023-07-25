/*
 * DIO.h
 *
 * Created: 01/02/2023 07:06:45 م
 *  Author: The7ag
 */ 
#include "DIO_Types.h"
#include "../../UTIL/STD_Types.h"
#include "../../UTIL/BitMath.h"
#include "DIO_REG.h"

#ifndef DIO_H_
#define DIO_H_

void DIO_SetPortDirection(DIO_PORT_ID port_name,DIO_DIRECTION direction);

void DIO_SetPortValue(DIO_PORT_ID port_name,uint8_t value);

void DIO_SetPinDirection(DIO_PORT_ID port_name,DIO_PIN_ID pin_name,DIO_DIRECTION direction);

void DIO_SetPinValue(DIO_PORT_ID port_name,DIO_PIN_ID pin_name,DIO_VALUE value);
void DIO_TogglePinValue(DIO_PORT_ID port_name,DIO_PIN_ID pin_name);

DIO_VALUE DIO_GetPinValue(DIO_PORT_ID port_name,DIO_PIN_ID pin_name);

#endif /* DIO_H_ */