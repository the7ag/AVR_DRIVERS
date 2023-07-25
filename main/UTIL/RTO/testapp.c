/*
 * testapp.c
 *
 * Created: 16/07/2023 05:04:40 م
 *  Author: The7ag
 */
#include "RTO.h"
void task1();
void task2();
void task3();

void RTO()
{
	LED_Init(PORTA,Pin0);
	LED_Init(PORTA,Pin1);
	LED_Init(PORTA,Pin2);
	LED_Init(PORTA,Pin3);
	RTO_Init();
	RTO_CreateTask(0,1000,6000,&task1);
	RTO_CreateTask(1,2000,0,&task2);
	RTO_CreateTask(2,5000,0,&task3);
	RTO_StartScheduler();
	TIMER0_voidStartTimer();
	while(1);
}
void task1()
{
	static uint8_t flag=0;
	if (flag==0)
	{
		LED_On(PORTA,Pin0);
		flag=1;
	}else
	{
		LED_Off(PORTA,Pin0);
		flag=0;
	}
}
void task2()
{
	static uint8_t flag=0;
	if (flag==0)
	{
		LED_On(PORTA,Pin1);
		flag=1;
	}else
	{
		LED_Off(PORTA,Pin1);
		flag=0;
	}
}
void task3()
{
	static uint8_t flag=0;
	if (flag==0)
	{
		LED_On(PORTA,Pin2);
		flag=1;
	}else
	{
		LED_Off(PORTA,Pin2);
		flag=0;
	}
}