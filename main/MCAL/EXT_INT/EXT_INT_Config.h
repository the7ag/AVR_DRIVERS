/*
 * EXT_INT_Config.h
 *
 * Created: 04/02/2023 11:10:19 م
 *  Author: The7ag
 */ 


#ifndef EXT_INT_CONFIG_H_
#define EXT_INT_CONFIG_H_

#include "EXT_INT_types.h"
/*
Config When The interrupt 0 Mode
EXT_INT_Low_Level			
EXT_INT_Any_Logical			
EXT_INT_Falling_Edge	
EXT_INT_Rising_Edge			
*/
#define EXT_INT0_Mode			EXT_INT_Rising_Edge
/*
Config When The interrupt 1 Mode
EXT_INT_Low_Level
EXT_INT_Any_Logical
EXT_INT_Falling_Edge
EXT_INT_Rising_Edge
*/
#define EXT_INT1_Mode			EXT_INT_Falling_Edge
/*
Config When The interrupt 2 Mode
EXT_INT2_Falling_Edge
EXT_INT2_Rising_Edge
*/
#define EXT_INT2_Mode			EXT_INT2_Falling_Edge

/*
Configure The Ext interrupt Status
EXT_INT_Enable_
EXT_INT_Disable_		
*/
#define EXT_INT0_Init_State		EXT_INT_Disable_
#define EXT_INT1_Init_State		EXT_INT_Disable_
#define EXT_INT2_Init_State		EXT_INT_Disable_


#endif /* EXT_INT_CONFIG_H_ */