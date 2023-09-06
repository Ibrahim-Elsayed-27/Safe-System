/*
 * EEPROM.c
 *
 * Created: 8/7/2023 1:32:34 PM
 *  Author: himah
 */ 
#include "EEPROM.h"


void EEPROM_write(uint16 adress, uint8 data){
		EEAR_REG = adress;
		EEDR_REG = data;
		
		SET_BIT(EECR_REG,EEMWE_BIT);
		SET_BIT(EECR_REG,EEWE_BIT);
		
		while(GET_BIT(EECR_REG,EEWE_BIT) == 1); 
}

uint8 EEPROM_read(uint16 adress){
		EEAR_REG = adress;
		SET_BIT(EECR_REG,EERE_BIT);
		
		return EEDR_REG;
}