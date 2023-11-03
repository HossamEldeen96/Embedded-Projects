#include "MemMap.h"
#include "StdTypes.h"
#include "Utels.h"
#include "DIO_Interface.h"

#include "ADC_Interface.h"
#include "EX_Interrupt_Interface.h"
#include "Timers.h"
#include "LCD_Interface.h"
u8 flag_c=0;
u8 flag_PWM=1;
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
	void(PWM_led_duty25_8MHZ)(void)
	{
		DIO_TogglePin(PINA5);
		if (flag_PWM==1)
		{
			TCNT0=245;
			flag_PWM=0;
		}
		else
		{
			TCNT0=225;
			flag_PWM=1;
		}
		
	} 
void(PWM_led_duty25)(void)
{
	DIO_TogglePin(PINA5);
	if (flag_PWM==1)
	{
		TCNT0=250;
		flag_PWM=0;
	} 
	else
	{
		TCNT0=240;
		flag_PWM=1;
	}
	
}
void(PWM_led_duty50)(void)
{
	DIO_TogglePin(PINA6);
	if (flag_PWM==1)
	{
		TCNT0=246;
		flag_PWM=0;
	}
	else
	{
		TCNT0=246;
		flag_PWM=1;
	}
	
}

void(PWM_led_duty75)(void)
{
	DIO_TogglePin(PINA5);
	if (flag_PWM==1)
	{
		TCNT0=240;
		flag_PWM=0;
	}
	else
	{
		TCNT0=250;
		flag_PWM=1;
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
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	LCD_GoTo(0,0);
	LCD_WriteString("TimBB");
	TIMER0_OC0Mode(OC0_INVERTING);
	
//    TIMER0__SetCallBack(PWM_led_duty50);	
//     sei();
//     TIMER0_OV_InterruptEnable();
    
	u8 x=0;
	while(1)
	{  
		LCD_GoTo(0,0);		
		LCD_WriteString(" Hossam Led   ");
		OCR0=64;
		
	
		
	}
}


