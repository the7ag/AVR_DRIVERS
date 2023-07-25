/*
 * TestApp.c
 *
 * Created: 17/07/2023 03:18:59 م
 *  Author: The7ag
 */ 
#include "TestApp.h"

#define Red_Task_Priority	3
#define Green_Task_Priority 2
#define Blue_Task_Priority	1

void Redtask(void* pv);
void Greentask(void* pv);
void Bluetask(void* pv);

void LCD_1(void* pv);
void LCD_2(void* pv);

//create semaphore
xSemaphoreHandle LCD_Semp;

void RTOS_test()
{
	//DIO_SetPinDirection(PORTA,Pin0,Output);
	//DIO_SetPinDirection(PORTA,Pin1,Output);
	//DIO_SetPinDirection(PORTA,Pin2,Output);
	LCD_Init(PORTA,PORTA,Pin0,Pin1,Pin2,Pin3,Pin4,Pin5);
	/*create tasks*/
	//xTaskCreate(&Redtask,NULL,200,NULL,Red_Task_Priority,NULL);
	//xTaskCreate(&Greentask,NULL,200,NULL,Green_Task_Priority,NULL);
	//xTaskCreate(&Bluetask,NULL,200,NULL,Blue_Task_Priority,NULL);
	xTaskCreate(&LCD_1,NULL,200,NULL,2,NULL);
	xTaskCreate(&LCD_2,NULL,200,NULL,2,NULL);
	/*create Semaphore*/
	vSemaphoreCreateBinary(LCD_Semp);
	//LCD_Semp=xSemaphoreCreateCounting(1,1);
	/*Start Scheduler*/
	vTaskStartScheduler();
	while(1);
}
//tasks
void Redtask(void *pv)
{
	while(1)
	{
		vTaskDelay(1000);
		DIO_TogglePinValue(PORTA,Pin0);
		
	}
}
void Greentask(void *pv)
{
	while(1)
	{
		vTaskDelay(2000);
		DIO_TogglePinValue(PORTA,Pin1);
	}
}
void Bluetask(void *pv)
{
	while(1)
	{
		vTaskDelay(4000);
		DIO_TogglePinValue(PORTA,Pin2);
	}
}

void LCD_1(void* pv)
{
	while(1)
	{
		/*Take Semaphore*/
		if(xSemaphoreTake(LCD_Semp,portMAX_DELAY)== pdTRUE)
		{
			LCD_Print("I'm Task 1");
			xSemaphoreGive(LCD_Semp);
			vTaskDelay(1000);
			//LCD_Clear();
		}

	}
}
void LCD_2(void* pv)
{
	while(1)
	{
		/*Take Semaphore*/
		if(xSemaphoreTake(LCD_Semp,portMAX_DELAY)== pdTRUE)
		{
			LCD_Print("I'm Task 2");
			xSemaphoreGive(LCD_Semp);
			vTaskDelay(1000);
			//LCD_Clear();
		}
	}
}
