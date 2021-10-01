/*
 * SPI.c
 *
 * Author : Mahmoud Ayoub
 */ 

#include "SPI.h"

int main(void)
{
	SPI_Master_init(Fosc_16) ;
	SPI_Transmit_Char(3) ;  
}

