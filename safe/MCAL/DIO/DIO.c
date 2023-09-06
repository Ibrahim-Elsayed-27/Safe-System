
#include "DIO.h"
void pin_init(uint8 port,uint8 pin,uint8 direction){
	switch (port){
		case PORT_A:
		if (direction==OUTPUT){
			SET_BIT(DDRA_REG,pin);
		}
		else{
			CLR_BIT(DDRA_REG,pin);
			}
		break;

		case PORT_B:
		if (direction==OUTPUT){
			SET_BIT(DDRB_REG,pin);
			}	
		else{
			CLR_BIT(DDRB_REG,pin);
			}
		break;

		case PORT_C:
		if (direction==OUTPUT){
			SET_BIT(DDRC_REG,pin);
			}
			else{
				CLR_BIT(DDRC_REG,pin);
			}
		
		break;

		case PORT_D:
		if (direction==OUTPUT){
			SET_BIT(DDRD_REG,pin);
			}
			else{
				CLR_BIT(DDRD_REG,pin);
			}
		
		break;

		default:
		;

	}

}



void pin_write(uint8 port,uint8 pin,uint8 direction){
	switch (port){
		case PORT_A:
		if (direction==HIGH){
			SET_BIT(PORTA_REG,pin);
		}
			else{
			CLR_BIT(PORTA_REG,pin);
			}

		break;

		case PORT_B:
		if (direction==HIGH){
			SET_BIT(PORTB_REG,pin);
			}
			else{
			CLR_BIT(PORTB_REG,pin);
			}

		break;

		case PORT_C:
		if (direction==HIGH){
			SET_BIT(PORTC_REG,pin);
		}
			else{
			CLR_BIT(PORTC_REG,pin);
			}
		
		break;

		case PORT_D:
		if (direction==HIGH){
			SET_BIT(PORTD_REG,pin);
		}
			else{
				CLR_BIT(PORTD_REG,pin);
			}
		
		break;

		default:
		;

	}

}

void pin_toggle(uint8 port,uint8 pin){
	switch (port){
		case PORT_A:
		TOG_BIT(PORTA_REG,pin);
		break;
		case PORT_B:
		TOG_BIT(PORTB_REG,pin);
		break;

		case PORT_C:
		TOG_BIT(PORTC_REG,pin);
		break;

		case PORT_D:
		TOG_BIT(PORTD_REG,pin);
		break;

		default:
		;

	}

}


uint8 pin_read(uint8 port,uint8 pin){
	uint8 status;

	switch (port){
		case PORT_A:
		status=GET_BIT(PINA_REG,pin);
		break;

		case PORT_B:
		status=GET_BIT(PINB_REG,pin);
		break;

		case PORT_C:
		status=GET_BIT(PINC_REG,pin);
		break;

		case PORT_D:
		status=GET_BIT(PIND_REG,pin);
		break;

		default:
		status=0;
	}

	return status;

}


void port_init(uint8 port,uint8 direction){

	switch (port){
		case PORT_A:
		if (direction==OUTPUT){
			DDRA_REG=0xff;
		}
		else{
			DDRA_REG=0x00;
		}
		break;

		case PORT_B:
		if (direction==OUTPUT){
			DDRB_REG=0xff;
		}
		else{
			DDRB_REG=0x00;
		}
		break;

		case PORT_C:
		if (direction==OUTPUT){
			DDRC_REG=0xff;
		}
		else{
			DDRC_REG=0x00;
		}
		
		break;

		case PORT_D:
		if (direction==OUTPUT){
			DDRD_REG=0xff;
		}
		else{
			DDRD_REG=0x00;
		}
		
		break;

		default:
		;

	}
}

void port_write(uint8 port,uint8 output){

	switch (port){
		case PORT_A:
			PORTA_REG=output;
			break;

		case PORT_B:
			PORTB_REG=output;
			break;

		case PORT_C:
			PORTC_REG=output;
			break;

		case PORT_D:
			PORTD_REG=output;
			break;

		default:
		;

	}
}

void port_toggle(uint8 port){
	switch (port){
		case PORT_A:
		PORTA_REG ^= 0xff;
		break;
		case PORT_B:
		PORTB_REG ^= 0xff;
		break;

		case PORT_C:
		PORTC_REG ^= 0xff;
		break;

		case PORT_D:
		PORTD_REG ^= 0xff;
		break;

		default:
		;

	}

}


