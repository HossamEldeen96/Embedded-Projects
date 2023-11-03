


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_Interface.h"
#include "stdTypes.h"
#include "Utels.h"



typedef enum{
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_type;



typedef enum{
	OUTPUT,
	INFREE,
	INPULL
}DIO_PinStatus_type;

typedef enum{
	PA=0,
	PB,
	PC,
	PD
}DIO_Port_type;

typedef enum{
	LOW=0,
	HIGH
}DIO_PinVoltage_type;



/*
#define PA 1
#define PB 2
#define PC 3
#define PD 4*/

void    DIO_voidSetPortDirection(u8 copy_u8PortID,u8 copy_u8PortDir );
void    DIO_voidSetPortValue(u8 copy_u8PortID,u8 copy_u8PortVal )    ;

void	DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir);
void    DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);


u8 DIO_voidGetBitValue(u8 copy_u8PortID , u8 copy_PinID );





void DIO_Init(void);
void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);

void DIO_InitPin2(DIO_Port_type port,u8 pin_num,DIO_PinStatus_type status);


void DIO_WritePin(DIO_Pin_type pin ,DIO_PinVoltage_type volt);
DIO_PinVoltage_type	DIO_ReadPin(DIO_Pin_type pin);
/* output only
*pin PINA0:PIND7  */

void DIO_TogglePin(DIO_Pin_type pin);
void DIO_WritePort(DIO_Port_type port,u8 data);
u8 DIO_ReadPort(DIO_Port_type port);


/* DIO_Registers */
#define DDRA (*(volatile unsigned char*)0x3A)
#define DDRB (*(volatile unsigned char*)0x37)
#define DDRC (*(volatile unsigned char*)0x34)
#define DDRD (*(volatile unsigned char*)0x31)

#define PINA (*(volatile unsigned char*)0x39)
#define PINAA (*(volatile unsigned char*)0x39)
#define PINB (*(volatile unsigned char*)0x36)
#define PINC (*(volatile unsigned char*)0x33)
#define PIND (*(volatile unsigned char*)0x30)

#define PORTA (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*)0x35)
#define PORTD (*(volatile unsigned char*)0x32)
/********************************************************************************************************/

#endif /* DIO_INTERFACE_H_ */