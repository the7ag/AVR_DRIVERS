/*
 * Timer1_Types.h
 *
 * Created: 23/06/2023 04:16:25 م
 *  Author: The7ag
 */ 


#ifndef TIMER1_TYPES_H_
#define TIMER1_TYPES_H_
/***************************************************************************/
/*************************** *Timer/Counter1 Control Register A  TCCR1A*   ************************/
/*************************************************************************/
#define COM1A1   7
#define COM1A0   6
#define COM1B1   5
#define COM1B0   4
#define FOC1A    3
#define FOC1B    2
#define WGM11    1
#define WGM10    0
/***************************************************************************/
/*************************** *Timer/Counter1 Control Register B  TCCR1B*   ************************/
/*************************************************************************/
#define ICNC1     7
#define ICES1     6
#define WGM13     4
#define WGM12     3
#define CS12      2
#define CS11      1
#define CS10      0
/***************************************************************************/
/*************************** Timer/Counter Interrupt Mask Register – TIMSK   ************************/
/*************************************************************************/
#define  OCIE2       7
#define  TOIE2       6
#define  TICIE1      5
#define  OCIE1A      4
#define  OCIE1B      3
#define  TOIE1       2
#define  OCIE0       1
#define  TOIE0       0
/***************************************************************************/
/*************************** Timer/Counter Interrupt Flag Register – TIFR   ************************/
/*************************************************************************/
#define CF1 	5
#define OCF1A 	4
#define OCF1B 	3
#define TOV1	2
#define TOV0	0
#define OCF0 	1

/************************************************************************/
/* Timer 1 Int                                                                     */
/************************************************************************/
#define Interrupt_Disaple_Timer1	0
#define Interrupt_Enable_Timer1		1
#define TICIE1    5  //Input Capture Interrupt Enable in TIMER 1
#define OCIE1A    4  //output compare A Interrupt Enable in TIMER 1
#define OCIE1B    3  //output compare B Interrupt Enable in TIMER 1
#define TOIE1     2  //TIMER 1 overflow Interrupt Enable
/***************************************************************************/
/*************************** TIMER 1 MODES  ************************/
/*************************************************************************/
#define NORMAL_Timer_1                              		        0
#define PWM_Phase_Correct_8_bit_Timer_1                             1
#define PWM_Phase_Correct_9_bit_Timer_1                             2
#define PWM_Phase_Correct_10_bit_Timer_1                            3
#define CTC_1_Timer_1                                               4
#define Fast_PWM_8_bit_Timer_1                                      5
#define Fast_PWM_9_bit_Timer_1                                      6
#define Fast_PWM_10_bit_Timer_1                                     7
#define PWM_Phase_and_Frequency_Correct_1_Timer_1                   8
#define PWM_Phase_and_Frequency_Correct_2_Timer_1                   9
#define PWM_Phase_Correct_0_Timer_1									10
#define PWM_Phase_Correct_1_Timer_1									11
#define CTC_2_Timer_1                                               12
#define Reserved_Timer_1                                            13
#define Fast_PWM_ICR1_Timer_1                                       14
#define Fast_PWM_OCR1A_Timer_1                                      15
/***************************************************************************/
/*************************** TIMER 1 PRESCALER  ************************/
/*************************************************************************/

#define    TIMER1_NO_CLOCK_SOURCE    	 0
#define    TIMER1_NO_PRESCALER 			 1
#define    TIMER1_Prescaler_8			 2
#define    TIMER1_Prescaler_64			 3
#define    TIMER1_Prescaler_256			 4
#define    TIMER1_Prescaler_1024		 5
#define    TIMER1_FALLING_EDGE			 6
#define    TIMER1_RISING_EDGE			 7

/****************************************************************************************************************/
/****************************************************************************************************************/

/*Compare Output Mode, Non-PWM*/
#define Normal_port_operation_Timer1	0
#define Toggle_OC1A_OC1B_Timer1         1
#define Non_Inverted_Timer1             2
#define Inverted_Timer1                 3
/****************************************************************************************************************/
/****************************************************************************************************************/
/*Compare Output Mode, Fast PWM*/
#define PWM_Normal_port_operation_Timer1		  0
#define PWM_Toggle_OC1A_OC1B_Timer1               1
#define PWM_Non_Inverted_Timer1                   2
#define PWM_Inverted_Timer1                       3
/****************************************************/
/****************************************************************************************************************/
#define PHC_PWM_Normal_port_operation_Timer1	      0
#define PHC_PWM_Toggle_OC1A_OC1B_Timer1               1
#define PHC_PWM_Non_Inverted_Timer1                   2
#define PHC_PWM_Inverted_Timer1                       3

/****************************************************/


#endif /* TIMER1_TYPES_H_ */