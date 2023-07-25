/*
 * Algo.c
 *
 * Created: 24/06/2023 10:47:31 م
 *  Author: The7ag
 */ 
#include "Algo.h"
void reverseString(uint8_t* str) {
	uint16 length = strlen(str);
	uint16 i, j;
	uint8_t temp;
	for (i = 0, j = length - 1; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}