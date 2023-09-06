/*
 * keypad.h
 *
 * Created: 9/2/2023 11:47:19 PM
 *  Author: himah
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "../../MCAL/DIO/DIO.h"
#include "../../Std_Macros.h"

#define keypad_port PORT_D

void keypad_init();
uint8 keypad_read();


#endif /* KEYPAD_H_ */