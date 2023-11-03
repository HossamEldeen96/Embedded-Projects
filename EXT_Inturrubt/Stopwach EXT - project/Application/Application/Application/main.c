

#include "std_macros.h"
#include "LED.h"
#include "Button.h"
#include "LCD.h"
#include "SevenSeg.h"
#include "KEYPAD.h"

#include "DIO.h"
#include "EXT_Interface.h"
#include "GIE_Interface.h"
#include "ADC_Interface.h"

uint8 flag=0;


//callback function 
void flagTpggel(void)
{
	if (flag==0)
	{
		flag=1;
	} 
	else
	{flag=0;
	}
	}




int main(void)
{	
	
	LCD_init();
	LCD_GoTo(0,5);
	LCD_write_string("Hossam ");
	
	ADC_Init(VREF_AREF,ADC_SCALLER_128);
	
	/*LCD_GoTo(1,5);
	LCD_write_string("Hossam1 ");
	LCD_GoTo(2,5);
	LCD_write_string("Hossam2 ");
	LCD_GoTo(3,5);
	LCD_write_string("Hossam3 ");
	*/
	
	uint32 c=0;
	EXT_init(EXT1, FALLING);
	EXT_callback(flagTpggel, EXT1);
	GIE_Enable();
	
	sevenseg_init();
	uint32 temp =c;
	while(1){
	
	
	for (uint8 i=0;i<100;i++)
	{
		 temp =c;
		sevenseg_write(temp%10, 1);temp/=10;_delay_ms(1);
		sevenseg_write(temp%10, 2);temp/=10;_delay_ms(1);
		sevenseg_write(temp%10, 3);temp/=10;_delay_ms(1);
		sevenseg_write(temp%10, 4);temp/=10;_delay_ms(1);
		
	}
		
		if (flag==0)
		{
			c++;
		} 
		else
		{
			c--;
		}
	
		 
		
		
		

	}
    
}



