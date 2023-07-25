/*
 * ADC_types.h
 *
 * Created: 03/02/2023 10:04:19 م
 *  Author: The7ag
 */ 


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_



/*Voltage Ref*/
#define ADC_Voltage_Ref_clr_msk			0b00111111 //For And to clear the mask
#define ADC_Voltage_Ref_AVCC			0b01000000 //OR
#define ADC_Voltage_Ref_AREF			0b00000000
#define ADC_Voltage_Ref_2_56_VCC		0b11000000

/*Trigger Mode*/
#define ADC_Mode_Auto_Trigger			1
#define ADC_Mode_Single_Conversion		0
/*Saving Mode*/
#define ADC_Right_Adjusted				0
#define ADC_Left_Adjusted				1
/*PreScalar Selection*/
#define ADC_PreSclr_clr_msk				0b11111000 //And
#define ADC_PreSclr_2_msk				0b00000000 //OR
#define ADC_PreSclr_4_msk				0b00000010
#define ADC_PreSclr_8_msk				0b00000011
#define ADC_PreSclr_16_msk				0b00000100
#define ADC_PreSclr_32_msk				0b00000101
#define ADC_PreSclr_64_msk				0b00000110
#define ADC_PreSclr_128_msk				0b00000111

/*Trigger Signal Source*/
#define ADC_AUTO_TRIG_SRC_clr_msk			0b00011111
#define ADC_AUTO_TRIG_SRC_Free_Running_msk	0b00000000
#define ADC_AUTO_TRIG_SRC_Analog_Comp_msk	0b00100000
#define ADC_AUTO_TRIG_SRC_EXT_I0_msk		0b01000000
#define ADC_AUTO_TRIG_SRC_Timer0_Comp_msk	0b01100000
#define ADC_AUTO_TRIG_SRC_Timer0_OVF_msk	0b10000000
#define ADC_AUTO_TRIG_SRC_Timer1_Comp_msk	0b10100000
#define ADC_AUTO_TRIG_SRC_Timer1_OVF_msk	0b11000000
#define ADC_AUTO_TRIG_SRC_Timer1_Capt_msk	0b11100000

/*Clear The channel*/
#define ADC_Channel_Selector_clr_msk		0b11100000

#endif /* ADC_TYPES_H_ */