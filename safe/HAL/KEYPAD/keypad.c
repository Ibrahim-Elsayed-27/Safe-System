/*
 * keypad.c
 *
 * Created: 9/2/2023 11:47:31 PM
 *  Author: himah
 */ 

#include "keypad.h"

void keypad_init(){
		pin_init(keypad_port,0,OUTPUT);
		pin_init(keypad_port,1,OUTPUT);
		pin_init(keypad_port,2,OUTPUT);
		pin_init(keypad_port,3,OUTPUT);
		
		pin_init(keypad_port,4,INPUT);
		pin_init(keypad_port,5,INPUT);
		pin_init(keypad_port,6,INPUT);
		pin_init(keypad_port,7,INPUT);
		
		
		internal_pullup_enable(keypad_port,4);
		internal_pullup_enable(keypad_port,5);
		internal_pullup_enable(keypad_port,6);
		internal_pullup_enable(keypad_port,7);
}

uint8 keypad_read(){
	uint8 characters[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	uint8 return_value=0xff;
	uint8 check=1;
	for (int i=0;i<4;i++){
		pin_write(keypad_port,0,HIGH);
		pin_write(keypad_port,1,HIGH);
		pin_write(keypad_port,2,HIGH);
		pin_write(keypad_port,3,HIGH);
		pin_write(keypad_port,i,LOW);
		for (int j=0;j<4;j++){
			check = pin_read(keypad_port,j+4);
			if (check == 0){
				return_value = characters[i][j];
				break;
			}

			}
			if (check ==0){
				break;
			}
		}
		
		
		return return_value;
			
}