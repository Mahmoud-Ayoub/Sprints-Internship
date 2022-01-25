/*
 * Toggle_LED.c
 * Author : Mahmoud Ayoub
 */ 

#include "D:\Sprints iCamp\5- MCU interfacing\Toggle_LED\Toggle_LED\HAL\LED\LED.h"
#include "D:\Sprints iCamp\5- MCU interfacing\Toggle_LED\Toggle_LED\HAL\Push_Button\PB.h"


int main(void)
{
	uint8 pb_value ; 
	LED_init(portA , 0) ; 
	PB_init(portC , 0) ; 
    while (1) 
    {
		// when pb is pressed , Toggle LED
		pb_value = PB_read(portC , 0) ; 
		if (pb_value == 1) {
			LED_TOGGLE(portA , 0) ; 
		}
    }
}

