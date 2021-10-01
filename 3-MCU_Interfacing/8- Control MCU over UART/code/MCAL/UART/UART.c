/*
 * UART.c
 *
 *  Author: Mahmoud Ayoub
 */ 
#include "UART.h"

/*
Description : The function initializes UART module with the specified baud rate , data frame
inputs		: baud rate , no of stop bits required (_1_BIT , _2_BITS) , data size required (_5_BITS , _6_BITS , _7_BITS , _8_BITS)
outputs		: none
*/
void UART_init (unsigned int baud_rate , EN_STOP_BITS stop_bits , EN_DATA_SIZE data_size) {
	/* Turn on transmission and reception */
	UART_UCSRB |= (1 << 4) | (1 << 3) ; 
	
	/*  setting frame format */
	
	if (stop_bits == _1_BIT){
		switch (data_size) {
			case _5_BITS : 
				UART_UCSRC = 0b10000000 ; 
				break;
				
			case _6_BITS :
				UART_UCSRC = 0b10000010 ;
				break;
				
			case _7_BITS :
				UART_UCSRC = 0b10000100 ;
				break;
				
			case _8_BITS :
				UART_UCSRC = 0b10000110 ;
				break;	
		}
	}
	else if (stop_bits == _2_BITS) {
		switch (data_size) {
			case _5_BITS :
				UART_UCSRC = 0b10001000 ;
				break;
			
			case _6_BITS :
				UART_UCSRC = 0b10001010 ;
				break;
			
			case _7_BITS :
				UART_UCSRC = 0b10001100 ;
				break;
			
			case _8_BITS :
				UART_UCSRC = 0b10001110 ;
				break;
		}
	}
	unsigned int baud_prescale ; 
	baud_prescale = ((F_CPU / (16UL*baud_rate))-1) ; 
	UART_UBRRL = baud_prescale ; 
	UART_UBRRH = baud_prescale >> 8 ; 
}
/*
Description : The function waits for the transmit buffer to be empty by checking the UDRE Flag, before loading it with new data to be transmitted.
inputs		: data to be transmitted
outputs		: none
*/
void UART_Transmit_Char (unsigned char data) {
	/*
	 (UDRE) Flag indicates whether the transmit buffer is ready to receive new data. 
	 This bit is set when the transmit buffer is empty, and cleared when the transmit buffer
	 contains data to be transmitted that has not yet been moved into the Shift Register
	*/
 	while ( (UART_UCSRA & (1<<5)) == 0) ;	/* Wait for empty transmit buffer*/
 	UART_UDR = data ;
}

/*
Description : The function for transmitting a string as a character by character.
inputs		: string to be transmitted
outputs		: none
*/
void UART_Transmit_String (unsigned char* str) {
	unsigned char counter = 0 ; 
	while (str[counter] != 0) {
		UART_Transmit_Char(str[counter]) ; 
		counter ++ ; 
	}
}
/*
Description : The function waits for data to be present in the receive buffer by checking the RXC Flag, 
			   before reading the buffer and returning the value
inputs		: none
outputs		: received data
*/
unsigned char UART_Receive_Char (void) {
	while ( (UART_UCSRA & (1<<7)) == 0) ;	/* Wait till data is received */
	return UART_UDR ; 
}