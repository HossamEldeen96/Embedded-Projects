/*
 * KEYPAD.h
 *
 * Created: 3/7/2023 3:09:34 PM
 *  Author: Ali
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_macros.h"

void KEYPAD_init(void);
int8 KEYPAD_read(void);
uint8 get_input_from_user(void);


#endif /* KEYPAD_H_ */