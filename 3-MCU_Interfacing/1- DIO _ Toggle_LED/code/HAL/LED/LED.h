﻿/*
 * LED.h
 *
 *  Author: Mahmoud Ayoub
 */ 


#ifndef LED_H_
#define LED_H_

#include "D:\Sprints iCamp\5- MCU interfacing\Toggle_LED\Toggle_LED\MCAL\DIO\DIO_Config.h"

#define HIGH 1
#define LOW 0

void LED_init (uint8 PortNumber , uint8 PinNumber) ; 
void LED_TOGGLE (uint8 PortNumber , uint8 PinNumber) ; 




#endif /* LED_H_ */