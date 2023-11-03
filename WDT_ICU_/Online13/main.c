#include "MemMap.h"
#include "StdTypes.h"
#include "Utels.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "SPI_interface.h"

u8 flag_c=0;
u8 flag_PWM=1;
u16 C=2020;


int main()
{
	DIO_Init();
	
	LCD_Init();
	SPI_Init();
	
	LCD_GoTo(0,0);	
	LCD_WriteString("SPI Test");

	u8 x=20;
	u8 i=8,y=5,j=8;
	_delay_ms(1000);
	LCD_GoTo(1,5);
	LCD_WriteNumber(x);
	while(1)
	{  
		
		y=SPI_SendReceive(x);
		LCD_GoTo(1,5);
		LCD_WriteNumber(x);
		LCD_WriteString("  Recive ");
		LCD_WriteNumber(y);
		x++;
		_delay_ms(1000);
		
		
		
	}
}


