/*
 * pwm.c
 *
 *  Author: Mahmoud Ayoub
 */ 
#include "pwm.h"

void pwm_init (uint8 mode , uint16 prescalar) {
	if (mode == NON_INVERTING_MODE) {		// fast pwm - non inverting mode
		switch (prescalar) {
			case 0 : 
				T0_Control_REG |= 0x69 ;
				break ;
			case 8 : 
				T0_Control_REG |= 0x6A ;
				break ;
			case 64 : 
				T0_Control_REG |= 0x6B ;
				break ;
			case 256 :
				T0_Control_REG |= 0x6C ;
				break ;
			case 1024 :
				T0_Control_REG |= 0x6D ;
				break ;
		}
	}
	else if (mode == INVERTING_MODE) {		// fast pwm - inverting mode
		switch (prescalar) {	
			case 0 :
				T0_Control_REG |= 0x79 ;
				break ;
			case 8 :
				T0_Control_REG |= 0x7A ;
				break ;
			case 64 :
				T0_Control_REG |= 0x7B ;
				break ;
			case 256 :
				T0_Control_REG |= 0x7C ;
				break ;
			case 1024 :
				T0_Control_REG |= 0x7D ;
				break ;
		}
	}
}
void pwm_SetSpeed (uint8 percentage) {
	uint8 duty_cycle = 255 * percentage / 100 ; 
	T0_OutCmp_REG = duty_cycle ; 
}