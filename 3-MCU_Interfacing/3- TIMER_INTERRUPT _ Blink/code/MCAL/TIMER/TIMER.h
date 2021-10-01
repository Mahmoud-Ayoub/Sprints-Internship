/*
 * TIMER.h
 *
 *  Author: Mahmoud Ayoub
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "D:\Sprints iCamp\5- MCU interfacing\Blink_LED\Blink_LED\MCAL\Std_Types.h"
#include "D:\Sprints iCamp\5- MCU interfacing\Blink_LED\Blink_LED\MCAL\Bit_Math.h"

#define TC1_Control_A_REG					(*((volatile uint8*)0x4F))
#define TC1_Control_B_REG					(*((volatile uint8*)0x4E))
#define TC1_Data_L_REG						(*((volatile uint8*)0x4C))
#define TC1_Data_H_REG						(*((volatile uint8*)0x4D))
#define TC1_OutputCompare_A_L_REG			(*((volatile uint8*)0x4A))
#define TC1_OutputCompare_A_H_REG			(*((volatile uint8*)0x4B))
#define TC1_OutputCompare_B_L_REG			(*((volatile uint8*)0x48))
#define TC1_OutputCompare_B_H_REG			(*((volatile uint8*)0x49))
#define TC1_Status_REG						(*((volatile uint8*)0x58))
#define TC1_INTMask_REG						(*((volatile uint8*)0x59))


void TIMER1_init (void) ;     
uint8 TIMER1_end (void) ; 
void TIMER1_reset (void) ; 



#endif /* TIMER_H_ */