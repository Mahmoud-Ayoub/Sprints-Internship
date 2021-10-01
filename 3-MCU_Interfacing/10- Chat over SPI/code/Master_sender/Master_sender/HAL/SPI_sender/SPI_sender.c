/*
 * SPI_sender.c
 *
 *  Author: Mahmoud Ayoub
 */ 

#include "SPI_sender.h"

/*
Description : function to initialize MCU as sender
inputs		: clock for master initialization 
outputs		: none
*/
void SPI_Sender_init (EN_SCK clock) {
	SPI_Master_init(clock) ; 
}

/*
Description : function to send char over SPI
inputs		: char to be sent
outputs		: none
*/
void SPI_Sender_Send_Char (unsigned char data) {
	SPI_Transmit_Char(data) ; 
}

/*
Description : function to send string over SPI
inputs		: string to be sent
outputs		: none
*/
void SPI_Sender_Send_String (unsigned char* str) {
	SPI_Transmit_String(str) ; 
}
