/*
 * EXT_INT.h
 *
 * Created: 04/02/2023 11:09:24 م
 *  Author: The7ag
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_
#include "EXT_INT_reg.h"
#include "EXT_INT_types.h"
#include "EXT_INT_Config.h"
/*Init All the interrupts*/
void EXT_INT_init();
/*Global INT*/
void EXT_INT_Enable();
void EXT_INT_Disable();

/*Enable Functions*/
void EXT_INT0_Enable();
void EXT_INT1_Enable();
void EXT_INT2_Enable();
/*Disable */
void EXT_INT0_Disable();
void EXT_INT1_Disable();
void EXT_INT2_Disable();

/*CallBack Functions*/
void EXT_INT0_SetCallback(void (*CopyFuncPtr) (void));
void EXT_INT1_SetCallback(void (*CopyFuncPtr) (void));
void EXT_INT2_SetCallback(void (*CopyFuncPtr) (void));


void Interrupt();
#endif /* EXT_INT_H_ */