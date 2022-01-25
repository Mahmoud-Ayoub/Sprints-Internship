/*
 * TIMER.c
 *
 *  Author: Mahmoud Ayoub
 */ 
#include "TIMER.h"

void TIMER1_init (void) {
	TC1_Control_B_REG |= (0b11 << 0) ;		//set the pre-scalar as 64   ,  freq = 1 MHz         
	TC1_Data_H_REG = 0x00 ;					// delay ticks = 65535 starting from 0
	TC1_Data_L_REG = 0x00 ;  
}
uint8 TIMER1_end (void) {
	if ((TC1_Status_REG & (1<<2)) == 0) {		// timer doesn't finish yet
		return 0 ; 
	}
	else {										// timer finished
		return 1 ; 
	} 
}
void TIMER1_reset (void) {
	TC1_Data_H_REG = 0x00 ;
	TC1_Data_L_REG = 0x00 ;
	SET_BIT (TC1_Status_REG , 2) ;   //clear timer1 overflow flag
}