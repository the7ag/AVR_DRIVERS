/*
 * ADC.c
 *
 * Created: 03/02/2023 10:03:23 م
 *  Author: The7ag
 */ 
#include "ADC.h"
static void (*CallBackPtr) (void) = NULL;
void ADC_Init()
{
	/************************************************************************/
	/*             	Selecting The Voltage Ref                            */
	/************************************************************************/
	ADMUX_Reg &= ADC_Voltage_Ref_clr_msk;
	ADMUX_Reg |= ADC_Voltage_Ref_Selector;
	/************************************************************************/
	/*             	Selecting The ADC Mode								 */
	/************************************************************************/
	#if ADC_Mode_Selector	==	ADC_Mode_Auto_Trigger
		SetBit(ADCSRA_Reg,5);
		SFIOR_Reg &= ADC_AUTO_TRIG_SRC_clr_msk;
		SFIOR_Reg |= ADC_Auto_Trig_Src_Selector;
	#elif ADC_Mode_Selector==ADC_Mode_Single_Conversion
		ClearBit(ADCSRA_Reg,5);
	#endif
	/************************************************************************/
	/*             	Selecting The Adjustment		                          */
	/************************************************************************/
	#if		ADC_Adjustment_Selector == ADC_Right_Adjusted
				ClearBit(ADMUX_Reg,5);
	#elif	ADC_Adjustment_Selector == ADC_Left_Adjusted
				SetBit(ADMUX_Reg,5);
	#endif
	/************************************************************************/
	/*             	Clearing the interrupt flag		                    */
	/************************************************************************/
	 SetBit(ADCSRA_Reg,4);
	/************************************************************************/
	/*             	Enabling ADC											 */
	/************************************************************************/
	SetBit(ADCSRA_Reg,7);
}
void ADC_StartConversion(ADC_Channel_types Channel)
{
	/*Select Adc Channel*/
	ADMUX_Reg &= ADC_Channel_Selector_clr_msk;
	ADMUX_Reg |= Channel;
	/*Start the Conversion*/
	SetBit(ADCSRA_Reg,6);
}
uint16 ADC_GetResult()
{
	#if ADC_Mode_Selector	==	ADC_Mode_Auto_Trigger
		return ADCLH_Reg;
	#elif ADC_Mode_Selector ==  ADC_Mode_Single_Conversion
		while (ReadBit(ADCSRA_Reg,6));
		SetBit(ADCSRA_Reg,4);
		return ADCLH_Reg;
	#endif

}
uint16 analogRead(ADC_Channel_types Channel)
{
	ADC_StartConversion(Channel);
	return ADC_GetResult();
}
/*Enable*/
void ADC_INT_Enable()
{
	SetBit(ADCSRA_Reg,3);
}
/*Disable */
void ADC_INT_Disable()
{
	ClearBit(ADCSRA_Reg,3);
}
/*CallBack Functions*/
void ADC_INT_SetCallback(void (*CopyFuncPtr) (void))
{
	CallBackPtr = CopyFuncPtr;
}
void __vector_16(void) __attribute__((signal,used));
void __vector_16()
{
	if (CallBackPtr != NULL)
	{
		CallBackPtr();
	}
}