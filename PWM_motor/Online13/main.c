#include "MemMap.h"
#include "StdTypes.h"
#include "Utels.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "MOTOR_Interface.h"
#include "Keypad_Interface.h"
#include "Keypad_CFG.h"
#include "ADC_Interface.h"
#include "Sensors_Interface.h"
#include "EX_Interrupt_Interface.h"

u32 volatile c, t=0;
u8 flag1=0;
void f1(void)
{	TCNT0=0;
	c=0;
	t=0;
	DIO_TogglePin(PINC0);
	TCCR0=2; //prescaller 8
	SET_BIT(TIMSK,0);
	flag1=1;
}
u16 adc=0;
int main()
{
	DIO_Init();
	LCD_Init();
	ADC_Init(VREF_AVCC,ADC_SCALLER_64);
	LCD_GoTo(0,0);
	LCD_WriteString("Volt read");
	LCD_GoTo(1,0);
	LCD_WriteString("PWM_duty ");
	TCCR0=2; //prescaller 8
	MOTOR_CW(M1);
	SET_BIT(TCCR0,COM01);
	//SET_BIT(TCCR0,COM00);  // CLEAR AT COMPARE MATCH 
	SET_BIT(TCCR0,WGM01);  //PWM FAST MODE
	SET_BIT(TCCR0,WGM00);
		
	u8 x=0;	
	OCR0=100;
	while(1)
	{	
		
		adc=ADC_voltRaed(CH_0);
		LCD_GoTo(0,10);
		LCD_WriteNumber(adc);
		adc=ADC_Read(CH_0);		
		LCD_WriteString("mV   ");
		OCR0=(adc/4)-256;
		LCD_GoTo(1,9);
		LCD_WriteNumber(OCR0);
		LCD_WriteString("   ");
	    
}
}


