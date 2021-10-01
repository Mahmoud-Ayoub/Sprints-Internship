/*
 * I2C.c
 *
 *  Author: Mahmoud Ayoub
 */ 
#include "I2C.h"

/*
Description : function to initialize the master to generate clock
inputs		: required bit rate value , required prescaler 
outputs		: none
*/
void I2C_Master_init (unsigned char bit_rate_value , EN_PRESCALER prescaler) {
	TWBR = bit_rate_value ; 
	switch (prescaler) {
		case _1_div :
			TWSR |= (0b00 << 0) ; 
			break ;
		
		case _4_div :
			TWSR |= (0b01 << 0) ;
			break ;
			
		case _16_div :
			TWSR |= (0b10 << 0) ;
			break ;
			
		case _64_div :
			TWSR |= (0b11 << 0) ;
			break ;
	}
}

/*
Description : function to initialize the slave with the specified address
inputs		: slave address
outputs		: none
*/
void I2C_Slave_init (unsigned char slave_address) {
	TWAR = slave_address ; 
}

/*
Description : function to send start bit by master
inputs		: none
outputs		: none
*/
void I2C_start (void) {
	// Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	TWCR = (1 << TWINT)|(1 << TWSTA)|(1 << TWEN);
	
	// Wait till start condition is transmitted
	while (!(TWCR & (1 << TWINT))) ; 
	
	// Check for the acknowledgment
	while ((TWSR & 0xF8) != START_TRANSMIT_ACK) ; 
}

/*
Description : function to send a repeated start bit by master
inputs		: none
outputs		: none
*/
void I2C_repeated_start (void) {
	// Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	TWCR = (1 << TWINT)|(1 << TWSTA)|(1 << TWEN);
	
	// Wait till start condition is transmitted
	while (!(TWCR & (1 << TWINT))) ;
	
	// Check for the acknowledgment
	while ((TWSR & 0xF8) != REPEATED_START_TRANSMIT_ACK) ;
}

/*
Description : function to send stop bit by master
inputs		: none
outputs		: none
*/
void I2C_stop (void) {
	// Clear TWI interrupt flag, Put start condition on SDA, Enable TWI
	TWCR = (1 << TWINT)|(1 << TWSTO)|(1 << TWEN);
	
	// Wait till stop condition is transmitted
	while (!(TWCR & (1 << TWSTO))) ;
}

/*
Description : function to send slave address and operation required (WRITE) by master 
inputs		: slave address
outputs		: none
*/
void I2C_write_address (unsigned char slave_address) {
	// Address and write instruction
	TWDR = slave_address + WRITE ; 
	
	// Clear TWI interrupt flag,Enable TWI
	TWCR |= (1 << TWINT) | (1 << TWEN) ; 
	
	// Wait till complete TWDR byte transmitted
	while (!(TWCR & (1 << TWINT))) ;
	
	// Check for the acknowledgment
	while ((TWSR & 0xF8) != ADDR_OP_ACK) ;
}

/*
Description : function to send byte data by master (Master - Sender)
inputs		: none
outputs		: none
*/
void I2C_Master_write_data (unsigned char data) {
	TWDR = data ; 
	
	// Clear TWI interrupt flag,Enable TWI
	TWCR |= (1 << TWINT) | (1 << TWEN) ;
	
	// Wait till complete TWDR byte transmitted
	while (!(TWCR & (1 << TWINT))) ;
	
	// Check for the acknowledgment
	while ((TWSR & 0xF8) != M_DATA_TRANSMIT_ACK) ;
}

/*
Description : function to receive byte data by master (Master - Receiver)
inputs		: none
outputs		: none
*/
unsigned char I2C_Master_read_data (void) {
	// Clear TWI interrupt flag,Enable TWI
	TWCR |= (1 << TWINT) | (1 << TWEN) ;
	
	// Wait till complete TWDR byte transmitted
	while (!(TWCR & (1 << TWINT))) ;
	
	// Check for the acknowledgment
	while ((TWSR & 0xF8) != M_DATA_RECEIVE_ACK) ;
	
	return TWDR ; 
}

/*
Description : function to acknowledge the slave address has been matched
inputs		: none
outputs		: none
*/
void I2C_Slave_match_read (void) {
	while ((TWSR & 0xF8) != S_ADDR_RECEIVE_ACK) {
		// Clear TWI interrupt flag,Enable TWI
		TWCR |= (1 << TWINT) | (1 << TWEA) | (1 << TWEN) ;
		
		// Wait for TWINT flag
		while (!(TWCR & (1<<TWINT)));
	}
}

/*
Description : function to send byte data by slave (Slave - Sender)
inputs		: none
outputs		: none
*/
void I2C_Slave_write_data (unsigned char data) {
	TWDR = data ;
	
	// Clear TWI interrupt flag,Enable TWI
	TWCR |= (1 << TWINT) | (1 << TWEN) ;
	
	// Wait till complete TWDR byte transmitted
	while (!(TWCR & (1 << TWINT))) ;
	
	// Check for the acknowledgment
	while ((TWSR & 0xF8) != S_DATA_TRANSMIT_ACK) ;	
}

/*
Description : function to receive byte data by slave (Slave - Receiver)
inputs		: none
outputs		: none
*/
unsigned char I2C_Slave_read_data (void) {
	// Clear TWI interrupt flag,Enable TWI
	TWCR |= (1 << TWINT) | (1 << TWEA) | (1 << TWEN) ;
	
	// Wait till complete TWDR byte transmitted
	while (!(TWCR & (1 << TWINT))) ;
	
	// Check for the acknowledgment
	while ((TWSR & 0xF8) != S_DATA_RECEIVE_ACK) ;
	
	return TWDR ;	
}
