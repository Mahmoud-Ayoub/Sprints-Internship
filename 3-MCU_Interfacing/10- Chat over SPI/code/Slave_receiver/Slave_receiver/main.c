/*
 * Slave_receiver.c
 *
 * Author : Mahmoud Ayoub
 */ 
#include "./HAL/Terminal/Terminal.h"
#include "./HAL/SPI_receiver/SPI_receiver.h"

int main(void)
{
	unsigned char key = 0 ;
	
    // Terminal initialization
    Terminal_init(9600 , _1_BIT , _8_BITS) ;
    
    // SPI Receiver initialization
    SPI_Receiver_init() ;

	while (1) { 
		key = SPI_Receiver_Receive_Char() ; 
		if (key != 0) {
			Terminal_Send_Char(key) ;
		}	
	}
}

