/*
 * Timer1_config.h
 *
 * Created: 23/06/2023 04:16:38 م
 *  Author: The7ag
 */ 


#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_
#include "Timer1_Types.h"
#define TIMER1_F_CPU				8000000UL
/* 
 * Choose prescaler from 
 TIMER1_NO_CLOCK_SOURCE,TIMER1_NO_PRESCALER ,TIMER1_Prescaler_8 ,TIMER1_Prescaler_64 ,TIMER1_Prescaler_256 ,TIMER1_Prescaler_1024
 TIMER1_FALLING_EDGE ,TIMER1_RISING_EDGE
 */
#define  TIMER1_Prescaler	TIMER1_Prescaler_8
/*
 * Choose Mode :
  NORMAL_Timer_1                              		        
  PWM_Phase_Correct_8_bit_Timer_1                             
  PWM_Phase_Correct_9_bit_Timer_1                             
  PWM_Phase_Correct_10_bit_Timer_1                            
  CTC_1_Timer_1                                               
  Fast_PWM_8_bit_Timer_1                                      
  Fast_PWM_9_bit_Timer_1                                      
  Fast_PWM_10_bit_Timer_1                                     
  PWM_Phase_and_Frequency_Correct_1_Timer_1                   
  PWM_Phase_and_Frequency_Correct_2_Timer_1                   
  PWM_Phase_Correct_0_Timer_1									
  PWM_Phase_Correct_1_Timer_1									
  CTC_2_Timer_1                                               
  Reserved_Timer_1                                            
  Fast_PWM_ICR1_Timer_1                                       
  Fast_PWM_OCR1A_Timer_1                                      
 */
#define TIMER1_MODE  CTC_1_Timer_1
/* 
 * Choose Timer1 OC1 Mode :
 Normal_port_operation_Timer1	
 Toggle_OC1A_OC1B_Timer1         
 Non_Inverted_Timer1             
 Inverted_Timer1                 
 */
#define Compare_Output_Mode  Normal_port_operation_Timer1
/*
		Compare Output Mode, Fast PWM
 PWM_Normal_port_operation_Timer1		  
 PWM_Toggle_OC1A_OC1B_Timer1               
 PWM_Non_Inverted_Timer1                   
 PWM_Inverted_Timer1                       
		*/
#define PWM_Compare_Output_Mode  Non_Inverted_Timer1
/*Compare Output Mode, Phase Correct and Phase and Frequency Correct PWM
#define PHC_PWM_Normal_port_operation_Timer1	      
#define PHC_PWM_Toggle_OC1A_OC1B_Timer1               
#define PHC_PWM_Non_Inverted_Timer1                   
#define PHC_PWM_Inverted_Timer1                       
*/
#define PHC_PWM_Compare_Output_Mode  Non_Inverted_Timer1
/* 
 * Timers interrupt initial status :
 Interrupt_Disaple_Timer1	
 Interrupt_Enable_Timer1			   
 */

#define TIMER1_INTERRUPT_STATUS		  Interrupt_Enable_Timer1



#endif /* TIMER1_CONFIG_H_ */