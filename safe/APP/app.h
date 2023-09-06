/*
 * app.h
 *
 * Created: 9/5/2023 6:17:49 AM
 *  Author: himah
 */ 


#ifndef APP_H_
#define APP_H_
#include "../Std_Macros.h"
#define BUZZER_PIN     PIN1
#define GREEN_LED_PIN  PIN2
#define RED_LED_PIN    PIN3
#define RESET_CHAR     'A'

#define MAX_TRIALS      2

#define EEPROM_STATUS_ADRESS 0x20
#define EEPROM_PASSWORD1_ADRESS 0x21
#define EEPROM_PASSWORD2_ADRESS 0x22
#define EEPROM_PASSWORD3_ADRESS 0x23
#define EEPROM_PASSWORD4_ADRESS 0x24

typedef enum{
	FIRST_SETUP,
	NOT_FIRST_SETUP,
	PASSWORD_SET
	}safe_status;

typedef enum{
	CORRECT,
	NOT_CORRECT
}password_status;

typedef enum{
	PASSWORD_CORRECT,
	PASSWORD_NOT_CORRECT,
	LOCKED
	}safe_case;
safe_status check_status();
password_status check_password(uint8 * password);
void set_new_password(uint8 * password);
uint8* read_password(safe_status *status);
void check_password_message(password_status status, uint8 trials);
void blocked_message();
void app();

#endif /* APP_H_ */