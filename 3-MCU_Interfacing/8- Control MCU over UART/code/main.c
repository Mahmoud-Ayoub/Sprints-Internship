/*
 * Control MCU over UART.c
 *
 * Author : Mahmoud Ayoub
 */ 

#include "./HAL/Terminal/Terminal.h"
#include "./HAL/LED/LED.h"
#include "string.h"

#define LED_GREEN		portA,0
#define LED_YELLOW		portA,1
#define LED_RED			portA,2

int main(void)
{
	uint8 key ;
	uint8 command[10] =  {0} ;			// array of characters for user command
	uint8 counter = 0 ;
	uint8 loop_iterator = 0 ; 
	
	// LEDs initialization
	LED_init(LED_GREEN) ;			// Green LED
	LED_init(LED_YELLOW) ;			// Yellow LED
	LED_init(LED_RED) ;				// RED LED
	
	// LEDs first state are OFF
	LED_OFF (LED_GREEN) ;
	LED_OFF (LED_YELLOW) ;
	LED_OFF (LED_RED) ;
	
	// Terminal initialization
	Terminal_init(9600 , _1_BIT , _8_BITS) ;
	
    while (1) 
    {
		key = Terminal_Receive_Char() ; 
		Terminal_Send_Char(key) ;
		if ( (key != 32) && (key >= 65) && (key <= 122) ) {		// user doesn't enter space key to finish entering command yet
			command[counter] = key ; 
			counter ++ ; 
		}
		else if (key == 32) {									// user enters space key to finish entering command
			// check for commands to take an action
			
			// START command
			if (strcmp(command , "START") == 0) {
				Terminal_Send_String("Green LED is ON ") ;
				LED_ON(LED_GREEN) ;
				LED_OFF(LED_YELLOW) ;
				LED_OFF(LED_RED) ;
			}
			
			// WAIT command
			else if (strcmp(command , "WAIT") == 0) {
				Terminal_Send_String("Yellow LED is ON ") ;
				LED_ON(LED_YELLOW) ;
				LED_OFF(LED_GREEN) ;
				LED_OFF(LED_RED) ; 
			}
			
			// STOP command
			else if (strcmp(command , "STOP") == 0) {
				Terminal_Send_String("Red LED is ON ") ;
				LED_ON(LED_RED) ;
				LED_OFF(LED_YELLOW) ;
				LED_OFF(LED_GREEN) ; 
			}
			
			// AT command
			else if (strcmp(command , "AT") == 0) {
				Terminal_Send_String("OK ") ;
				LED_OFF (LED_GREEN) ;
				LED_OFF (LED_YELLOW) ;
				LED_OFF (LED_RED) ;
			}
	
			counter = 0 ; 
			for (loop_iterator = 0 ; loop_iterator <10 ; loop_iterator ++) {
				command[loop_iterator] = 0 ; 
			}
		}
    }
}

