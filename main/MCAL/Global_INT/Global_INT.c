/*
 * Global_INT.c
 *
 * Created: 06/02/2023 03:18:07 م
 *  Author: The7ag
 */ 
#include "Global_INT.h"
void Global_INT_Enable()
{
	SetBit(SREG_Reg,Global_INT_ENABLE_BIT);
}
void Global_INT_Disable()
{
	ClearBit(SREG_Reg,Global_INT_ENABLE_BIT);
}