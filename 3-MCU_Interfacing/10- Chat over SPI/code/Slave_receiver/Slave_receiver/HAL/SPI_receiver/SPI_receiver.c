/*
 * SPI_receiver.c
 *
 *  Author: Mahmoud Ayoub
 */ 

#include "SPI_receiver.h"

/*
Description : function to initialize MCU as receiver
inputs		: none
outputs		: none	 
*/
void SPI_Receiver_init (void) {
	SPI_Slave_init() ;
}

/*
Description : function to get data sent over SPI
inputs		: none
outputs		: received char  
*/
unsigned char SPI_Receiver_Receive_Char (void) {
	return SPI_Receive_Char() ;
}