#ifndef DOI_H
#define DIO_H

#include "../../Std_Macros.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define LOW_NIBBLE 0
#define HIGH_NIBBLE 1

#define PINA_REG  *((volatile uint8*) 0x39)
#define DDRA_REG   *((volatile uint8*) 0x3A)
#define PORTA_REG   *((volatile uint8*) 0x3B)

#define PINB_REG   *((volatile uint8*) 0x36)
#define DDRB_REG   *((volatile uint8*) 0x37)
#define PORTB_REG   *((volatile uint8*) 0x38)


#define PINC_REG   *((volatile uint8*) 0x33)
#define DDRC_REG   *((volatile uint8*) 0x34)
#define PORTC_REG   *((volatile uint8*) 0x35)

#define PIND_REG   *((volatile uint8*) 0x30)
#define DDRD_REG   *((volatile uint8*) 0x31)
#define PORTD_REG   *((volatile uint8*) 0x32)


void pin_init(uint8 port,uint8 pin,uint8 direction);
void pin_write(uint8 port,uint8 pin,uint8 direction);
void pin_toggle(uint8 port,uint8 pin);
uint8 pin_read(uint8 port,uint8 pin);



void port_init(uint8 port,uint8 direction);
void port_write(uint8 port,uint8 output);
void port_toggle(uint8 port);
uint8 port_read(uint8 port);

void port_nibble_init(uint8 port, uint8 nibble, uint8 direction);
void port_nibble_write(uint8 port, uint8 nibble, uint8 output);

void port_nibble_internal_pullup_enable(uint8 port, uint8 nibble);
void port_nibble_internal_pullup_disable(uint8 port, uint8 nibble);

void internal_pullup_enable(uint8 port, uint8 pin);
void internal_pullup_disable(uint8 port, uint8 pin);

#endif