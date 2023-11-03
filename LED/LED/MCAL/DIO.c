
#include "DIO_Interface.h"
#include "stdTypes.h"
#include "Utels.h"


extern const DIO_PinStatus_type DIO_PinsStatusArr[TOTAL_PINS];


void DIO_Init(void)
{
	DIO_Pin_type i;
	for (i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,DIO_PinsStatusArr[i]);
		
	}
}





void   DIO_voidSetPortValue(u8 copy_u8PortID,u8 copy_u8PortVal )    
{
	switch (copy_u8PortID)
	{
		case PA:
		PORTA=copy_u8PortVal;
		break;
		case PB:
		PORTB=copy_u8PortVal;
		break;
		case PC:
		PORTC=copy_u8PortVal;
		break;
		case PD:
		PORTD=copy_u8PortVal;
		break;
		
	}
	
}

void	DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinDir)
{
	switch (Copy_u8PortID)
	{
		case PA:
		if (Copy_u8PinDir)
		{
			SET_BIT(DDRA,Copy_u8PinID);
		} 
		else
		{
			CLR_BIT(DDRA,Copy_u8PinID);
			SET_BIT(PORTA,Copy_u8PinID);
			
		}
		break;
		case PB:
		
		if (Copy_u8PinDir)
		{
			SET_BIT(DDRB,Copy_u8PinID);
			
			
		}
		else
		{
			CLR_BIT(DDRB,Copy_u8PinID);
			SET_BIT(PORTB,Copy_u8PinID);
		}
		break;
		case PC:
		
		if (Copy_u8PinDir)
		{
			SET_BIT(DDRC,Copy_u8PinID);
		}
		else
		{
			CLR_BIT(DDRC,Copy_u8PinID);
			SET_BIT(PORTC,Copy_u8PinID);
		}
		break;
		case PD:
		
		if (Copy_u8PinDir)
		{
			SET_BIT(DDRD,Copy_u8PinID);
		}
		else
		{
			CLR_BIT(DDRD,Copy_u8PinID);
			SET_BIT(PORTD,Copy_u8PinID);
		}
		break;
		
	}
}
void    DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue)
{
	switch (Copy_u8PortID)
	{
		case PA:
		if (Copy_u8PinValue)
		{
			SET_BIT(PORTA,Copy_u8PinID);
		}
		else
		{
			CLR_BIT(PORTA,Copy_u8PinID);
		}
		break;
		case PB:
		
		if (Copy_u8PinValue)
		{
			SET_BIT(PORTB,Copy_u8PinID);
		}
		else
		{
			CLR_BIT(PORTB,Copy_u8PinID);
		}
		break;
		case PC:
		
		if (Copy_u8PinValue)
		{
			SET_BIT(PORTC,Copy_u8PinID);
		}
		else
		{
			CLR_BIT(PORTC,Copy_u8PinID);
		}
		break;
		case PD:
		
		if (Copy_u8PinValue)
		{
			SET_BIT(PORTD,Copy_u8PinID);
		}
		else
		{
			CLR_BIT(PORTD,Copy_u8PinID);
		}
		break;
		
	}
}


u8 DIO_voidGetBitValue(u8 copy_u8PortID , u8 copy_PinID )
{
	u8 r;
	switch (copy_u8PortID)
	{
		case PA:
		r=READ_BIT(PINA,copy_PinID);
		return r;
		break;
		case PB:		
		r=READ_BIT(PINB,copy_PinID);
		return r;
		break;
		case PC:		
		r=READ_BIT(PINC,copy_PinID);
		return r;
		break;
		case PD:		
		r=READ_BIT(PIND,copy_PinID);
		return r;
		break;
		
	}
	
}



void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	u8 Pin_num=pin%8;
	DIO_Port_type port=pin/8;
	switch(status)
	{
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,Pin_num);
			CLR_BIT(PORTA,Pin_num);
			break;
			case PB:
			SET_BIT(DDRB,Pin_num);
			CLR_BIT(PORTB,Pin_num);
			break;
			case PC:
			SET_BIT(DDRC,Pin_num);
			CLR_BIT(PORTC,Pin_num);
			break;
			case PD:
			SET_BIT(DDRD,Pin_num);
			CLR_BIT(PORTD,Pin_num);
			break;
			
		}
		break;
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,Pin_num);
			CLR_BIT(PORTA,Pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,Pin_num);
			CLR_BIT(PORTB,Pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,Pin_num);
			CLR_BIT(PORTC,Pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,Pin_num);
			CLR_BIT(PORTD,Pin_num);
			break;
		}
		break;
		case INPULL:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,Pin_num);
			SET_BIT(PORTA,Pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,Pin_num);
			SET_BIT(PORTB,Pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,Pin_num);
			SET_BIT(PORTC,Pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,Pin_num);
			SET_BIT(PORTD,Pin_num);
			break;
		}
		break;
		
	}
}


void DIO_WritePin(DIO_Pin_type pin ,DIO_PinVoltage_type volt)
{
	u8 Pin_num=pin%8;
	DIO_Port_type port=pin/8;
	if (volt==HIGH)
	{
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,Pin_num);
			break;
			case PB:
			SET_BIT(PORTB,Pin_num);
			break;
			case PC:
			SET_BIT(PORTC,Pin_num);
			break;
			case PD:
			SET_BIT(PORTD,Pin_num);
			break;
		}
	}
	else
	{
		switch(port)
		{
			case PA:
			CLR_BIT(PORTA,Pin_num);
			break;
			case PB:
			CLR_BIT(PORTB,Pin_num);
			break;
			case PC:
			CLR_BIT(PORTC,Pin_num);
			break;
			case PD:
			CLR_BIT(PORTD,Pin_num);
			break;
		}
	}
}
void DIO_WritePort(DIO_Port_type port,u8 data){	switch (port)	{		case PA:		PORTA = data;		break;				case PB:		PORTB = data;		break;				case PC:		PORTC = data;		break;				case PD:		PORTD = data;		break;	}}

DIO_PinVoltage_type	DIO_ReadPin(DIO_Pin_type pin)
{
	u8 Pin_num=pin%8;
	DIO_Port_type port=pin/8;
	DIO_PinVoltage_type volt=LOW;
	switch(port)
	{
		case PA:
		volt=READ_BIT(PINA,Pin_num);
		break;
		case PB:
		volt=READ_BIT(PINB,Pin_num);
		break;
		case PC:
		volt=READ_BIT(PINC,Pin_num);
		break;
		case PD:
		volt=READ_BIT(PIND,Pin_num);
		break;
	}
	return volt;
}

void DIO_TogglePin(DIO_Pin_type pin)
{
	u8 Pin_num=pin%8;
	DIO_Port_type port=pin/8;
	switch (port)
	{
		case PA:
		TOGGEL_BIT(PORTA,Pin_num);
		break;
		case PB:
		TOGGEL_BIT(PORTB,Pin_num);
		break;
		case PC:
		TOGGEL_BIT(PORTC,Pin_num);
		break;
		case PD:
		TOGGEL_BIT(PORTD,Pin_num);
		break;
	}
	
}

