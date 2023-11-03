#include "MemMap.h"
#include "StdTypes.h"
#include "Utels.h"
#include "DIO_Interface.h"

#include "ADC_Interface.h"
#include "EX_Interrupt_Interface.h"
#include "Timers.h"
#include "LCD_Interface.h"
u8 flag_c=0;
u16 C=2020;

void(Timer0_toggel1sec)(void)
{
	static u16 c;
	c++;

  if (c==7812)
		{
			DIO_TogglePin(PINA5);
			c=0;
			flag_c=0;
		}
	
		
	}
	 
	
void delay_sec(u32 t)
 {
    static u16 c;
	u32 i=0,j;
	for (i=0;i<t;i++)
	{
		
		for (j=0;j<7812;j++)
		{
			while (!READ_BIT(TIFR,TOV0));			
			SET_BIT(TIFR,TOV0);	
								
		}
		DIO_TogglePin(PINA5);
		
	}
	
	
 }
		

int main()
{
	DIO_Init();
	LCD_Init();
	TIMER0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8);
	LCD_GoTo(0,0);
	LCD_WriteString("TimBB");
	DIO_WritePin(PINA5,LOW);
  //TIMER0__SetCallBack(Timer0_toggel1sec);	
  // sei();
  //TIMER0_OV_InterruptEnable();


	u8 x=0;
	while(1)
	{  		
		LCD_GoTo(0,0);		
		LCD_WriteNumber(x);
		LCD_WriteString("    ");		
		delay_sec(1);
		x++;
		
	}
}


