/*
 * Interrupt.c
 *
 *  Author: Mahmoud Ayoub
 */ 
#include "Interrupt.h"
void (*gpfun) (void) ;          // global pointer to function

void INT_global_Enable (void) {
	SET_BIT (Status_REG , 7) ; 
}
void INT_Timer_Enable (void) {
	SET_BIT (TC1_INTMask_REG , 2) ; 
}
void __vector_9(void)         // Timer1 ISR
{
	
	gpfun() ;
	TIMER1_reset() ;
}

void cb_func (void (*led_p_fun) (void)) {
	gpfun = led_p_fun ; 
}
