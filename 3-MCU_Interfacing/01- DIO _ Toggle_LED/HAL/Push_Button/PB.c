/*
 * PB.c
 *
 *  Author: Mahmoud Ayoub
 */ 
#include "PB.h"

void PB_init (uint8 PortNumber , uint8 PinNumber) {
	DIO_SetPinDirection (PortNumber , PinNumber , INPUT) ; 
}
uint8 PB_read (uint8 PortNumber , uint8 PinNumber) {
	uint8 value ;
	value = DIO_GetPinValue (PortNumber , PinNumber) ;
	return value ; 
}