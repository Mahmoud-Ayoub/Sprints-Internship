/*
 * I2C Master
 *
 *  Author: Mahmoud Ayoub
 */

#include "I2C.h"

#define DDRB_REG			(*((volatile unsigned char*)0x37))
#define PORTB_REG			(*((volatile unsigned char*)0x38))
#define PINB_REG			(*((volatile unsigned char*)0x36))

int main(void)
{
	DDRB_REG = 0xFF ;
	I2C_Slave_init(0x10) ;  // Function to initialize slave
	while(1)
	{
		I2C_Slave_match_read() ; 
		PORTB_REG = I2C_Slave_read_data() ; // Function to read data
	}
}
