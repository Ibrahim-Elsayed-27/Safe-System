/*
 * EEPROM.h
 *
 * Created: 8/7/2023 1:32:22 PM
 *  Author: himah
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "../../Std_Macros.h"


#define EEARH_REG    *((volatile uint8*) 0x3F)
#define EEARL_REG    *((volatile uint8*) 0x3E)
#define EEAR_REG    *((volatile uint16*) 0x3E)
#define EEDR_REG    *((volatile uint8*) 0x3D)
#define EECR_REG    *((volatile uint8*) 0x3C)

#define EERE_BIT     0
#define EEWE_BIT     1
#define EEMWE_BIT    2
#define EERIE_BIT    3



void EEPROM_write(uint16 adress, uint8 data);
uint8 EEPROM_read(uint16 adress);


#endif /* EEPROM_H_ */