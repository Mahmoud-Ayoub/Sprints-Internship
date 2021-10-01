/*
 * Master_sender.c
 *
 * Author : Mahmoud Ayoub
 */ 

#include "./HAL/Terminal/Terminal.h"
#include "./HAL/SPI_sender/SPI_sender.h"

int main(void)
{
	unsigned char key ;
	unsigned char message[256] =  {0} ;			// array of characters for user message
	unsigned char counter = 0 ;
	unsigned char loop_iterator = 0 ;
	
	// Terminal initialization
	Terminal_init(9600 , _1_BIT , _8_BITS) ;
	
	// SPI Sender initialization 
	SPI_Sender_init(Fosc_2) ;

    while (1) 
    {
		key = Terminal_Receive_Char() ;
		Terminal_Send_Char(key) ;
		
		if ( key != 0x0D) {		// user doesn't press "Enter" key to finish entering message yet
			message[counter] = key ;
			counter ++ ;
		}
		if (key == 32) {		// user entered a space 
			SPI_Sender_Send_Char(key) ; 
		}
		else if (key == 0x0D) {
			if (counter <= 255) {
				SPI_Sender_Send_Char(0x0D) ;
				for (loop_iterator = 0 ; loop_iterator <= counter ; loop_iterator ++) {	// send string over SPI char by char
					SPI_Sender_Send_Char(message[loop_iterator]) ;
					Terminal_Send_Char(0) ;
				}
				Terminal_Send_Char(0x0D) ;
				counter = 0 ;
				for (loop_iterator = 0 ; loop_iterator <10 ; loop_iterator ++) {	// send string as a char by char
					message[loop_iterator] = 0 ;
				}
			}
			else {
				SPI_Sender_Send_Char(0) ; 
			}
		}	
	}
}

