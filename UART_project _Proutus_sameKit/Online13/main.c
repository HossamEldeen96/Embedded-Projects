#include "MemMap.h"
#include "StdTypes.h"
#include "Utels.h"
#include "DIO_Interface.h"

#include "ADC_Interface.h"
#include "EX_Interrupt_Interface.h"
#include "Timers.h"
#include "LCD_Interface.h"
#include "WDT_Interface.h"
#include "UART_Interface.h"

u8 flag_c=0;
u8 flag_PWM=1;
u16 C=2020;


int main()
{
	DIO_Init();
	DIO_WritePin(PINB7,LOW);
	DIO_WritePin(PINA5,LOW);
	DIO_WritePin(PINA6,LOW);
	LCD_Init();
	
	LCD_GoTo(0,0);	
	LCD_WriteString("UART Test");

	ADC_Init(VREF_AVCC,ADC_SCALLER_128);
	UART_Init();
	

	
	u16 x=2020;
	u8 i=8,y=5,j=8;
	
	while(1)
	{  
		_delay_ms(500);
		x=ADC_voltRaed(CH_1)/10;
		LCD_GoTo(1,0);
		LCD_WriteNumber(x);
		LCD_WriteString("   ");
		UART_Send(x);
		y=UART_Receive();
		LCD_GoTo(1,10);
		LCD_WriteNumber(y);
		LCD_WriteString("   ");
		/*
		i=x/10;
		UART_Send(i+'0');		
		x=x%10;
		x=x+'0';
		UART_Send(x);
		y=UART_Receive();
		j=y-'0';
		LCD_GoTo(1,10);
		LCD_WriteNumber(j);
		LCD_WriteString("   ");
		y=UART_Receive();
		j=y-'0';
		LCD_GoTo(1,11);
		LCD_WriteNumber(j);
		LCD_WriteString("   ");
		*/
		
		
		/*x=UART_Receive();
		LCD_GoTo(1,i);
		LCD_WriteChar(x);
		LCD_WriteString("   ");
		if (x!=y)
		{
			i++;
			y=x;
						
		}
*/
		
		
	}
}


