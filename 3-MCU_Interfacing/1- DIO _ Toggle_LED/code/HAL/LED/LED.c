/*
 * LED.c
 *
 *  Author: Mahmoud Ayoub
 */ 
#include "LED.h"

void LED_init (uint8 PortNumber , uint8 PinNumber) {
	DIO_SetPinDirection (PortNumber , PinNumber , OUTPUT) ; 
}
void LED_TOGGLE (uint8 PortNumber , uint8 PinNumber) {
	DIO_TogglePinValue (PortNumber , PinNumber) ; 
}