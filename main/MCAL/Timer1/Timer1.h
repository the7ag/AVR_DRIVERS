/*
 * Timer1.h
 *
 * Created: 23/06/2023 04:16:48 م
 *  Author: The7ag
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "Timer1_config.h"
#include "Timer1_Reg.h"
#include "Timer1_Types.h"
#include "../DIO/DIO.h"
#include "../Global_INT/Global_INT.h"
#include "math.h"
void TMR1_OF_SetCallBack(void(*LocPFunc)(void));
void TMR1_OCA_SetCallBack(void(*LocPFunc)(void));
void TMR1_OCB_SetCallBack(void(*LocPFunc)(void));
void TMR1_IC_SetCallBack(void(*LocPFunc)(void));

void TIMER1_INIT(void);
void TIMER1_OverFlow_Interrupt_Enable(void);
void TIMER1_OCAM_Interrupt_Enable(void);
void TIMER1_OCBM_Interrupt_Enable(void);
void TIMER1_IC_Interrupt_Enable(void);
void TIMER1_Timer_Counter(uint16 Value_of_TCNT1);
void TIMER1_Output_Compare_Register_1A(uint16 Value_of_OCR1A);
void TIMER1_Output_Compare_Register_1B(uint16 Value_of_OCR1B);
void TIMER1_Timer_Counter(uint16 Value_of_TCNT1);
void TIMER1_ICR1A_Reg(uint16 Value_of_ICR1A);
void Set_Duty_Cycle_TIMER_1_A(float32 percentage_Value);
void Set_Duty_Cycle_TIMER_1_B(float32 percentage_Value);
#endif /* TIMER1_H_ */