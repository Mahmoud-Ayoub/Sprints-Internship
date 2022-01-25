/*
 * Blink_LED_with_Timer_INT.c
 *
 * Author : Mahmoud Ayoub
 */ 

#include<avr/io.h>
#include<avr/interrupt.h>
#include "D:\Sprints iCamp\5- MCU interfacing\Blink_LED_with_Timer_INT\Blink_LED_with_Timer_INT\HAL\LED\LED.h"
#include "D:\Sprints iCamp\5- MCU interfacing\Blink_LED_with_Timer_INT\Blink_LED_with_Timer_INT\MCAL\INTERRUPT\Interrupt.h"

int main()
{
	
	LED_init(portA , 0) ; 
	LED_OFF(portA , 0) ; 
	TIMER1_init() ; 
	INT_Timer_Enable() ; 
	INT_global_Enable() ; 
	cb_func(LED_TOGGLE) ;  
	while(1)
	{
		
	}
}
