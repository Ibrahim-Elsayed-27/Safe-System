/*
 * LCD.c
 *
 * Created: 8/17/2023 4:28:23 PM
 *  Author: Ibrahim Elsayed 
 */ 

#include "LCD.h"
#include <util/delay.h>
#define   F_CPU 8000000UL


void lcd_init(){
	_delay_ms(200);
	#if defined EIGHT_BIT_MODE
	port_init(DATA_PORT,OUTPUT);
	pin_init(CONTROL_PORT,ENABLE_PIN,OUTPUT);
	pin_init(CONTROL_PORT,READ_WRITE_PIN,OUTPUT);
	pin_init(CONTROL_PORT,REGISTER_SELECT_PIN,OUTPUT);
	
	pin_write(CONTROL_PORT,READ_WRITE_PIN,LOW);
	lcd_send_cmd(RETURN_HOME_CMD);
	_delay_ms(10);
	lcd_send_cmd(EIGHT_BIT_CMD);
	_delay_ms(1);
	lcd_send_cmd(CURSOR_ON_DISPLAY_ON_CMD);
	_delay_ms(1);
	lcd_send_cmd(CLEAR_SCREEN_CMD);
	_delay_ms(10);
	lcd_send_cmd(ENTRY_MODE_CMD);
	_delay_ms(1);
	
	#elif defined FOUR_BIT_MODE
	port_nibble_init(DATA_PORT,DATA_NIBBLE,OUTPUT);
	pin_init(CONTROL_PORT,ENABLE_PIN,OUTPUT);
	pin_init(CONTROL_PORT,READ_WRITE_PIN,OUTPUT);
	pin_init(CONTROL_PORT,REGISTER_SELECT_PIN,OUTPUT);
	
	pin_write(CONTROL_PORT,READ_WRITE_PIN,LOW);
	
	lcd_send_cmd(RETURN_HOME_CMD);
	_delay_ms(10);
	lcd_send_cmd(FOUR_BIT_CMD);
	_delay_ms(1);
	lcd_send_cmd(CURSOR_ON_DISPLAY_ON_CMD);
	_delay_ms(1);
	lcd_send_cmd(CLEAR_SCREEN_CMD);
	_delay_ms(10);
	lcd_send_cmd(ENTRY_MODE_CMD);
	_delay_ms(1);
	#endif

}


static void send_falling_edge(){
	pin_write(CONTROL_PORT,ENABLE_PIN,HIGH);
	_delay_ms(2);
	pin_write(CONTROL_PORT,ENABLE_PIN,LOW);
	_delay_ms(2);
}

void lcd_send_cmd(char cmd){
	
	#if defined EIGHT_BIT_MODE
	port_write(DATA_PORT,cmd);
	pin_write(CONTROL_PORT,REGISTER_SELECT_PIN,LOW);
	send_falling_edge();
	
	#elif defined FOUR_BIT_MODE
	port_nibble_write(DATA_PORT,DATA_NIBBLE,cmd>>4);
	pin_write(CONTROL_PORT,REGISTER_SELECT_PIN,LOW);
	send_falling_edge();
	port_nibble_write(DATA_PORT,DATA_NIBBLE,cmd);
	pin_write(CONTROL_PORT,REGISTER_SELECT_PIN,LOW);
	send_falling_edge();
	_delay_ms(1);
	#endif
}


void lcd_send_char(char data){
	
	#if defined EIGHT_BIT_MODE
	port_write(DATA_PORT,data);
	pin_write(CONTROL_PORT,REGISTER_SELECT_PIN,HIGH);
	send_falling_edge();
	
	#elif defined FOUR_BIT_MODE
	port_nibble_write(DATA_PORT,DATA_NIBBLE,data>>4);
	pin_write(CONTROL_PORT,REGISTER_SELECT_PIN,HIGH);
	send_falling_edge();
	port_nibble_write(DATA_PORT,DATA_NIBBLE,data);
	pin_write(CONTROL_PORT,REGISTER_SELECT_PIN,HIGH);
	send_falling_edge();
	_delay_ms(1);
	#endif
	
	
}

void lcd_send_string(char* data){
	while(*data != '\0'){
		lcd_send_char(*data);
		data++;
	}
}

void lcd_clear_screen(){
	lcd_send_cmd(CLEAR_SCREEN_CMD);
	_delay_ms(10);
}

void lcd_move_cursor(char row, char column){
	char data;
	if(row<1 || row>2 || column<1 || column>16){
		;
	}else if(row == 1){
		data = 0x80 + column - 1;
		lcd_send_cmd(data);
	}else{
		data = 0xc0 + column - 1;
		lcd_send_cmd(data);
	}
	
	_delay_ms(1);
}