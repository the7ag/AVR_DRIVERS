/*
 * ADC_config.h
 *
 * Created: 03/02/2023 10:04:44 م
 *  Author: The7ag
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_
#include "ADC_types.h"
/*
Configure The Voltage Ref
 ADC_Voltage_Ref_AVCC		 
 ADC_Voltage_Ref_AREF		
 ADC_Voltage_Ref_2_56_VCC
*/
#define ADC_Voltage_Ref_Selector		ADC_Voltage_Ref_AVCC
#define ADC_Voltage_Ref_mv				5000
#define ADC_Max_Number_Of_Steps			1024
/*
Configure The ADC mode
ADC_Mode_Auto_Trigger		
ADC_Mode_Single_Conversion  
*/
#define ADC_Mode_Selector				ADC_Mode_Auto_Trigger
/*
Configure The ADC Adjustment
ADC_Right_Adjusted			
ADC_Left_Adjusted			
*/
#define ADC_Adjustment_Selector			ADC_Right_Adjusted
/*
Configure The ADC Prescaler
ADC_PreSclr_clr_msk			
ADC_PreSclr_2_msk			
ADC_PreSclr_4_msk		
ADC_PreSclr_8_msk			
ADC_PreSclr_16_msk			
ADC_PreSclr_32_msk			
ADC_PreSclr_64_msk			
ADC_PreSclr_128_msk			
*/
#define ADC_PreScaler_Selector			ADC_PreSclr_128_msk

/*
Configure The ADC Trigger Signal Source
ADC_AUTO_TRIG_SRC_clr_msk			
ADC_AUTO_TRIG_SRC_Free_Running_msk	
ADC_AUTO_TRIG_SRC_Analog_Comp_msk	
ADC_AUTO_TRIG_SRC_EXT_I0_msk		
ADC_AUTO_TRIG_SRC_Timer0_Comp_msk	
ADC_AUTO_TRIG_SRC_Timer0_OVF_msk	
ADC_AUTO_TRIG_SRC_Timer1_Comp_msk	
ADC_AUTO_TRIG_SRC_Timer1_OVF_msk	
ADC_AUTO_TRIG_SRC_Timer1_Capt_msk	
*/

#define ADC_Auto_Trig_Src_Selector		ADC_AUTO_TRIG_SRC_Free_Running_msk

#endif /* ADC_CONFIG_H_ */