/*
 * SWITCH.h
 *
 * Created: 8/2/2023 2:01:49 PM
 *  Author: himah
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../Std_Macros.h"

void switch_init(uint8 port, uint8 pin);
uint8 switch_status(uint8 port, uint8 pin);

#endif /* SWITCH_H_ */