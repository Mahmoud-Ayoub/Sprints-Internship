/*
 * SPI.c
 *
 *  Author: Mahmoud Ayoub
 */ 

#include "SPI.h"

/*
Description : function to initialize SPI master with specified clock
inputs		: required clock
outputs		: none
*/

void SPI_Master_init (EN_SCK clock) {
	// configure SS , MOSI , SCK as an output
	DDRB_REG |= (1 << SS) | (1 << MOSI) | (1 << SCK) ; 
	
	PORTB_REG |= (1<<SS);			/* Make high on SS pin */
	
	// configure MISO as an input 
	DDRB_REG &= ~(1 << MISO) ; 
	
	// Enable SPI , Master , initiate clock
	switch (clock) {
		case Fosc_4 :
			SPCR |= (1 << SPE) | (1 << MSTR) ;
			break;
			
		case Fosc_16 : 
			 SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0) ;
			 break;
			 
		case Fosc_64 : 
			SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR1) ;
			break;
			
		case Fosc_128 :
			SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0) ;
			break;
			
		case Fosc_2 :
			SPCR |= (1 << SPE) | (1 << MSTR) ;
			SPSR |= (1 << SPI2X) ; 
			break;
		
		case Fosc_8 :
			SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR0) ;
			SPSR |= (1 << SPI2X) ; 
			break;
		
		case Fosc_32 :
			SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR1) ;
			SPSR |= (1 << SPI2X) ; 
			break;
	}
}

/*
Description : function to initialize SPI slave 
inputs		: none
outputs		: none
*/
void SPI_Slave_init (void) {
	// configure SS , MOSI , SCK as an input
	DDRB_REG &= ~((1 << SS) | (1 << MOSI) | (1 << SCK)) ;
	
	// configure MISO as an output
	DDRB_REG |= (1 << MISO) ;
	
	// Enable SPI
	SPCR |= (1 << SPE) ; 
}

/*
Description : function to transmit character data over SPI 
inputs		: character data to be sent 
outputs		: none
*/
void SPI_Transmit_Char (unsigned char data) {
	PORTB_REG &= ~(1<<SS);			/* Make low on SS pin */
	SPDR = data ; 
	while((SPSR & (1<<SPIF)) == 0);  // wait until transmission is complete

}

/*
Description : function to transmit string data over SPI
inputs		: string data to be sent
outputs		: none
*/
void SPI_Transmit_String (unsigned char* str) {
	unsigned char counter = 0 ;
	while (str[counter] != 0) {
		SPI_Transmit_Char(str[counter]) ;
		counter ++ ;
	}
}

/*
Description : function to receive character data over SPI
inputs		: none
outputs		: character data received 
*/
unsigned char SPI_Receive_Char (void) {
	while((SPSR & (1<<SPIF)) == 0);  // wait until reception is complete
	return SPDR ; 
}