/*
 * WDT_Types.h
 *
 * Created: 24/06/2023 01:01:58 ص
 *  Author: The7ag
 */ 


#ifndef WDT_TYPES_H_
#define WDT_TYPES_H_

#define WDP0	0
#define WDP1	1
#define WDP2	2
#define WDE		3
#define WDTOE	4

#define WDT_TIME_OUT_SELECT_MASK  0b11111000
#define WDT_TIME_OUT_SELECT_SHIFT  0

#define WDT_16K_TIME_OUT16_3ms    0
#define WDT_32K_TIME_OUT32_5ms    1
#define WDT_64K_TIME_OUT65ms      2
#define WDT_128K_TIME_OUT0_13s    3
#define WDT_256K_TIME_OUT0_26s    4
#define WDT_512K_TIME_OUT0_52s    5
#define WDT_1024K_TIME_OUT1s      6
#define WDT_2048K_TIME_OUT2_1s    7

/*
 * To Enable or disable the Watchdog timer
 */
#define ENABLE  1
#define DISABLE 0

#endif /* WDT_TYPES_H_ */