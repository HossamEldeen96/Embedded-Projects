
#ifndef UTELS_H_
#define UTELS_H_



#define  READ_BIT(reg,bit)  ((reg>>bit)&1)
#define  SET_BIT(reg,bit)   (reg=reg|(1<<bit))
#define  CLR_BIT(reg,bit) (reg=reg&~(1<<bit))
#define  TOGGEL_BIT(reg,bit)  (reg=reg ^(1<<bit))


#define F_CPU 16000000
#include <util/delay.h>







#endif /* UTELS_H_ */