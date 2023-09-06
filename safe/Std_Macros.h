#ifndef Std_macros
#define Std_macros


typedef unsigned char uint8;
typedef int uint16;


#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7


#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#define NULL ((volatile void*)0)
#define HIGH 1
#define LOW  0

#define OUTPUT   0
#define INPUT	 1




#define SET_BIT(Port,Pin)  (Port|=(1<<Pin))
#define CLR_BIT(Port,Pin)  (Port &= ~(1<<Pin))
#define TOG_BIT(Port,Pin)  (Port ^= (1<<Pin))
#define GET_BIT(Port,Pin)  ((Port & (1<<Pin))>>Pin)


#endif
