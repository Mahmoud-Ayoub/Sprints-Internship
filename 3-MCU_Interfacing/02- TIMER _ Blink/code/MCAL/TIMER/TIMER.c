/*
 * TIMER.c
 *
 *  Author: Mahmoud Ayoub
 */ 
#include "TIMER.h"

void TIMER1_init (void) {
	SET_BIT(TC1_Control_B_REG , 1) ;         //set the pre-scalar as 8   ,  freq = 1 MHz
	TC1_Data_H_REG = 0x6D ;					// delay ticks = 65535 - (delay_ms * 1000 * 1) / 8 = 28035
	TC1_Data_L_REG = 0x83 ;  
}
uint8 TIMER1_end (void) {
	while((TC1_Status_REG & (1<<2)) == 0);	// wait till the overflow of A flag is SET
	return 1 ; 
}
void TIMER1_reset (void) {
	TC1_Data_H_REG = 0x6D ;
	TC1_Data_L_REG = 0x83 ;
	SET_BIT (TC1_Status_REG , 2) ;   //clear timer1 overflow flag
}