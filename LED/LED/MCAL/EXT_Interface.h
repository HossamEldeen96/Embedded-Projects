/*
 * EXT_Interface.h
 *
 * Created: 10/22/2023 2:05:57 PM
 *  Author: Zahraa Ahmed Selim
 */ 


#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_


typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}TriggerEdge_type;

typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}ExInterruptSource_type;


void EXI_Init(void);

#define   GLOBAL_ENABLE    sei

void EXI_Enable(ExInterruptSource_type Interrupt);
void EXI_Disable(ExInterruptSource_type Interrupt);
void EXI_TriggerEdge(ExInterruptSource_type Interrupt,TriggerEdge_type Edge);
void EXI_SetCallBack(ExInterruptSource_type Interrupt,void(*LocalPtr)(void));








#endif /* EXT_INTERFACE_H_ */