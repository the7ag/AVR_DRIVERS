/*
 * Timer1.c
 *
 * Created: 23/06/2023 04:16:58 م
 *  Author: The7ag
 */ 
#include "Timer1.h"
void __vector_9(void)__attribute__((signal,used));
void __vector_8(void)__attribute__((signal,used));
//void __vector_7(void)__attribute__((signal,used));
void __vector_6(void)__attribute__((signal,used));

/****** Global Pointer To Function *********/
static void (*GPFunc_OF)(void)=NULL;
static void (*GPFunc_OCA)(void)=NULL;
static void (*GPFunc_OCB)(void)=NULL;
static void (*GPFunc_IC)(void)=NULL;
void TMR1_OF_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc_OF=LocPFunc;
}
void TMR1_OCA_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc_OCA=LocPFunc;
}
void TMR1_OCB_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc_OCB=LocPFunc;
}
void TMR1_IC_SetCallBack(void(*LocPFunc)(void))
{
	GPFunc_IC=LocPFunc;
}
void __vector_9(void)
 {
	if(GPFunc_OF!=NULL)
	{
		GPFunc_OF();
	}
	
}
void __vector_8(void)
{
	if(GPFunc_OCB!=NULL)
	{
		GPFunc_OCB();
	}	
}
/*void __vector_7(void)
{
	if(GPFunc_OCA!=NULL)
	{
		GPFunc_OCA();
	}
}*/
void __vector_6(void)
{
	if(GPFunc_IC!=NULL)
	{
		GPFunc_IC();
	}
}
void TIMER1_INIT(void)
{
	#if TIMER1_MODE	==	NORMAL_Timer_1
	/*Prescalar must be 8*/
	ClearBit(TCCR1A_Reg, WGM10);
	ClearBit(TCCR1A_Reg, WGM11);
	ClearBit(TCCR1A_Reg, WGM12);
	ClearBit(TCCR1A_Reg, WGM13);
	TCNT1_Reg=25206;
	TIMER1_OverFlow_Interrupt_Enable();
	#elif TIMER1_MODE	==	PWM_Phase_Correct_8_bit_Timer_1
	SetBit(TCCR1A_Reg, WGM10);
	ClearBit(TCCR1A_Reg, WGM11);
	ClearBit(TCCR1B_Reg, WGM12);
	ClearBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==	PWM_Phase_Correct_9_bit_Timer_1
	ClearBit(TCCR1A_Reg, WGM10);
	SetBit(TCCR1A_Reg, WGM11);
	ClearBit(TCCR1B_Reg, WGM12);
	ClearBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==	PWM_Phase_Correct_10_bit_Timer_1
	SetBit(TCCR1A_Reg, WGM10);
	SetBit(TCCR1A_Reg, WGM11);
	ClearBit(TCCR1B_Reg, WGM12);
	ClearBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==	CTC_1_Timer_1
	/*IN CTC MODE YOU CAN ONLY WORK WITH OCR1A
	 * YOU CAN'T WORK OUTPUT COMPARE MATCH B*/
	OCR1A_Reg=1000;
	TIMER1_OCAM_Interrupt_Enable();
	ClearBit(TCCR1A_Reg, WGM10);
	ClearBit(TCCR1A_Reg, WGM11);
	SetBit(TCCR1B_Reg, WGM12);
	ClearBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==  Fast_PWM_8_bit_Timer_1
	SetBit(TCCR1A_Reg, WGM10);
	ClearBit(TCCR1A_Reg, WGM11);
	SetBit(TCCR1B_Reg, WGM12);
	ClearBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==  Fast_PWM_9_bit_Timer_1
	ClearBit(TCCR1A_Reg, WGM10);
	SetBit(TCCR1A_Reg, WGM11);
	SetBit(TCCR1B_Reg, WGM12);
	ClearBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==	Fast_PWM_10_bit_Timer_1
	SetBit(TCCR1A_Reg, WGM10);
	SetBit(TCCR1A_Reg, WGM11);
	SetBit(TCCR1B_Reg, WGM12);
	ClearBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==  PWM_Phase_and_Frequency_Correct_1_Timer_1
	ClearBit(TCCR1A_Reg, WGM10);
	ClearBit(TCCR1A_Reg, WGM11);
	ClearBit(TCCR1B_Reg, WGM12);
	SetBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==	PWM_Phase_and_Frequency_Correct_2_Timer_1
	SetBit(TCCR1A_Reg, WGM10);
	ClearBit(TCCR1A_Reg, WGM11);
	ClearBit(TCCR1B_Reg, WGM12);
	SetBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==	PWM_Phase_Correct_0_Timer_1
	ClearBit(TCCR1A_Reg, WGM10);
	SetBit(TCCR1A_Reg, WGM11);
	ClearBit(TCCR1B_Reg, WGM12);
	SetBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==	PWM_Phase_Correct_1_Timer_1
	SetBit(TCCR1A_Reg, WGM10);
	SetBit(TCCR1A_Reg, WGM11);
	ClearBit(TCCR1B_Reg, WGM12);
	SetBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==  CTC_2_Timer_1
	/*Can work with both OCR1A OCR1B*/
	ClearBit(TCCR1A_Reg, WGM10);
	ClearBit(TCCR1A_Reg, WGM11);
	SetBit(TCCR1B_Reg, WGM12);
	SetBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==  Reserved_Timer_1
	SetBit(TCCR1A_Reg, WGM10);
	ClearBit(TCCR1A_Reg, WGM11);
	SetBit(TCCR1B_Reg, WGM12);
	SetBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==  Fast_PWM_ICR1_Timer_1
	ClearBit(TCCR1A_Reg, WGM10);
	SetBit(TCCR1A_Reg, WGM11);
	SetBit(TCCR1B_Reg, WGM12);
	SetBit(TCCR1B_Reg, WGM13);
	#elif TIMER1_MODE	==	Fast_PWM_OCR1A_Timer_1
	SetBit(TCCR1A_Reg, WGM10);
	SetBit(TCCR1A_Reg, WGM11);
	SetBit(TCCR1B_Reg, WGM12);
	SetBit(TCCR1B_Reg, WGM13);
	#endif
		#if Compare_Output_Mode	==	Normal_port_operation_Timer1
		ClearBit(TCCR1A_Reg, COM1A0);
		ClearBit(TCCR1A_Reg, COM1A1);
		ClearBit(TCCR1A_Reg, COM1B0);
		ClearBit(TCCR1A_Reg, COM1B1);
		#elif Compare_Output_Mode	==	Toggle_OC1A_OC1B_Timer1
		SetBit(TCCR1A_Reg, COM1A0);
		ClearBit(TCCR1A_Reg, COM1A1);
		SetBit(TCCR1A_Reg, COM1B0);
		ClearBit(TCCR1A_Reg, COM1B1);
		#elif Compare_Output_Mode	==	Non_Inverted_Timer1
		ClearBit(TCCR1A_Reg, COM1A0);
		SetBit(TCCR1A_Reg, COM1A1);
		ClearBit(TCCR1A_Reg, COM1B0);
		SetBit(TCCR1A_Reg, COM1B1);
		#elif  Compare_Output_Mode == Inverted_Timer1
		SetBit(TCCR1A_Reg, COM1A0);
		SetBit(TCCR1A_Reg, COM1A1);
		SetBit(TCCR1A_Reg, COM1B0);
		SetBit(TCCR1A_Reg, COM1B1);
		#endif
		#if PHC_PWM_Compare_Output_Mode == PHC_PWM_Normal_port_operation_Timer1
		ClearBit(TCCR1A_Reg, COM1A0);
		ClearBit(TCCR1A_Reg, COM1A1);
		ClearBit(TCCR1A_Reg, COM1B0);
		ClearBit(TCCR1A_Reg, COM1B1);
		#elif PHC_PWM_Compare_Output_Mode == PHC_PWM_Toggle_OC1A_OC1B_Timer1
		SetBit(TCCR1A_Reg, COM1A0);
		ClearBit(TCCR1A_Reg, COM1A1);
		SetBit(TCCR1A_Reg, COM1B0);
		ClearBit(TCCR1A_Reg, COM1B1);
		#elif PHC_PWM_Compare_Output_Mode == PHC_PWM_Non_Inverted_Timer1
		ClearBit(TCCR1A_Reg, COM1A0);
		SetBit(TCCR1A_Reg, COM1A1);
		ClearBit(TCCR1A_Reg, COM1B0);
		SetBit(TCCR1A_Reg, COM1B1);
		#elif PHC_PWM_Compare_Output_Mode == PHC_PWM_Inverted_Timer1
		SetBit(TCCR1A_Reg, COM1A0);
		SetBit(TCCR1A_Reg, COM1A1);
		SetBit(TCCR1A_Reg, COM1B0);
		SetBit(TCCR1A_Reg, COM1B1);
		#endif
		#if PWM_Compare_Output_Mode == PWM_Normal_port_operation_Timer1
		ClearBit(TCCR1A_Reg, COM1A0);
		ClearBit(TCCR1A_Reg, COM1A1);
		ClearBit(TCCR1A_Reg, COM1B0);
		ClearBit(TCCR1A_Reg, COM1B1);
		#elif PWM_Compare_Output_Mode == PWM_Toggle_OC1A_OC1B_Timer1
		 SetBit(TCCR1A_Reg, COM1A0);
		 ClearBit(TCCR1A_Reg, COM1A1);
		 SetBit(TCCR1A_Reg, COM1B0);
		 ClearBit(TCCR1A_Reg, COM1B1);
		#elif PWM_Compare_Output_Mode == PWM_Non_Inverted_Timer1
		 ClearBit(TCCR1A_Reg, COM1A0);
		 SetBit(TCCR1A_Reg, COM1A1);
		 ClearBit(TCCR1A_Reg, COM1B0);
		 SetBit(TCCR1A_Reg, COM1B1);
		#elif PWM_Compare_Output_Mode == PWM_Inverted_Timer1
		 SetBit(TCCR1A_Reg, COM1A0);\
		 SetBit(TCCR1A_Reg, COM1A1);\
		 SetBit(TCCR1A_Reg, COM1B0);\
		 SetBit(TCCR1A_Reg, COM1B1);
		#endif
	#if TIMER1_Prescaler==TIMER1_NO_CLOCK_SOURCE
		ClearBit(TCCR1B_Reg,CS12);
		ClearBit(TCCR1B_Reg,CS11);
		ClearBit(TCCR1B_Reg,CS10);
	#elif TIMER1_Prescaler==TIMER1_NO_PRESCALER
		ClearBit(TCCR1B_Reg,CS12);
		ClearBit(TCCR1B_Reg,CS11);
		SetBit(TCCR1B_Reg,CS10);
	#elif TIMER1_Prescaler==TIMER1_Prescaler_8
		ClearBit(TCCR1B_Reg,CS12);
		SetBit(TCCR1B_Reg,CS11);
		ClearBit(TCCR1B_Reg,CS10);
	#elif TIMER1_Prescaler==TIMER1_Prescaler_64
		ClearBit(TCCR1B_Reg,CS12);
		SetBit(TCCR1B_Reg,CS11);
		SetBit(TCCR1B_Reg,CS10);
	#elif TIMER1_Prescaler==TIMER1_Prescaler_256
		SetBit(TCCR1B_Reg,CS12);
		ClearBit(TCCR1B_Reg,CS11);
		ClearBit(TCCR1B_Reg,CS10);
	#elif TIMER1_Prescaler==TIMER1_Prescaler_1024
		SetBit(TCCR1B_Reg,CS12);
		ClearBit(TCCR1B_Reg,CS11);
		SetBit(TCCR1B_Reg,CS10);
	#elif TIMER1_Prescaler==TIMER1_FALLING_EDGE
		SetBit(TCCR1B_Reg,CS12);
		SetBit(TCCR1B_Reg,CS11);
		ClearBit(TCCR1B_Reg,CS10);
	#elif TIMER1_Prescaler==TIMER1_RISING_EDGE
		 SetBit(TCCR1B_Reg,CS12);
		 SetBit(TCCR1B_Reg,CS11);
		 SetBit(TCCR1B_Reg,CS10);
	#endif
	#if TIMER1_INTERRUPT_STATUS==Interrupt_Enable_Timer1
	Global_INT_Enable();
	#endif
}
void TIMER1_OverFlow_Interrupt_Enable(void)
{
	SetBit(TIMSK_Reg,TOIE1);
}
void TIMER1_OCAM_Interrupt_Enable(void)
{
	SetBit(TIMSK_Reg,OCIE1A);
}
void TIMER1_OCBM_Interrupt_Enable(void)
{
	SetBit(TIMSK_Reg,OCIE1B);
}
void TIMER1_IC_Interrupt_Enable(void)
{
	SetBit(TIMSK_Reg,TICIE1);
}
void TIMER1_Timer_Counter(uint16 Value_of_TCNT1)
{
	TCNT1_Reg=Value_of_TCNT1;
}
void TIMER1_Output_Compare_Register_1A(uint16 Value_of_OCR1A)
{
	OCR1A_Reg=Value_of_OCR1A;
}

