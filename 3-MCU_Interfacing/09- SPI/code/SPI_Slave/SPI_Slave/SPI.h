/*
 * SPI.h
 *
 *  Author: Mahmoud Ayoub
 */ 

#ifndef SPI_H_
#define SPI_H_

#define DDRB_REG			(*((volatile unsigned char*)0x37))
#define PORTB_REG			(*((volatile unsigned char*)0x38))
#define PINB_REG			(*((volatile unsigned char*)0x36))

#define SPCR				(*((volatile unsigned char*)0x2D))
#define SPSR				(*((volatile unsigned char*)0x2E))
#define SPDR				(*((volatile unsigned char*)0x2F))

#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7

#define SPIF	7
#define SPE		6
#define MSTR	4
#define SPR1	1
#define SPR0	0
#define SPI2X	0

typedef enum {
	Fosc_4 , 
	Fosc_16 , 
	Fosc_64 , 
	Fosc_128 , 
	Fosc_2 ,
	Fosc_8 , 
	Fosc_32   
}EN_SCK;

void SPI_Master_init (EN_SCK clock) ; 
void SPI_Slave_init (void) ;
void SPI_Transmit_Char (unsigned char data) ; 
void SPI_Transmit_String (unsigned char* str) ; 
unsigned char SPI_Receive_Char (void) ;


#endif /* SPI_H_ */