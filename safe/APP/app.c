/*
 * app.c
 *
 * Created: 9/5/2023 6:17:59 AM
 *  Author: himah
 */ 
#include "app.h"
#include "../MCAL/EEPROM/EEPROM.h"
#include "../HAL/KEYPAD/keypad.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Buzzer/BUZZER.h"
#include "../HAL/LED/LED.h"
#define  F_CPU 8000000UL
#include <util/delay.h>


/*check if the safe is being used for the fist time or resetted*/
safe_status check_status(){
	uint8 check = EEPROM_read(EEPROM_STATUS_ADRESS);
	safe_status status = FIRST_SETUP;
	if (check != 0xff){
		status = NOT_FIRST_SETUP;
	}
	return status;
}

/*check a given password is the same stored as the safe`s password or not*/
password_status check_password(uint8 * password){
	password_status status = CORRECT;
	for (int i=0;i<4;i++){
		if (password[i] != EEPROM_read(EEPROM_PASSWORD1_ADRESS+i)){
			status = NOT_CORRECT;
			break;
			}
	}
	return status;
}

/*get password and assign it as new password for the safe*/
void set_new_password(uint8 * password){
		for (int i=0;i<4;i++){
				EEPROM_write(EEPROM_PASSWORD1_ADRESS+i,password[i]);
		}
		EEPROM_write(EEPROM_STATUS_ADRESS,'h');
}

/*read the password from the user (setting a new pass or entering the pass to open the safe or resetting*/
uint8* read_password(safe_status *status){

	uint8 num;
	uint8 password[4]={0};
	uint8 reset_flag=0;
	switch (*status){
		/*entering the password to open the safe */
		case NOT_FIRST_SETUP:
			lcd_clear_screen();
			lcd_move_cursor(1,1);
			lcd_send_string("check Password:");
			/*reading each number*/
			for (int i=0;i<4;i++){
					num = keypad_read();
					_delay_ms(200);
					while(num == 0xff){
						num = keypad_read();
						_delay_ms(200);
					}
					/*check if it is not the reset char "A" */
					if (num != RESET_CHAR){
						*(password+i) = num;
						lcd_move_cursor(2,i+1);
						lcd_send_char(num);
						_delay_ms(1000);
						lcd_move_cursor(2,i+1);
						lcd_send_char('*');
						}
					else{
						/*reset routine*/
						EEPROM_write(EEPROM_STATUS_ADRESS,0xff);
						*status = FIRST_SETUP;
						break;
					}

			}
			break;
		/*setting a new pass*/
		case FIRST_SETUP:
			*status = PASSWORD_SET;
			lcd_clear_screen();
			lcd_move_cursor(1,1);
			lcd_send_string("Set Password:");
			/*reading each number*/
			for (int i=0;i<4;i++){
					num = keypad_read();
					_delay_ms(200);
					while(num == 0xff){
						num = keypad_read();
						_delay_ms(200);
					}
					/*check if it is not the reset char "A" and applying reset routine */
					if (num == RESET_CHAR){
						EEPROM_write(EEPROM_STATUS_ADRESS,0xff);
						reset_flag=1;   //flag to indicate the reset happens
						*status = FIRST_SETUP;
					}
					else{
					password[i] = num;
					lcd_move_cursor(2,1+i);
					lcd_send_char(num);
					_delay_ms(1000);
					lcd_move_cursor(2,i+1);
					lcd_send_char('*');
					}
				}
			/*if reset does not happened*/
			if (reset_flag == 0){
				lcd_clear_screen();
				lcd_move_cursor(1,1);
				lcd_send_string("Password is set");
				_delay_ms(3000);
			}
			break;
				
			
	}
	return password;
}
	
/*the routine for indicating to the user the state after entering password */
void check_password_message(password_status status, uint8 trials){
	switch(status){
		/*routine of correct password*/
		case CORRECT:
			lcd_clear_screen();
			lcd_move_cursor(1,1);
			lcd_send_string("Correct Password");
			led_on(PORT_C,GREEN_LED_PIN);  //green led is on indicating correct pass
			_delay_ms(3000);
			led_off(PORT_C,GREEN_LED_PIN);
			break;
		
		/*routine of incorrect password*/	
		case NOT_CORRECT:
			lcd_clear_screen();
			lcd_move_cursor(1,1);
			lcd_send_string("Not Correct");
			lcd_move_cursor(2,1);
			lcd_send_string("Trials Left:"); //printing how many trials left before alarming
			lcd_move_cursor(2,14);
			lcd_send_char(trials+48);
			led_on(PORT_C,RED_LED_PIN);  //red led is on indicating incorrect pass
			_delay_ms(3000);
			led_off(PORT_C,RED_LED_PIN);
			break;
	}
}

/*the routine for indicating to the user that he is blocked for 30 seconds */
void blocked_message(){
		lcd_clear_screen();
		lcd_move_cursor(1,1);
		lcd_send_string("You Are Blocked");
		lcd_move_cursor(2,1);
		lcd_send_string("Time Left(s):");
		led_on(PORT_C,RED_LED_PIN);			 //red led is on indicating blocking state
		buzzer_on(PORT_C,BUZZER_PIN);		 //buzzer is on indicating blocking state
		for(int i=30;i>0;i--){
			lcd_move_cursor(2,14);
			lcd_send_char((i/10)+48);
			lcd_send_char((i%10)+48);
			_delay_ms(1000);
		}
		led_off(PORT_C,RED_LED_PIN);  
		buzzer_off(PORT_C,BUZZER_PIN);
}

/*the application function*/
void app(){
		/*initializations*/
		lcd_init();
		keypad_init();
		buzzer_init(PORT_C,BUZZER_PIN);
		led_init(PORT_C,GREEN_LED_PIN);
		led_init(PORT_C,RED_LED_PIN);
		led_off(PORT_C,GREEN_LED_PIN);
		led_off(PORT_C,RED_LED_PIN);
		safe_status check_safe_status ;
		uint8 * password;
		password_status check_password_status;
		uint8 trials=MAX_TRIALS;
		
		
		while(1){
			
			check_safe_status =  check_status(); 
			password = read_password(&check_safe_status); 
			while(check_safe_status == FIRST_SETUP){
				password= read_password(&check_safe_status);
			}
			
			
			if (check_safe_status == PASSWORD_SET){
				set_new_password(password);
			}
			else{
				check_password_status = check_password(password);
				if (check_password_status == CORRECT){
					check_password_message(check_password_status,trials);
					trials=MAX_TRIALS;
				}
				else{
					trials--;
					if (trials==0){
						blocked_message();
						trials=MAX_TRIALS;
					}
					else{
					check_password_message(check_password_status,trials);
					}
				}
			}
		}
}