#include "MemMap.h"
#include "StdTypes.h"
#include "Utels.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "I2C_Interface.h"


int main()
{
	DIO_Init();
	LCD_Init();
	
	I2C_SLAVE_INIT(0x03);
	
	
	LCD_GoTo(0,0);
	LCD_WriteString("I2C Test");
	LCD_GoTo(1,0);
	LCD_WriteString("Recive:");

	u16 i=30,y=5,j=8;

	while(1)
	{
		
		if(I2C_slave_avialable())
		{
			DIO_TogglePin(PINA6);
			I2C_Send_Master_Read_Byte(&i);
			LCD_GoTo(1,7);
			LCD_WriteNumber(i);
			LCD_WriteString("   ");
			_delay_ms(1000);
			
		}
		
		
		
		
		
		
		
		
		
	}
}


