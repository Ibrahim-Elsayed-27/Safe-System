/*
 * LCD.h
 *
 * Created: 8/17/2023 4:27:59 PM
 *  Author: himah
 */ 


#ifndef LCD_H_
#define LCD_H_


#include "../../MCAL/DIO/DIO.h"
#include "LCD_Config.h"

#if defined EIGHT_BIT_MODE
#define EIGHT_BIT_CMD        0x38
#define DATA_PORT            PORT_A
#define CONTROL_PORT         PORT_B
#define ENABLE_PIN           PIN0
#define READ_WRITE_PIN       PIN1
#define REGISTER_SELECT_PIN  PIN2

#elif defined FOUR_BIT_MODE
#define FOUR_BIT_CMD         0x28
#define DATA_PORT            PORT_A
#define DATA_NIBBLE          LOW_NIBBLE
#define CONTROL_PORT         PORT_B
#define ENABLE_PIN           PIN0
#define READ_WRITE_PIN       PIN1
#define REGISTER_SELECT_PIN  PIN2
#endif

#define CURSOR_ON_DISPLAY_ON_CMD     0x0e
#define CLEAR_SCREEN_CMD             0x01
#define ENTRY_MODE_CMD               0x06
#define RETURN_HOME_CMD              0x02





void lcd_init();
static void send_falling_edge();
void lcd_send_cmd(char cmd);
void lcd_send_char(char data);
void lcd_send_string(char* data);
void lcd_clear_screen();
void lcd_move_cursor(char row, char column);

#endif /* LCD_H_ */