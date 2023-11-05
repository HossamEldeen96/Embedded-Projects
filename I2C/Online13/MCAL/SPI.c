#include "StdTypes.h"
#include "MemMap.h"
#include "Utels.h"
#include "DIO_Interface.h"
#include "SPI_interface.h"


void SPI_Init(void )
{
	DIO_InitPin(PINB4,OUTPUT);
	DIO_InitPin(PINB5,OUTPUT);
	DIO_InitPin(PINB6,INFREE);
	DIO_InitPin(PINB7,OUTPUT);
	// SLAVE OR MASTER
	#if SPI_MODE
	SET_BIT(SPCR,MSTR);
	//clock 2mhz
// 	SET_BIT(SPCR,SPR0);
// 	CLR_BIT(SPCR,SPR1);
	#else
	CLR_BIT(SPCR,MSTR);
	#endif
	//enable
	SET_BIT(SPCR,SPE);
	CLR_BIT(SPSR,SPI2X);
}


u8 SPI_SendReceive(u8 data)
{
	
	// write puffer
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	//READ PUFFER
	return SPDR;
	
}