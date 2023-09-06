/*
 * SWITCH.c
 *
 * Created: 8/2/2023 2:01:15 PM
 *  Author: himah
 */ 

#include "SWITCH.h"

void switch_init(uint8 port, uint8 pin){
	pin_init(port, pin , INPUT);
}

uint8 switch_status(uint8 port, uint8 pin){
	uint8 status;
	status=pin_read(port, pin);
	return status;
}