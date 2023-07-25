	/*
 * Timer0.c
 *
 * Created: 07/02/2023 02:14:57 م
 *  Author: The7ag
 */ 
#include "Timer0.h"
void __vector_10(void)__attribute__((signal,used));
void __vector_11(void)__attribute__((signal,used));
static void (*TIMER0_OverFlowCallBackPointer)(void);
static void (*TIMER0_CTCCallBackPointer)(void);
static volatile uint32		TIMER0_OverFlowNo	 = 0;
static uint8_t				TIMER0_TCCR0Value    = 0;
static uint8_t				TIMER0_TCNT0Preload  = 0;
static uint16				TIMER0_Prescaler	 = 1;
static uint32				Local_Counter		 = 0;

 void TIMER0_voidStartTimer(void)
 {
	 /*Start TCNT0 Reg counting by loading it's value*/
	 TCCR0_Reg = TIMER0_TCCR0Value;
 }
 
void TIMER0_voidStopTimer(void)
{
	/*Stop TCNT0 Reg counting by loading zeros in CS00,CS01,CS02*/
	TCCR0_Reg = TIMER0_TCCR0Value & TCCR0_MASK;
}

void TIMER0_voidInitializeTimer0(void)
 {
	TIMER0_TCCR0Value &= TCCR0_MASK;          
	TIMER0_TCCR0Value |= TIMER0_PRESCALER;    
	#if (TIMER0_PRESCALER==No_Prescaller)
		TIMER0_Prescaler =1 ;
	#elif (TIMER0_PRESCALER==Prescaller_8)
		TIMER0_Prescaler = 8;
	#elif (TIMER0_PRESCALER>Prescaller_8 && TIMER0_PRESCALER<=Prescaller_1024)
		/*caclulate prescaler = 2^(2*Prescaller)*/
		for (uint8_t i=0;i<(TIMER0_PRESCALER*2);i++)
		{
			TIMER0_Prescaler *= 2;
		}
	#else
		#error "Wrong Prescaller"
	
	#endif
	#if (TIMER0_MODE==TIMER0_NORMAL_MODE)
	
		ClearBit(TIMER0_TCCR0Value,WGM00);
		ClearBit(TIMER0_TCCR0Value,WGM01);
		
		#if (TIMER0_INTERRUPT_STATUS == TIMER0_INT_ENABLED)
			Global_INT_Enable();
			SetBit(TIMSK_Reg,TOIE0);
		#endif
	#elif (TIMER0_MODE==TIMER0_CTC_MODE)
	
		ClearBit(TIMER0_TCCR0Value,WGM00);
		SetBit(TIMER0_TCCR0Value,WGM01);
		
		OCR0_Reg = TIMER0_OCR0_VALUE;
		
		#if (TIMER0_INTERRUPT_STATUS == TIMER0_INT_ENABLED)
		Global_INT_Enable();
		SetBit(TIMSK_Reg,OCIE0);
		#endif
	
	
	#elif (TIMER0_MODE==TIMER0_PHASE_CORCT_MODE)
	
		SetBit(TIMER0_TCCR0Value,WGM00);
		ClearBit(TIMER0_TCCR0Value,WGM01);
	
	#elif (TIMER0_MODE==TIMER0_FAST_PWM_MODE)
	
		SetBit(TIMER0_TCCR0Value,WGM00);
		SetBit(TIMER0_TCCR0Value,WGM01);
	
	#else
		#error "Wrong Timer0 Mode"
	#endif
	TIMER0_TCCR0Value &= COM_MASK;
	TIMER0_TCCR0Value |= (TIMER0_OC0_MODE<<4) ;	
 }
 #if TIMER0_MODE == TIMER0_NORMAL_MODE
	void TIMER0_voidSetDesiredTime_ms(uint32 Copy_Time_ms)
	{
		/*Timer0 calculations*/
			
		float64 Local_TickTime               = (TIMER0_Prescaler)/(float64)TIMER0_F_CPU ;  /*Time in  second*/
		float64 Local_OverFlowTime           = Local_TickTime * TIMER0_REG_CAPACITY ;
		float64 Local_DesiredTime            = Copy_Time_ms/1000;                              /*Time in  second*/
		/*Number of over flow required*/
		TIMER0_OverFlowNo               = ceil(Local_DesiredTime/Local_OverFlowTime);
		/*Number of over flaws remainder*/
		uint32 TIMER0_OverFlowRemainder    = (uint32)Local_DesiredTime%(uint32)Local_OverFlowTime;
		/*clear TCNT0 Register*/
		TCNT0_Reg=0;
		/*if there is initial value*/
		if (TIMER0_OverFlowRemainder>0)
		{
			/*initialize TCNT0 value with pre load value */
			TIMER0_TCNT0Preload = TIMER0_REG_CAPACITY - ((Local_DesiredTime/Local_TickTime)/TIMER0_OverFlowNo) ;
			TCNT0_Reg = TIMER0_TCNT0Preload;
			/*increment no of overflows by one*/
			//TIMER0_OverFlowNo++;
			
		}
			
		/*Start counter by setting TCCR0 value*/
		TIMER0_voidStartTimer();
			
	}/*end of MTIMER0_voidSetDesiredTime_ms()*/
	
	
	void TIMER0_voidSetDesiredTime_us(uint32 Copy_Time_us)
	{	
		/*Timer0 calculations*/
		float64 Local_TickTime               = (TIMER0_Prescaler)/(float64)TIMER0_F_CPU ;  /*Time in  second*/
		float64 Local_OverFlowTime           = Local_TickTime * TIMER0_REG_CAPACITY ;
		float64 Local_DesiredTime            = Copy_Time_us/1000000;                              /*Time in  second*/
		TIMER0_OverFlowNo               = ceil(Local_DesiredTime/Local_OverFlowTime);
		/*Number of over flaws remainder*/
		uint32 TIMER0_OverFlowRemainder    = (uint32)Local_DesiredTime%(uint32)Local_OverFlowTime;
		/*clear TCNT0 Register*/
		TCNT0_Reg=0;
		/*if there is initial value*/
		if (TIMER0_OverFlowRemainder>0)
		{
			/*initialize TCNT0 value with pre load value */
			TIMER0_TCNT0Preload = TIMER0_REG_CAPACITY - ((Local_DesiredTime/Local_TickTime)/TIMER0_OverFlowNo) ;
			TCNT0_Reg = TIMER0_TCNT0Preload;
		}		
		TIMER0_voidStartTimer();
	}

	void TIMER0_voidOverFlowCallBack(void(*Copy_Ptr)(void))
	 {
		 TIMER0_OverFlowCallBackPointer = Copy_Ptr;
	 }
 
	 void __vector_11(void) /*Timer0 over flow ISR*/
	 {
		Local_Counter++;
		if (TIMER0_OverFlowCallBackPointer != NULL)
		{
			TIMER0_OverFlowCallBackPointer();
		}
	}/*end of __vector_11()*/
	void delay_T0(uint32 Time_MS)
	{
		TIMER0_voidSetDesiredTime_ms(Time_MS);
		while (Local_Counter<TIMER0_OverFlowNo);
		Local_Counter = 0;
		TCNT0_Reg=TIMER0_TCNT0Preload;
		TIMER0_voidStopTimer();
	}
	void delay_T0_US(uint32 Time_US)
	{
		TIMER0_voidSetDesiredTime_us(Time_US);
		while (Local_Counter<TIMER0_OverFlowNo);
		Local_Counter = 0;
		TCNT0_Reg=TIMER0_TCNT0Preload;
		TIMER0_voidStopTimer();
	}
