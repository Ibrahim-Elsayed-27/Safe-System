/*
 * LED.c
 *
 * Created: 8/1/2023 11:20:40 AM
 *  Author: himah
 */ 

#include "LED.h"
void led_init(uint8 port, uint8 pin){
	pin_init(port,pin,OUTPUT);
}

void led_on(uint8 port, uint8 pin){
	pin_write(port,pin,HIGH);
}

void led_off(uint8 port, uint8 pin){
	pin_write(port,pin,LOW);
}

void led_toggle(uint8 port, uint8 pin){
	pin_toggle(port,pin);
}

char led_status(uint8 port, uint8 pin){
	return pin_read(port,pin);
}
