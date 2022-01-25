/*
 * Interrupt.h
 *
 *  Author: Mahmoud Ayoub
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "D:\Sprints iCamp\5- MCU interfacing\Blink_LED\Blink_LED\MCAL\Std_Types.h"
#include "D:\Sprints iCamp\5- MCU interfacing\Blink_LED\Blink_LED\MCAL\Bit_Math.h"
#include "D:\Sprints iCamp\5- MCU interfacing\Blink_LED_with_Timer_INT\Blink_LED_with_Timer_INT\MCAL\TIMER\TIMER.h"

#define Status_REG (*((volatile uint8*)0x5F))

void INT_global_Enable (void) ;
void INT_Timer_Enable (void) ; 
void __vector_9(void) __attribute__((signal));       // ISR for Timer 1 overflow
 

#endif /* INTERRUPT_H_ */