#elif TIMER0_MODE == TIMER0_CTC_MODE
	void TIMER0_voidSetDesiredTime_ms(uint32 Copy_Time_ms)
	 {
 		 /*Timer0 calculations*/
		float64 Local_TickTime               = (TIMER0_Prescaler)/(float64)TIMER0_F_CPU ;  /*Time in  second*/
		float64 Local_DesiredTime            = Copy_Time_ms/1000;                              /*Time in  second*/
		 /*set OCR0 value*/
		 OCR0_Reg    = Local_DesiredTime / Local_TickTime; 
	
		 /*Start counter by setting TCCR0 value*/
		 TIMER0_voidStartTimer();
	
	 }

	 void MTIMER0_voidSetDesiredTime_us(uint32 Copy_Time_us)
	 {
  		 /*Timer0 calculations*/
		float64 Local_TickTime               = (TIMER0_Prescaler)/(float64)TIMER0_F_CPU ;  /*Time in  second*/
		float64 Local_DesiredTime            = Copy_Time_us/1000;                              /*Time in  second*/
		 /*set OCR0 value*/
		 OCR0_Reg    = Local_DesiredTime / Local_TickTime;
	
		 /*Start counter by setting TCCR0 value*/
		 TIMER0_voidStartTimer();
	 }

	 void TIMER0_voidCTCCallBackfunction(void(*Copy_Ptr)(void))
	 {
		 //save function address in global pointer to function
 		 TIMER0_CTCCallBackPointer = Copy_Ptr;
	  
	 }/*end of MTIMER0_voidCTCCallBackfn()*/

	 void __vector_10(void)/*Timer0 CTC ISR*/
	 {
		 //FOR RTO
		static uint16 counter=0;
		counter++;
		if(counter == 5 ) //for 1 ms delay
		{
			//clear counter
			counter=0;
			//For normal CTC
			if(TIMER0_CTCCallBackPointer != NULL)
			{
				TIMER0_CTCCallBackPointer();
			}
		}
	 }/*end of __vector_10()*/
	 
 #elif (TIMER0_MODE == TIMER0_FAST_PWM_MODE) 
 
 
	 void TIMER0_voidFastPWM(uint8_t Copy_DutyCycle)
	 {
		 /*configure PWM Duty Cycle*/
		 OCR0_Reg = (Copy_DutyCycle*TIMER0_REG_CAPACITY)/100;
		 /*Start PWM*/ 
		 TIMER0_voidStartTimer();
	 
	 }
 
 
 #elif TIMER0_MODE == TIMER0_PHASE_CORCT_MODE
	 void TIMER0_voidPhaseCorrectPWM(uint8_t Copy_DutyCycle)
	 {
		/*configure PWM Duty Cycle*/
 		OCR0_Reg = (Copy_DutyCycle*(TIMER0_REG_CAPACITY-1))/100;
 		/*Start PWM*/
		TIMER0_voidStartTimer();
	 }

#endif

