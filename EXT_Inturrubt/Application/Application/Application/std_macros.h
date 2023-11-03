

#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define F_CPU 16000000UL
#include <util/delay.h>


#define  READ_BIT(reg,bit)  ((reg>>bit)&1)
#define  SET_BIT(reg,bit)   (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit) (reg=reg&~(1<<bit))
#define  TOGGEL_BIT(reg,bit)  (reg=reg ^(1<<bit))


#include "Bit_math.h"
#include "std_types.h"
#include "memMap.h"


#endif /* STD_MACROS_H_ */