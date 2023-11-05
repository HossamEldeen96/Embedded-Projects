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
	I2C_MASTER_INIT();
	
	
	LCD_GoTo(0,0);	
	LCD_WriteString("I2C Test");
	LCD_GoTo(1,0);
	LCD_WriteString("Send:");
	u8 slave1=20;
	u8 i=8,y=5,j=8;

	while(1)
	{  
		LCD_GoTo(1,7);
		LCD_WriteNumber(i);
		LCD_WriteString("   ");
		I2C_Send_Start_Condition();
			
		I2C_Send_Slave_Address_Write(0x03);
		
		I2C_Send_Master_Send_Byte(i);
		
		I2C_Send_Stop_Condition();
		i++;
		_delay_ms(500);
		
		
		
		
		
		
		
	}
}


