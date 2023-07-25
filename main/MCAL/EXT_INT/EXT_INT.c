/*
 * EXT_INT.c
 *
 * Created: 04/02/2023 11:09:34 م
 *  Author: The7ag
 */ 
#include "EXT_INT.h"
/*Init All the interrupts*/
void (*CallBackPtr0) (void) = NULL;
void (*CallBackPtr1) (void) = NULL;
void (*CallBackPtr2) (void) = NULL;

void EXT_INT_init()
{
	/*Clear The Bits For INT0 INT1*/
	ClearBit(MCUCR_Reg,0);
	ClearBit(MCUCR_Reg,1);
	ClearBit(MCUCR_Reg,2);
	ClearBit(MCUCR_Reg,3);
	/*For INT2*/
	ClearBit(MCUCSR_Reg,6);
	/*For Mood Choise*/
	#if		EXT_INT0_Mode == EXT_INT_Low_Level
				MCUCR_Reg |= EXT_INT_Low_Level;
	#elif	EXT_INT0_Mode == EXT_INT_Any_Logical
				MCUCR_Reg |= EXT_INT_Any_Logical;
	#elif	EXT_INT0_Mode == EXT_INT_Falling_Edge
				MCUCR_Reg |= EXT_INT_Falling_Edge;
	#elif	EXT_INT0_Mode == EXT_INT_Rising_Edge
				MCUCR_Reg |= EXT_INT_Rising_Edge;
	#endif
	
	#if		EXT_INT1_Mode == EXT_INT_Low_Level
				MCUCR_Reg |= (EXT_INT_Low_Level <<2 );
	#elif	EXT_INT1_Mode == EXT_INT_Any_Logical
				MCUCR_Reg |= (EXT_INT_Any_Logical << 2 );
	#elif	EXT_INT1_Mode == EXT_INT_Falling_Edge
				MCUCR_Reg |= (EXT_INT_Falling_Edge << 2 );
	#elif	EXT_INT1_Mode == EXT_INT_Rising_Edge
				MCUCR_Reg |= (EXT_INT_Rising_Edge << 2);
	#endif
	
	#if		EXT_INT2_Mode == EXT_INT2_Falling_Edge
				MCUCSR_Reg |= (EXT_INT2_Falling_Edge << 6); 
	#elif	EXT_INT2_Mode == EXT_INT2_Rising_Edge
				MCUCSR_Reg |= (EXT_INT2_Rising_Edge << 6 );
	#endif	
	/*Choose What INT Is active*/
	#if		EXT_INT0_Init_State == EXT_INT_Disable_
				ClearBit(GICR_Reg,6);
	#elif	EXT_INT0_Init_State == EXT_INT_Enable_
				SetBit(GICR_Reg,6);
	#endif
	
	#if		EXT_INT1_Init_State == EXT_INT_Disable_
				ClearBit(GICR_Reg,7);
	#elif	EXT_INT1_Init_State == EXT_INT_Enable_
				SetBit(GICR_Reg,7);
	#endif
	
	#if		EXT_INT2_Init_State == EXT_INT_Disable_
				ClearBit(GICR_Reg,5);
	#elif	EXT_INT2_Init_State == EXT_INT_Enable_
				SetBit(GICR_Reg,5);
	#endif
	
	/*Clearing The flags*/
	SetBit(GIFR_Reg,5);
	SetBit(GIFR_Reg,6);
	SetBit(GIFR_Reg,7);
}
/*Global Int*/
void EXT_INT_Enable()
{
	Global_INT_Enable();
}
void EXT_INT_Disable()
{
	Global_INT_Disable();
}
/*Enable Functions*/
void EXT_INT0_Enable()
{
	SetBit(GICR_Reg,6);
}
void EXT_INT1_Enable()
{
	SetBit(GICR_Reg,7);

}
void EXT_INT2_Enable()
{
	SetBit(GICR_Reg,5);

}
/*Disable */
void EXT_INT0_Disable()
{
	ClearBit(GICR_Reg,6);
}
void EXT_INT1_Disable()
{
	ClearBit(GICR_Reg,7);
}
void EXT_INT2_Disable()
{
	ClearBit(GICR_Reg,5);	
}

/*CallBack Function*/
void EXT_INT0_SetCallback(void (*CopyFuncPtr) (void))
{
	CallBackPtr0= CopyFuncPtr;
}
void EXT_INT1_SetCallback(void (*CopyFuncPtr) (void))
{
	CallBackPtr1= CopyFuncPtr;
}
void EXT_INT2_SetCallback(void (*CopyFuncPtr) (void))
{
	CallBackPtr2= CopyFuncPtr;
}

/*ISR EXT0*/
void __vector_1(void)__attribute__((signal,used)); 
void __vector_1(void)
{
	if (CallBackPtr0 != NULL)
	{
		CallBackPtr0();
	}
}
/*ISR EXT1*/
void __vector_2(void)__attribute__((signal,used));
void __vector_2(void)
{
	if (CallBackPtr1 != NULL)
	{
		CallBackPtr1();
	}
}
/*ISR EXT2*/
void __vector_3(void)__attribute__((signal,used));
void __vector_3(void)
{
	if (CallBackPtr2 != NULL)
	{
		CallBackPtr2();
	}
}