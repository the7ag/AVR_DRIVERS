/*
 * Timer0_Types.h
 *
 * Created: 07/02/2023 02:15:48 م
 *  Author: The7ag
 */ 


#ifndef TIMER0_TYPES_H_
#define TIMER0_TYPES_H_


 #define TIMER_START           1
 #define TIMER_STOP            0


  #define TIMER0_INT_ENABLED      1
  #define TIMER0_INT_DISABLED     0
  
  
  #define TIMER0_REG_CAPACITY      256
  
  
   #define No_Prescaller             1
   #define Prescaller_8              2
   #define Prescaller_64             3
   #define Prescaller_256            4
   #define Prescaller_1024           5
   #define Prescaller_FalExtClk      6
   #define Prescaller_RaisExtClk     7
   
   
   
    #define TIMER0_NORMAL_MODE       0
    #define TIMER0_CTC_MODE          1
    #define TIMER0_FAST_PWM_MODE     2
    #define TIMER0_PHASE_CORCT_MODE  3
	
	
	//TCCR0
	
	#define WGM00			  6
	#define WGM01             3
	 
	//TIMSK
	 
	#define TOIE0             0
	#define OCIE0             1
	

	#define STOP_MASK          0x11111000
	
	#define COM_MASK           0b11001111
	
	#define TCCR0_MASK         0b11111000
	
	
	#define TIMER0_DISCONNECT_OC0      0
	#define TIMER0_TOGGLE_OC0          1
	#define TIMER0_CLEAR_OC0           2
	#define TIMER0_SET_OC0             3
	
	  
	 #define TIMER0_PWM_NONINVERTED_OC0 2
	 #define TIMER0_PWM_INVERTED_OC0    3



#endif /* TIMER0_TYPES_H_ */