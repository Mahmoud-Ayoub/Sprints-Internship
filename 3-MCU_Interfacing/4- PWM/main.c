/*
 * pwm.c
 *
 * Author : Mahmoud Ayoub
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "pwm.h"

void main()
{
	DDRB |= (1<<PB3);
	pwm_init(INVERTING_MODE , 1024) ;
	uint8 per = 50 ; 
	
	while(1)
	{
		pwm_SetSpeed (90) ;    
	}
}
