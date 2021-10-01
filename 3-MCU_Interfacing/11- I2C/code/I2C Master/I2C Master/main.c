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
	
	I2C_Master_init(1 , _1_div);  // Function to initialize TWI
	while(1)
	{		
		I2C_start() ;  // Function to send start condition
		I2C_write_address(0x10) ; // Function to write address and data direction bit(write) on SDA
		I2C_Master_write_data(4);      // Function to write data in slave
		I2C_stop(); // Function to send stop condition
		
	}
}
