/*
 * Keypad.h
 *
 *  Author: Mahmoud Ayoub
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_ 

#include "../../MCAL/DIO/DIO_Config.h"
#include <util/delay.h>

#define OUTPUT_ROW  PORTD_REG						// LSB is rows (OUTPUTS)
#define INPUT_COL	PIND_REG >> 4					// MSB is columns (INPUTS)

void KEYPAD_init (void) ; 
char KEYPAD_read (void) ;
void KEYPAD_wait (void) ; 

#endif /* KEYPAD_H_ */