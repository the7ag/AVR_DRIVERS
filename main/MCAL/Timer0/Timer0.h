/*
 * Timer0.h
 *
 * Created: 07/02/2023 02:14:46 م
 *  Author: The7ag
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "Timer0_Config.h"
#include "Timer0_Reg.h"
#include "../DIO/DIO.h"
#include "../../HAL/LED/LED.h"
#include "../Global_INT/Global_INT.h"
#include "math.h"
#define F_CPU 8000000UL

 void TIMER0_voidStartTimer(void);
 void TIMER0_voidStopTimer(void);
 void TIMER0_voidInitializeTimer0(void);
 #if TIMER0_MODE == TIMER0_NORMAL_MODE
	void TIMER0_voidSetDesiredTime_ms(uint32 Copy_Time_ms);
	void TIMER0_voidSetDesiredTime_us(uint32 Copy_Time_us);
	void TIMER0_voidOverFlowCallBack(void(*Copy_Ptr)(void));
	/*These Delays only Work for over 1Sec Long because of floating point calculations*/
	void delay_T0(uint32 Time_MS);
	void delay_T0_US(uint32 Time_US);
 #elif TIMER0_MODE == TIMER0_CTC_MODE
	void TIMER0_voidSetDesiredTime_ms(uint32 Copy_Time_ms);
	void TIMER0_voidSetDesiredTime_us(uint32 Copy_Time_us);
	void TIMER0_voidCTCCallBackfunction(void(*Copy_Ptr)(void));
 #elif (TIMER0_MODE == TIMER0_FAST_PWM_MODE)
 	void TIMER0_voidFastPWM(uint8_t Copy_DutyCycle);
 #elif TIMER0_MODE == TIMER0_PHASE_CORCT_MODE
	void TIMER0_voidPhaseCorrectPWM(uint8_t Copy_DutyCycle);
 #endif
void timer();
void pwm();

#endif /* TIMER0_H_ */