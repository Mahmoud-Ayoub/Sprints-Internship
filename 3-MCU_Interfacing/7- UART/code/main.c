/*
 * UART.c
 *
 * Author : Mahmoud Ayoub
 */ 

#include "UART.h"

int main()
{
	
	UART_init(9600 , _1_BIT , _8_BITS) ; 
	char name [10] ;
	char key_pressed ; 
	char counter = 0 ; 
	char loop_iterator = 0 ; 
	while (1) {
		key_pressed = UART_Receive_Char() ;
		UART_Transmit_Char(key_pressed) ; 
		if ( (key_pressed != 32) && (key_pressed >= 65) && (key_pressed <= 122) ) {				// user doesn't press a space button yet
			name[counter] = key_pressed ; 
			counter ++ ; 
		} 
		else if (key_pressed == 32) {														// user enters space key to finish entering command
			UART_Transmit_String(name) ; 
			counter = 0 ;
			for (loop_iterator=0 ; loop_iterator<10 ; loop_iterator++) {
				name[loop_iterator] = 0 ; 
			}  
		}
	}
}

