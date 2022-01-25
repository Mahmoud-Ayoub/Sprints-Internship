/*
 * I2C.h
 *
 *  Author: Mahmoud Ayoub
 */ 

#ifndef I2C_H_
#define I2C_H_

#define TWBR (*((volatile unsigned char*)0x20))
#define TWSR (*((volatile unsigned char*)0x21))
#define TWAR (*((volatile unsigned char*)0x22))
#define TWDR (*((volatile unsigned char*)0x23))
#define TWCR (*((volatile unsigned char*)0x56))

// TWCR bits
#define TWINT	7
#define TWEA	6
#define TWSTA	5
#define TWSTO	4
#define TWWC	3
#define TWEN	2
#define TWIE	0

typedef enum {
	_1_div  , 
	_4_div  , 
	_16_div , 
	_64_div
}EN_PRESCALER;

#define F_CPU 8000000UL
#define WRITE	0
#define READ	1

// Acknowledge status MACROS
#define START_TRANSMIT_ACK				0x08
#define REPEATED_START_TRANSMIT_ACK		0x10
#define ADDR_OP_ACK						0x18
#define M_DATA_TRANSMIT_ACK				0x28
#define M_DATA_RECEIVE_ACK				0x58
#define S_ADDR_RECEIVE_ACK				0x60
#define S_DATA_RECEIVE_ACK				0x80
#define S_DATA_TRANSMIT_ACK				0xC0

// APIs
void I2C_Master_init (unsigned char bit_rate_value , EN_PRESCALER prescaler) ;
void I2C_Slave_init (unsigned char slave_address) ;  
void I2C_start (void) ;
void I2C_repeated_start (void) ; 
void I2C_stop (void) ;
void I2C_write_address (unsigned char slave_address) ;
void I2C_Master_write_data (unsigned char data) ; 
unsigned char I2C_Master_read_data (void) ; 
void I2C_Slave_match_read (void) ; 
void I2C_Slave_write_data (unsigned char data) ;
unsigned char I2C_Slave_read_data (void) ;


#endif /* I2C_H_ */