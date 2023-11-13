#include "MemMap.h"
#include "StdTypes.h"
#include "Utels.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "MOTOR_Interface.h"


#include "ADC_Interface.h"
#include "Sensors_Interface.h"


u16 FILTER_GetFilterdTemp(void);


u16 smoke,volt,temp,adc;
u8 flag_fine=1,flafg_heat=1,flag_SMOKE=0;
void fine(void)
{	
	LCD_GoTo(0,3);
	LCD_WriteString("ALL IS Fine  ");
	DIO_WritePin(PINC0,HIGH);
}

u8 heat(void){
	LCD_GoTo(0,1);
	LCD_WriteString("Heat Detected");
	DIO_WritePin(PINC0,LOW);
	DIO_WritePin(PINC1,HIGH);
	DIO_WritePin(PINC2,LOW);
	while(1)
	{
		FILTER_Runnable();
		temp=FILTER_GetFilterdTemp();
		
		
		
		LCD_GoTo(1,2);
		LCD_WriteNumber(temp/10);
		LCD_WriteString("  ");		
		
			
		if (temp<=450)
		{	MOTOR_Stop(M1);
			DIO_WritePin(PINC1,LOW);
			LCD_GoTo(0,0);
			LCD_WriteString("      ");
			return 1;
		}
		smoke=PRESS_read();
		if (smoke>=400)
		{
			LCD_GoTo(1,7);
			LCD_WriteString("Smoke%");
			smoke=PRESS_read()+3;
			LCD_WriteNumber(smoke/10);			
		}
	    if (smoke>500)
		{
			flag_SMOKE=1;
			return 0;			
		}
	}
}


void smoke_f(void)
{
	LCD_GoTo(0,1);
	LCD_WriteString("Smoke Detected");
	DIO_WritePin(PINC0,LOW);
	DIO_WritePin(PINC1,LOW);
	DIO_WritePin(PINC2,HIGH);
	LCD_GoTo(1,7);
	LCD_WriteString("Smoke%");
	while (flag_SMOKE)
	{	
		LCD_GoTo(1,13);
		smoke=PRESS_read()+3;
		LCD_WriteNumber(smoke/10);
		MOTOR_CW(M1);
	}
	
	
}



int main(void)
{
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALLER_64);
	MOTOR_Init();
	FILTER_Init();
	
	TCCR0=2; //prescaller 8
	
	SET_BIT(TCCR0,COM01);
	//SET_BIT(TCCR0,COM00);  // CLEAR AT COMPARE MATCH
	SET_BIT(TCCR0,WGM01);  //PWM FAST MODE
	SET_BIT(TCCR0,WGM00);
	OCR0=100;
	
	LCD_GoTo(0,1);
	LCD_WriteString("ALL Fine");
	
	_delay_ms(1000);
	while(1)
	{
		FILTER_Runnable();
		temp=FILTER_GetFilterdTemp();
							
		if (!DIO_ReadPin(PIND4))
		{
		LCD_GoTo(1,5);
		LCD_WriteNumber(temp/10);
		LCD_WriteString("  ");
		LCD_GoTo(0,0);
		LCD_WriteString("Flame happen");		
		}
		if (!DIO_ReadPin(PIND5))
		{
			
			DIO_WritePin(PINC6,HIGH);
			MOTOR_CW(M1);
			adc=ADC_voltRaed(CH_0);
			OCR0=(adc/4)-256;
		}
		else
		{
			DIO_WritePin(PINC6,LOW);
			MOTOR_Stop(M1);
		}
		
		
	
	
	}
	}
	
	


	
	

		
					

