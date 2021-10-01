/*
 * SPI.c
 *
 * Author : Mahmoud Ayoub
 */ 
#define DDRA_REG			(*((volatile unsigned char*)0x3A))
#define PORTA_REG			(*((volatile unsigned char*)0x3B))
#define PINA_REG			(*((volatile unsigned char*)0x39))

#include "SPI.h"

int main(void)
{
	DDRA_REG = 0xFF ; 
    SPI_Slave_init() ;  
	while (1) {
	   PORTA_REG = SPI_Receive_Char() ;
	} 
}

