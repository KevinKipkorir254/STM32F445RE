#ifndef LCD8_H_
#define LCD8_H_
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void LCD_Char_Distribute(char cData);
void LCD_Char(char cData);
void LCD_CMD(char cData);
void LCD_INIT(void);
void LCD_Clear(void);
void LCD_String (char *str);
void wait_For_t(int Moment);
void LCD_String_xy (char row, char pos, char *str);
void LCD_Int_xy(char c, char z, volatile uint32_t r);
void LCD_int(volatile uint32_t number);



#endif


