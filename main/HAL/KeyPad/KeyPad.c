/*
 * KeyPad.c
 *
 * Created: 12/02/2023 02:56:36 ص
 *  Author: The7ag
 */ 
#include "KeyPad.h"
static DIO_PORT_ID Keypad_PORT;
static DIO_PIN_ID Keypad_Columns[Number_Of_Columns], Keypad_Rows[Number_Of_Rows]; //KeyPad Prep
uint8_t KeyBoard[Number_Of_Columns][Number_Of_Rows]={{'7','8','9','/'},
													{ '4','5','6','*'},
													{ '1','2','3','-'},
													{ 'O','0','=','+'}}; /*Change it Based On Your KeyPad*/
void Keypad_Init(DIO_PORT_ID Keypad_Port,DIO_PIN_ID A,DIO_PIN_ID B,DIO_PIN_ID C,DIO_PIN_ID D,DIO_PIN_ID one,DIO_PIN_ID two,DIO_PIN_ID three,DIO_PIN_ID four)
{
	/*Make A copy Of the init Keypad*/
	Keypad_PORT=Keypad_Port;
	Keypad_Rows[0]=A;
	Keypad_Rows[1]=B;
	Keypad_Rows[2]=C;
	Keypad_Rows[3]=D;
	Keypad_Columns[0]=one;
	Keypad_Columns[1]=two;
	Keypad_Columns[2]=three;
	Keypad_Columns[3]=four;
	/*Set the Rows as output and the columns as input pullup*/
	for (uint8_t i = 0; i<4 ; i++)
	{
		DIO_SetPinDirection(Keypad_Port,Keypad_Rows[i],Output);
		DIO_SetPinDirection(Keypad_Port,Keypad_Columns[i],Input);
		DIO_SetPinValue(Keypad_Port,Keypad_Columns[i],HIGH); // Enable PullUp
	}
}
uint8_t Read_Keypad()
{
	/*Stay in the while until a key has been pressed*/
	while(1)
	{
		for (uint8_t i=0; i<Number_Of_Rows ; i++)
		{
			DIO_SetPinValue(Keypad_PORT,Keypad_Rows[i],HIGH); /*Make all the rows high first*/
		}
		for (uint8_t i = 0 ; i<Number_Of_Rows;i++)
		{ 
			/*Go through Every Row make it Low*/
			DIO_SetPinValue(Keypad_PORT,Keypad_Rows[i],LOW);
			for (uint8_t j=0 ; j<Number_Of_Columns ;j++)
			{
				/*Check every Column if it reads 0*/
				if (DIO_GetPinValue(Keypad_PORT,Keypad_Columns[j])== LOW)
				{
					_delay_ms(300); // for proteus sim lower it for real life
					return KeyBoard[i][j]; /*Return if it does*/
				}
			}
			DIO_SetPinValue(Keypad_PORT,Keypad_Rows[i],HIGH); /*Return the value to  it's original state*/
		}
	}
}