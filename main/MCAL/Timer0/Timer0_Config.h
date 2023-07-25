/*
 * Timer0_Config.h
 *
 * Created: 07/02/2023 02:15:33 م
 *  Author: The7ag
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

#include "Timer0_Types.h"


#define TIMER0_F_CPU				8000000
/* 
 * Choose prescaler from 
 * No_Prescaller - Prescaller_8 - Prescaller_64 - Prescaller_256 - 
 * Prescaller_1024 - Prescaller_FalExtClk - Prescaller_RaisExtClk
 * Prescaller_FalExtClk - Prescaller_RaisExtClk these two options are used with counter option
 */

#define TIMER0_PRESCALER			Prescaller_8


/*
 * Choose Mode :
 * TIMER0_NORMAL_MODE - TIMER0_CTC_MODE - TIMER0_FAST_PWM_MODE - TIMER0_PHASE_CORCT_MODE  
 */
#define TIMER0_MODE					TIMER0_CTC_MODE
/* 
 * Timers interrupt initial status :
 * TIMER0_INT_ENABLED TIMER0_INT_DISABLED
 */

#define TIMER0_INTERRUPT_STATUS		TIMER0_INT_ENABLED
/* 
 * Choose Timer0 OC0 Mode :
 * with PWM modes:
 * TIMER0_DISCONNECT_OC0, TIMER0_PWM_NONINVERTED_OC0, TIMER0_PWM_INVERTED_OC0   
 * with non PWM Modes: 
 * TIMER0_DISCONNECT_OC0, TIMER0_TOGGLE_OC0, TIMER0_CLEAR_OC0, TIMER0_SET_OC0 
 */

#define TIMER0_OC0_MODE				TIMER0_DISCONNECT_OC0

/*OCR0 Initial Value*/

#define TIMER0_OCR0_VALUE			199




#endif /* TIMER0_CONFIG_H_ */