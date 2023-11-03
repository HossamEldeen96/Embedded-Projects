#include "DIO_Interface.h"
#include "stdTypes.h"
#include "Utels.h"
#include "DIO_Interface.h"



void segment(u8 number)
{
	switch(number)
	{
		case 0:
		DIO_WritePin(PINB0,LOW);
		DIO_WritePin(PINB1,LOW);
		DIO_WritePin(PINB2,LOW);
		DIO_WritePin(PINB4,LOW);
		break;
		case 1:
		DIO_WritePin(PINB0,HIGH);
		DIO_WritePin(PINB1,LOW);
		DIO_WritePin(PINB2,LOW);
		DIO_WritePin(PINB4,LOW);
		break;
		case 2:
		DIO_WritePin(PINB0,LOW);
		DIO_WritePin(PINB1,HIGH);
		DIO_WritePin(PINB2,LOW);
		DIO_WritePin(PINB4,LOW);
		break;
		case 3:
		DIO_WritePin(PINB0,HIGH);
		DIO_WritePin(PINB1,HIGH);
		DIO_WritePin(PINB2,LOW);
		DIO_WritePin(PINB4,LOW);
		break;
		case 4:
		DIO_WritePin(PINB0,LOW);
		DIO_WritePin(PINB1,LOW);
		DIO_WritePin(PINB2,HIGH);
		DIO_WritePin(PINB4,LOW);
		break;
		case 5:
		DIO_WritePin(PINB0,HIGH);
		DIO_WritePin(PINB1,LOW);
		DIO_WritePin(PINB2,HIGH);
		DIO_WritePin(PINB4,LOW);
		break;
		case 6:
		DIO_WritePin(PINB0,LOW);
		DIO_WritePin(PINB1,HIGH);
		DIO_WritePin(PINB2,HIGH);
		DIO_WritePin(PINB4,LOW);
		break;
		case 7:
		DIO_WritePin(PINB0,HIGH);
		DIO_WritePin(PINB1,HIGH);
		DIO_WritePin(PINB2,HIGH);
		DIO_WritePin(PINB4,LOW);
		break;
		case 8:
		DIO_WritePin(PINB0,LOW);
		DIO_WritePin(PINB1,LOW);
		DIO_WritePin(PINB2,LOW);
		DIO_WritePin(PINB4,HIGH);
		break;
		case 9:
		DIO_WritePin(PINB0,HIGH);
		DIO_WritePin(PINB1,LOW);
		DIO_WritePin(PINB2,LOW);
		DIO_WritePin(PINB4,HIGH);
		break;
		
	}
}