uint8 port_read(uint8 port){
	uint8 status;

	switch (port){
		case PORT_A:
		status=PINA_REG;
		break;

		case PORT_B:
		status=PINB_REG;
		break;

		case PORT_C:
		status=PINC_REG;
		break;

		case PORT_D:
		status=PIND_REG;
		break;

		default:
		status=0;
	}

	return status;

}

void port_nibble_init(uint8 port, uint8 nibble, uint8 direction){
	switch(port){
		case PORT_A:
			if (nibble==LOW_NIBBLE){
				if (direction==OUTPUT){
					pin_init(PORT_A,PIN0,OUTPUT);
					pin_init(PORT_A,PIN1,OUTPUT);
					pin_init(PORT_A,PIN2,OUTPUT);
					pin_init(PORT_A,PIN3,OUTPUT);
				}
				else{
					pin_init(PORT_A,PIN0,INPUT);
					pin_init(PORT_A,PIN1,INPUT);
					pin_init(PORT_A,PIN2,INPUT);
					pin_init(PORT_A,PIN3,INPUT);
				}
			}
			else{
				if (direction==OUTPUT){
					pin_init(PORT_A,PIN4,OUTPUT);
					pin_init(PORT_A,PIN5,OUTPUT);
					pin_init(PORT_A,PIN6,OUTPUT);
					pin_init(PORT_A,PIN7,OUTPUT);
				}
				else{
					pin_init(PORT_A,PIN4,INPUT);
					pin_init(PORT_A,PIN5,INPUT);
					pin_init(PORT_A,PIN6,INPUT);
					pin_init(PORT_A,PIN7,INPUT);
				}
			}
			break;
			
			
		case PORT_B:
			if (nibble==LOW_NIBBLE){
				if (direction==OUTPUT){
					pin_init(PORT_B,PIN0,OUTPUT);
					pin_init(PORT_B,PIN1,OUTPUT);
					pin_init(PORT_B,PIN2,OUTPUT);
					pin_init(PORT_B,PIN3,OUTPUT);
				}
				else{
					pin_init(PORT_B,PIN0,INPUT);
					pin_init(PORT_B,PIN1,INPUT);
					pin_init(PORT_B,PIN2,INPUT);
					pin_init(PORT_B,PIN3,INPUT);
				}
			}
			else{
				if (direction==OUTPUT){
					pin_init(PORT_B,PIN4,OUTPUT);
					pin_init(PORT_B,PIN5,OUTPUT);
					pin_init(PORT_B,PIN6,OUTPUT);
					pin_init(PORT_B,PIN7,OUTPUT);
				}
				else{
					pin_init(PORT_B,PIN4,INPUT);
					pin_init(PORT_B,PIN5,INPUT);
					pin_init(PORT_B,PIN6,INPUT);
					pin_init(PORT_B,PIN7,INPUT);
				}
			}
			break;

		case PORT_C:
			if (nibble==LOW_NIBBLE){
				if (direction==OUTPUT){
					pin_init(PORT_C,PIN0,OUTPUT);
					pin_init(PORT_C,PIN1,OUTPUT);
					pin_init(PORT_C,PIN2,OUTPUT);
					pin_init(PORT_C,PIN3,OUTPUT);
				}
				else{
					pin_init(PORT_C,PIN0,INPUT);
					pin_init(PORT_C,PIN1,INPUT);
					pin_init(PORT_C,PIN2,INPUT);
					pin_init(PORT_C,PIN3,INPUT);
				}
			}
			else{
				if (direction==OUTPUT){
					pin_init(PORT_C,PIN4,OUTPUT);
					pin_init(PORT_C,PIN5,OUTPUT);
					pin_init(PORT_C,PIN6,OUTPUT);
					pin_init(PORT_C,PIN7,OUTPUT);
				}
				else{
					pin_init(PORT_C,PIN4,INPUT);
					pin_init(PORT_C,PIN5,INPUT);
					pin_init(PORT_C,PIN6,INPUT);
					pin_init(PORT_C,PIN7,INPUT);
				}
			}
			break;
			
			
		case PORT_D:
			if (nibble==LOW_NIBBLE){
				if (direction==OUTPUT){
					pin_init(PORT_D,PIN0,OUTPUT);
					pin_init(PORT_D,PIN1,OUTPUT);
					pin_init(PORT_D,PIN2,OUTPUT);
					pin_init(PORT_D,PIN3,OUTPUT);
				}
				else{
					pin_init(PORT_D,PIN0,INPUT);
					pin_init(PORT_D,PIN1,INPUT);
					pin_init(PORT_D,PIN2,INPUT);
					pin_init(PORT_D,PIN3,INPUT);
				}
			}
			else{
				if (direction==OUTPUT){
					pin_init(PORT_D,PIN4,OUTPUT);
					pin_init(PORT_D,PIN5,OUTPUT);
					pin_init(PORT_D,PIN6,OUTPUT);
					pin_init(PORT_D,PIN7,OUTPUT);
				}
				else{
					pin_init(PORT_D,PIN4,INPUT);
					pin_init(PORT_D,PIN5,INPUT);
					pin_init(PORT_D,PIN6,INPUT);
					pin_init(PORT_D,PIN7,INPUT);
				}
			}
			break;
		}
}
			

