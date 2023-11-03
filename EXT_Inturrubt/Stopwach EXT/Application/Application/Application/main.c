

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

uint16 adc=50,v,temp=0;

void adc_autotrigger(void)
{
	LCD_GoTo(0,12);
	LCD_write_string("PB DONE");
	//auto treggering Enable
	SET_BIT(ADCSRA,ADATE);
	//auto trigger configration
	CLR_BIT(SFIOR,ADTS0);
	SET_BIT(SFIOR,ADTS1);
	//auto trigger Desable
	CLR_BIT(SFIOR,ADTS2);
	  
  	temp=ADC;
	CLR_BIT(ADCSRA,ADATE);
	
}

int main(void)
{
	
	
	//DIO_voidSetPinDirection(portD, 7,OUTPUT);
	//DIO_voidSetPinValue(portD,5,LOW);
	
	DIO_voidSetPinDirection(portD, 2,INPULL);
	

	LCD_init();
	ADC_Init(VREF_AVCC,ADC_SCALLER_128);
	
	EXT_init(EXT0,FALLING);
	EXT_callback(adc_autotrigger,EXT0);
 	GIE_Enable();
	
	LCD_GoTo(0,0);
	LCD_write_string("LDR % =");
	LCD_GoTo(1,0);
	LCD_write_string("Temp = ");
	
	
	
	
	
	
	
	while(1){
		
		adc=ADC_voltRaed(CH_0);
		LCD_GoTo(0,7);
		LCD_write_number(adc);
		LCD_GoTo(1,6);
	//	temp=ADC_voltRaed(CH_1);
		
		LCD_write_number(temp/10);
		LCD_write_string("            ");
		_delay_ms(200);
	
		
		
		
	}
		
		

	
}



