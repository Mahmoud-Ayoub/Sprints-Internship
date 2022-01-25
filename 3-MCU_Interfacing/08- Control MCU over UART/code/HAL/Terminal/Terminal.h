/*
 * Terminal.h
 *
 *  Author: Mahmoud Ayoub
 */ 


#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "../../MCAL/UART/UART.h"

void Terminal_init (unsigned int baud_rate , EN_STOP_BITS stop_bits , EN_DATA_SIZE data_size) ; 
void Terminal_Send_Char (unsigned char data) ; 
void Terminal_Send_String (unsigned char* str) ; 
unsigned char Terminal_Receive_Char (void) ; 




#endif /* TERMINAL_H_ */