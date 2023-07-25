/*
 * WDT.h
 *
 * Created: 24/06/2023 01:06:53 ص
 *  Author: The7ag
 */ 


#ifndef WDT_H_
#define WDT_H_
#include "WDT_Reg.h"
#include "WDT_Config.h"
#include "../DIO/DIO.h"

void WDT_Init_Preduild(void);
void WDT_Enable_Postbuild(void);
void WDT_Disable_Postbuild();
void WDT_SleepTimeOut_Postbuild(uint8_t Copy_TimeOut);

#endif /* WDT_H_ */