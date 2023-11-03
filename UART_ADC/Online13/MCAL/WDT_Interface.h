

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

typedef enum
{
	TIME_OUT16_3ms=0,
	TIME_OUT32_5ms,
	TIME_OUT65ms,
	TIME_OUT0_13ms,
	TIME_OUT0_26ms,
	TIME_OUT0_52ms,
	TIME_OUT1sec,
	TIME_OUT2_1sec

}TIME_OUT_type;


void WDT_Enable(u8 WDT_Time);
void WDT_Disable(void);



#endif /* WDT_INTERFACE_H_ */