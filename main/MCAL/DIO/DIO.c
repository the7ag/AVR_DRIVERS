﻿/*
 * DIO.c
 *
 * Created: 01/02/2023 07:09:43 م
 *  Author: The7ag
 */ 
#include "DIO.h"
#include "DIO_REG.h"
void DIO_SetPortDirection(DIO_PORT_ID port_name,DIO_DIRECTION direction)
{
	if (direction==Output)
	{
		switch(port_name)
		{
			case PORTA:DDRA_Reg=0xff;break;
			case PORTB:DDRB_Reg=0xff; ;break;
			case PORTC:DDRC_Reg=0xff; ;break;
			case PORTD:DDRD_Reg=0xff; ;break;

		}
	}else if (direction==Input)
	{
		switch(port_name)
		{
			case PORTA:DDRA_Reg=0x00;break;
			case PORTB:DDRB_Reg=0x00; ;break;
			case PORTC:DDRC_Reg=0x00; ;break;
			case PORTD:DDRD_Reg=0x00; ;break;

		}
	}
}

void DIO_SetPortValue(DIO_PORT_ID port_name,uint8_t value)
{
	switch(port_name)
	{
		case PORTA: PORTA_Reg=value;break;
		case PORTB: PORTB_Reg=value;break;
		case PORTC: PORTC_Reg=value;break;
		case PORTD: PORTD_Reg=value;break;

	}
}

void DIO_SetPinDirection(DIO_PORT_ID port_name,DIO_PIN_ID pin_name,DIO_DIRECTION direction)
{
if (port_name<=PORTD	&&	port_name>=PORTA	&&	pin_name<=Pin7	&& pin_name>=Pin0)
{
	if (direction==Output)
	{
		switch(port_name)
		{
			case PORTA:	SetBit(DDRA_Reg,pin_name) ;break;
			case PORTB: SetBit(DDRB_Reg,pin_name) ;break;
			case PORTC: SetBit(DDRC_Reg,pin_name) ;break;
			case PORTD: SetBit(DDRD_Reg,pin_name) ;break;

		}
	}else if (direction==Input)
	{
		switch(port_name)
		{
			case PORTA:	ClearBit(DDRA_Reg,pin_name) ;break;
			case PORTB: ClearBit(DDRB_Reg,pin_name) ;break;
			case PORTC: ClearBit(DDRC_Reg,pin_name) ;break;
			case PORTD: ClearBit(DDRD_Reg,pin_name) ;break;
		}
	}
}
	
}

void DIO_SetPinValue(DIO_PORT_ID port_name,DIO_PIN_ID pin_name,DIO_VALUE value){
	if (port_name<=PORTD	&&	port_name>=PORTA	&&	pin_name<=Pin7	&& pin_name>=Pin0)
	{
		if (value==HIGH)
		{
			switch(port_name)
			{
				case PORTA:	SetBit(PORTA_Reg,pin_name) ;break;
				case PORTB: SetBit(PORTB_Reg,pin_name) ;break;
				case PORTC: SetBit(PORTC_Reg,pin_name) ;break;
				case PORTD: SetBit(PORTD_Reg,pin_name) ;break;

			}
		}else if (value==LOW)
		{
			switch(port_name)
			{
				case PORTA:	ClearBit(PORTA_Reg,pin_name) ;break;
				case PORTB: ClearBit(PORTB_Reg,pin_name) ;break;
				case PORTC: ClearBit(PORTC_Reg,pin_name) ;break;
				case PORTD: ClearBit(PORTD_Reg,pin_name) ;break;
			}
		}
	}
}
void DIO_TogglePinValue(DIO_PORT_ID port_name,DIO_PIN_ID pin_name){
	if (port_name<=PORTD	&&	port_name>=PORTA	&&	pin_name<=Pin7	&& pin_name>=Pin0)
	{
		switch(port_name)
		{
			case PORTA:	ToggleBit(PORTA_Reg,pin_name) ;break;
			case PORTB: ToggleBit(PORTB_Reg,pin_name) ;break;
			case PORTC: ToggleBit(PORTC_Reg,pin_name) ;break;
			case PORTD: ToggleBit(PORTD_Reg,pin_name) ;break;
		}
	}
}

DIO_VALUE DIO_GetPinValue(DIO_PORT_ID port_name,DIO_PIN_ID pin_name)
{
	DIO_VALUE Pin_Value=0;
	if (port_name<=PORTD	&&	port_name>=PORTA	&&	pin_name<=Pin7	&& pin_name>=Pin0)
	{
		switch(port_name)
		{
			case PORTA:	Pin_Value=ReadBit(PINA_Reg,pin_name); break;
			case PORTB: Pin_Value=ReadBit(PINB_Reg,pin_name); break;
			case PORTC: Pin_Value=ReadBit(PINC_Reg,pin_name); break;
			case PORTD: Pin_Value=ReadBit(PIND_Reg,pin_name); break;
		}
	}
	return Pin_Value;
}