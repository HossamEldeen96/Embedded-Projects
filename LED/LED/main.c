#include "stdTypes.h"
#include "Utels.h"
#include "DIO_Interface.h"
#include "LED.h"
#include "LCD_Cfg.h"
#include "LCD_Interface.h"
#include "EXT_Interface.h"
#include "EXT_Private.h"

int main(void)
{
    /* Replace with your application code */
	
	
	DIO_Init();
	LCD_Init();
	EXI_Init();
//	GLOBAL_ENABLE;
	
	
	/*
	LCD_GoTo(0,0);
	LCD_Clear();
	LCD_WriteString("HOSSAM ELDEEN  EBRAHIM");
	*/
	;

	void f1(void)
	{
		DIO_TogglePin(PINA6);
	}
	
	EXI_SetCallBack(EX_INT1,f1);
	
	while(1)
	{	
		
		
		/*_delay_ms(5);
			segment(1);
		DIO_WritePin(PINB6,LOW);
		DIO_WritePin(PINB5,HIGH);
		DIO_WritePin(PINA2,HIGH);
		DIO_WritePin(PINA3,HIGH);
		_delay_ms(5);
		segment(8);
		DIO_WritePin(PINB6,HIGH);
		DIO_WritePin(PINB5,LOW);
		DIO_WritePin(PINA2,HIGH);
		DIO_WritePin(PINA3,HIGH);
		_delay_ms(5);
		segment(7);
		DIO_WritePin(PINB6,HIGH);
		DIO_WritePin(PINB5,HIGH);
		DIO_WritePin(PINA2,LOW);
		DIO_WritePin(PINA3,HIGH);
		_delay_ms(5);
		segment(9);
		DIO_WritePin(PINB6,HIGH);
		DIO_WritePin(PINB5,HIGH);
		DIO_WritePin(PINA2,HIGH);
		DIO_WritePin(PINA3,LOW);
		*/
	}
	
 

}

