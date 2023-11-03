#include "StdTypes.h"
#include "MemMap.h"
#include "Utels.h"
#include "WDT_Interface.h"

void WDT_Enable(TIME_OUT_type WDT_Time)
{
	
	switch(WDT_Time)
	{
		case TIME_OUT16_3ms:
		CLR_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
		break;
		case TIME_OUT32_5ms:
		SET_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
		break;
		case TIME_OUT65ms:
		CLR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
		break;
		case TIME_OUT0_13ms:
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		CLR_BIT(WDTCR,WDP2);
		break;
		case TIME_OUT0_26ms:
		CLR_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
		break;
		case TIME_OUT0_52ms:
		SET_BIT(WDTCR,WDP0);
		CLR_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
		break;
		case TIME_OUT1sec:
		CLR_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
		break;
		case TIME_OUT2_1sec:
		SET_BIT(WDTCR,WDP0);
		SET_BIT(WDTCR,WDP1);
		SET_BIT(WDTCR,WDP2);
		break;
		
	}
	SET_BIT(WDTCR,WDE);
}

void WDT_Disable(void)
{
	WDTCR=0x18;	
	CLR_BIT(WDTCR,WDE);
	
}
