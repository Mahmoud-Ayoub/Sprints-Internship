/*
 * Terminal.c
 *
 *  Author: Mahmoud Ayoub
 */ 
#include "Terminal.h"

/*
Description : function to initialize terminal
inputs		: baud rate , no of stop bits required (_1_BIT , _2_BITS) , data size required (_5_BITS , _6_BITS , _7_BITS , _8_BITS)
outputs		: none
*/
void Terminal_init (unsigned int baud_rate , EN_STOP_BITS stop_bits , EN_DATA_SIZE data_size) {
	UART_init(baud_rate , stop_bits , data_size) ; 
}

/*
Description : function to send data to terminal
inputs		: data to be sent using UART
outputs		: none
*/
void Terminal_Send_Char (unsigned char data) {
	UART_Transmit_Char(data) ; 
}

/*
Description : function to send string to terminal
inputs		: string to be sent using UART
outputs		: none
*/
void Terminal_Send_String (unsigned char* str) {
	UART_Transmit_String(str) ; 
}

/*
Description : function to receive data to terminal
inputs		: none
outputs		: data received on UART
*/
unsigned char Terminal_Receive_Char (void) {
	return UART_Receive_Char() ; 
}