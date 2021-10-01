/*
 * SPI_sender.h
 *
 *  Author: Mahmoud Ayoub
 */ 


#ifndef SPI_SENDER_H_
#define SPI_SENDER_H_
#include "../../MCAL/SPI/SPI.h"

void SPI_Sender_init (EN_SCK clock) ;
void SPI_Sender_Send_Char (unsigned char data) ;
void SPI_Sender_Send_String (unsigned char* str) ;




#endif /* SPI_SENDER_H_ */