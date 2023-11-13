


#ifndef LCD_CFG_H_
#define LCD_CFG_H_



#define _8_Bit 0
#define _4_Bit 1

/******************_8_Bit Or _4_Bit *******************/

#define LCD_MODE _4_Bit

#define RS PINA3
#define EN PINA2

/***************** Only for _4BIT *********************/

#define D4 PINB0
#define D5 PINB1
#define D6 PINB2
#define D7 PINB4


/***************** Only for _8BIT *********************/
#define LCD_PORT PA



#endif /* LCD_CFG_H_ */