void TIMER1_Output_Compare_Register_1B(uint16 Value_of_OCR1B)
{
	OCR1B_Reg=Value_of_OCR1B;
}
void TIMER1_ICR1A_Reg(uint16 Value_of_ICR1A)
{
	ICR1A_Reg=Value_of_ICR1A;
}
void Set_Duty_Cycle_TIMER_1_A(float32 percentage_Value)
{
	#if TIMER1_MODE==Fast_PWM_8_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A_Reg=(percentage_Value*256)-1;
	#elif TIMER1_MODE==Fast_PWM_9_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A_Reg=(percentage_Value*512)-1;
	#elif TIMER1_MODE==Fast_PWM_10_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A_Reg=(percentage_Value*1024)-1;
	#elif TIMER1_MODE==Fast_PWM_ICR1_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1A_Reg=(percentage_Value*ICR1A_Reg)-1;
	#endif
}
void Set_Duty_Cycle_TIMER_1_B(float32 percentage_Value)
{
	#if TIMER1_MODE==Fast_PWM_8_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B_Reg=(percentage_Value*256)-1;
	#elif TIMER1_MODE==Fast_PWM_9_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B_Reg=(percentage_Value*512)-1;
	#elif TIMER1_MODE==Fast_PWM_10_bit_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B_Reg=(percentage_Value*1024)-1;
	#elif TIMER1_MODE==Fast_PWM_ICR1_Timer_1
	percentage_Value=percentage_Value/100;
	OCR1B_Reg=(percentage_Value*ICR1A_Reg)-1;
	#endif
}