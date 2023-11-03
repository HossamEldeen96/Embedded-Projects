

#ifndef MEMMAP_H_
#define MEMMAP_H_
#include "std_types.h"

#define PORTA *((volatile uint8 *)0x3B)
#define PORTB *((volatile uint8 *)0x38)
#define PORTC *((volatile uint8 *)0x35)
#define PORTD *((volatile uint8 *)0x32)

#define DDRA *((volatile uint8 *)0x3A)
#define DDRB *((volatile uint8 *)0x37)
#define DDRC *((volatile uint8 *)0x34)
#define DDRD *((volatile uint8 *)0x31)

#define PINA *((volatile uint8 *)0x39)
#define PINB *((volatile uint8 *)0x36)
#define PINC *((volatile uint8 *)0x33)
#define PIND *((volatile uint8 *)0x30)


/* ADC_Registers */
#define ADMUX (*(volatile unsigned char*)0x27)

#define ADLAR 5
#define REFS0 6
#define REFS1 7


#define ADCSRA (*(volatile unsigned char*)0x26)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7
#define ADTS0 5
#define ADTS1 6
#define ADTS2 7


#define ADCL (*(volatile unsigned char*)0x24)
#define ADCH (*(volatile unsigned char*)0x25)
#define ADC (*(volatile unsigned short*)0x24)

#define SFIOR (*(volatile unsigned char*)0x50)

/********************************************************************************************************/


#endif /* MEMMAP_H_ */