/*
 * LED.h
 *
 * Created: 8/1/2023 11:20:53 AM
 *  Author: himah
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../Std_Macros.h"


void led_init(uint8 port, uint8 pin);
void led_on(uint8 port, uint8 pin);
void led_off(uint8 port, uint8 pin);
void led_toggle(uint8 port, uint8 pin);
char led_status(uint8 port, uint8 pin);

#endif /* LED_H_ */