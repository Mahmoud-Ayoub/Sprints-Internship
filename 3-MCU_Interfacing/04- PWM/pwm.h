/*
 * pwm.h
 *
 *  Author: Mahmoud Ayoub
 */ 


#ifndef PWM_H_
#define PWM_H_
#include "Std_Types.h"

#define T0_Control_REG			(*((volatile uint8*)0x53))
#define T0_Data_REG			(*((volatile uint8*)0x52))
#define T0_OutCmp_REG			(*((volatile uint8*)0x5C))
#define T0_INTMask_REG			(*((volatile uint8*)0x59))
#define T0_Status_REG			(*((volatile uint8*)0x58))

#define NON_INVERTING_MODE 0
#define INVERTING_MODE 1

void pwm_init (uint8 mode , uint16 prescalar) ; 
void pwm_SetSpeed (uint8 percentage) ; 



#endif /* PWM_H_ */