void port_nibble_write(uint8 port, uint8 nibble, uint8 output){
		switch(port){
			case PORT_A:
			if (nibble==LOW_NIBBLE){
				PORTA_REG &= 0xf0;
				PORTA_REG |= output;
			}
			else{
				output<<=4;
				PORTA_REG &= 0x0f;
				PORTA_REG |= output;

			}
			break;
			
			
			case PORT_B:
			if (nibble==LOW_NIBBLE){
				PORTB_REG &= 0xf0;
				PORTB_REG |= output;
			}
			else{
				output<<=4;
				PORTB_REG &= 0x0f;
				PORTB_REG |= output;

			}
			break;


			case PORT_C:
			if (nibble==LOW_NIBBLE){
				PORTC_REG &= 0xf0;
				PORTC_REG |= output;
			}
			else{
				output<<=4;
				PORTC_REG &= 0x0f;
				PORTC_REG |= output;

			}
			break;
			
			
			case PORT_D:
			if (nibble==LOW_NIBBLE){
				PORTD_REG &= 0xf0;
				PORTD_REG |= output;
			}
			else{
				output<<=4;
				PORTD_REG &= 0x0f;
				PORTD_REG |= output;

			}
			break;
		}
	}


void port_nibble_internal_pullup_enable(uint8 port, uint8 nibble){
	switch(port){
		case PORT_A:
		if (nibble==LOW_NIBBLE){
			PORTA_REG |= 0x0f;
		}
		else{
			PORTA_REG |= 0xf0;

		}
		break;
		
		case PORT_B:
		if (nibble==LOW_NIBBLE){
			PORTB_REG |= 0x0f;
		}
		else{
			PORTB_REG |= 0xf0;

		}
		break;


		case PORT_C:
		if (nibble==LOW_NIBBLE){
			PORTC_REG |= 0x0f;
		}
		else{
			PORTC_REG |= 0xf0;

		}
		break;
		
		
		case PORT_D:
		if (nibble==LOW_NIBBLE){
			PORTD_REG |= 0x0f;
		}
		else{
			PORTD_REG |= 0xf0;

		}
		break;
	}
}


void port_nibble_internal_pullup_disable(uint8 port, uint8 nibble){
	switch(port){
		case PORT_A:
		if (nibble==LOW_NIBBLE){
			PORTA_REG &= 0xf0;
		}
		else{
			PORTA_REG &= 0x0f;

		}
		break;
		
		case PORT_B:
		if (nibble==LOW_NIBBLE){
			PORTB_REG &= 0xf0;
		}
		else{
			PORTB_REG &= 0x0f;

		}
		break;


		case PORT_C:
		if (nibble==LOW_NIBBLE){
			PORTC_REG &= 0xf0;
		}
		else{
			PORTC_REG &= 0x0f;

		}
		break;
		
		
		case PORT_D:
		if (nibble==LOW_NIBBLE){
			PORTD_REG &= 0xf0;
		}
		else{
			PORTD_REG &= 0x0f;

		}
		break;
	}
}



void internal_pullup_enable(uint8 port, uint8 pin){
	switch(port){
		case PORT_A:
			SET_BIT(PORTA_REG,pin);
			break;
		case PORT_B:
			SET_BIT(PORTB_REG,pin);
			break;
		case PORT_C:
			SET_BIT(PORTC_REG,pin);
			break;
		case PORT_D:
			SET_BIT(PORTD_REG,pin);
			break;
	}
}

void internal_pullup_disable(uint8 port, uint8 pin){
	
	switch(port){
		case PORT_A:
		CLR_BIT(PORTA_REG,pin);
		break;
		case PORT_B:
		CLR_BIT(PORTB_REG,pin);
		break;
		case PORT_C:
		CLR_BIT(PORTC_REG,pin);
		break;
		case PORT_D:
		CLR_BIT(PORTD_REG,pin);
		break;
	}
}