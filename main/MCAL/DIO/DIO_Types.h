/*
 * DIO_Types.h
 *
 * Created: 01/02/2023 07:14:33 م
 *  Author: The7ag
 */ 


#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_
typedef enum {
	Input, //0
	Output //1
	}DIO_DIRECTION;

typedef enum {
	PORTA, //0
	PORTB, //1
	PORTC, //2
	PORTD  //3
	}DIO_PORT_ID;
typedef enum {
	LOW, //0
	HIGH //1
	}DIO_VALUE;
typedef enum{
	Pin0, //0
	Pin1, //1
	Pin2, //2
	Pin3, //3
	Pin4, //4
	Pin5, //5
	Pin6, //6
	Pin7 //7
	}DIO_PIN_ID;
typedef unsigned char uint8_t;

#endif /* DIO_TYPES_H_ */