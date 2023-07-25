/*
 * WDT.c
 *
 * Created: 24/06/2023 01:07:01 ص
 *  Author: The7ag
 */ 
#include "WDT.h"
void WDT_Init_Preduild(void)
{
		WDTCR_Reg&=WDT_TIME_OUT_SELECT_MASK;
		WDTCR_Reg|=WDT_TIME_OUT<<WDT_TIME_OUT_SELECT_SHIFT;
		#if(WDT_INITIAL_STATE==ENABLE)
		{
			SetBit(WDTCR_Reg,WDE);
		}
		#endif
}
void WDT_Enable_Postbuild(void)
{
	SetBit(WDTCR_Reg,WDE);
}
void WDT_Disable_Postbuild()
{
	WDTCR_Reg |=0b00011000;
	ClearBit(WDTCR_Reg,WDE);
}
void WDT_SleepTimeOut_Postbuild(uint8_t Copy_TimeOut)
{
	uint8_t Timeout_temp=WDTCR_Reg;
	Timeout_temp&=WDT_TIME_OUT_SELECT_MASK;
	Timeout_temp |= Copy_TimeOut;
	WDTCR_Reg=Timeout_temp;
}
