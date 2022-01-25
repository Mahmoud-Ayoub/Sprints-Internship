/*
 * Blink_LED.c
 *
 * Author : Mahmoud Ayoub
 */ 

#include "D:\Sprints iCamp\5- MCU interfacing\Blink_LED\Blink_LED\HAL\LED\LED.h"
#include "D:\Sprints iCamp\5- MCU interfacing\Blink_LED\Blink_LED\MCAL\TIMER\TIMER.h"

int main(void)
{
	
	LED_init(portA , 0) ;
	LED_OFF (portA , 0) ; 
	TIMER1_init () ; 
	
	while(1)
	{
		//If flag is set toggle the led
		while(TIMER1_end() == 0);// wait till the timer overflow flag is SET
		LED_TOGGLE(portA , 0) ; 
		TIMER1_reset() ; 
	}
}

