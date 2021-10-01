/*
 * SPI_receiver.h
 *
 *  Author: Mahmoud Ayoub
 */ 

#ifndef SPI_RECEIVER_H_
#define SPI_RECEIVER_H_

#include "../../MCAL/SPI/SPI.h"

void SPI_Receiver_init (void) ;
unsigned char SPI_Receiver_Receive_Char (void) ;



#endif /* SPI_RECEIVER_H_ */