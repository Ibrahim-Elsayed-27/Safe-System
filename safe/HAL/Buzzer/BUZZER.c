/*
 * BUZZER.c
 *
 * Created: 8/2/2023 2:22:36 PM
 *  Author: himah
 */ 

#include "BUZZER.h"

void buzzer_init(uint8 port, uint8 pin){
	pin_init(port, pin, OUTPUT);
}

void buzzer_on(uint8 port, uint8 pin){
	pin_write(port, pin, HIGH);
}

void buzzer_off(uint8 port, uint8 pin){
	pin_write(port, pin, LOW);
}