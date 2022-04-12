#include "stm32f4xx.h"                  // Device header
#include "LCD8.h"
#include "GPIO.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define PORTD0 GPIOC
#define PIND0  0
#define PORTD1 GPIOC
#define PIND1  1
#define PORTD2 GPIOC
#define PIND2  2
#define PORTD3 GPIOC
#define PIND3  3
#define PORTD4 GPIOA
#define PIND4  1
#define PORTD5 GPIOC
#define PIND5  4
#define PORTD6 GPIOC
#define PIND6  5
#define PORTD7 GPIOA
#define PIND7  6

#define RSPORT GPIOA
#define RSPIN  7
#define RWPORT GPIOA
#define RWPIN  0
#define ENPORT GPIOB
#define ENPIN  0




void wait_For_t(int Moment){

   volatile int x,i;
	for(i=0;i<Moment;i++)
	{
    for(x=0; x<6000; x++);    /* loop to generate 1 millisecond delay with Cclk = 60MHz */
	}
}


void LCD_Char_Distribute(char cData){
	
	//check bit for PC0
	if (cData & 1){
		//using BSRR to turn on
	PORTD0->BSRR |= (1<<PIND0);
	
	}
	else{
	PORTD0->BSRR |= (1<<(PIND0+16));
		
	}
	//check bit for PC1
	if (cData & 2){
		//using BSRR to turn on
	PORTD1->BSRR |= (1<<PIND1);
	
	}
	else{
	PORTD1->BSRR |= (1<<(PIND1+16));
		
	}
	//check bit for PC2
	if (cData & 4){
		//using BSRR to turn on
	PORTD2->BSRR |= (1<<PIND2);
	
	}
	else{
	PORTD2->BSRR |= (1<<(PIND2+16));
		
	}
	//check bit for PC3
	if (cData & 8){
		//using BSRR to turn on
	PORTD3->BSRR |= (1<<PIND3);
	
	}
	else{
	PORTD3->BSRR |= (1<<(PIND3+16));
		
	}
	//check bit for PA1
	if (cData & 16){
		//using BSRR to turn on
	PORTD4->BSRR |= (1<<PIND4);
	
	}
	else{
	PORTD4->BSRR |= (1<<(PIND4+16));
		
	}
	//check bit for PC4
	if (cData & 32){
		//using BSRR to turn on
	PORTD5->BSRR |= (1<<PIND5);
	
	}
	else{
	PORTD5->BSRR |= (1<<(PIND5+16));
		
	}
	//check bit for PC5
	if (cData & 64){
		//using BSRR to turn on
	PORTD6->BSRR |= (1<<PIND6);
	
	}
	else{
	PORTD6->BSRR |= (1<<(PIND6+16));
		
	}
	//check bit for PA6
	if (cData & 128){
		//using BSRR to turn on
	PORTD7->BSRR |= (1<<PIND7);
	
	}
	else{
	PORTD7->BSRR |= (1<<(PIND7+16));
		
	}
	
}



void LCD_CMD(char cmd){
	
  LCD_Char_Distribute(cmd);
	wait_For_t(2);
//set high to enable
	GPIOB->BSRR |= GPIO_BSRR_BS0;
//write 0 to RS to select command register
	RSPORT->BSRR |= (1<<(RSPIN+16));
//write 0 to RW to select writing
	RWPORT->BSRR |= (1<<(RWPIN+16));
	wait_For_t(2);
	
	//set low to enable
	GPIOB->BSRR |= GPIO_BSRR_BR0;
//wait 20useconds
	wait_For_t(5);
}

void LCD_Char(char sing){
	LCD_Char_Distribute(sing);
	wait_For_t(2);
//set high to enable
	GPIOB->BSRR |= GPIO_BSRR_BS0;
//write 1 to RS to select data register
	RSPORT->BSRR |= (1<<RSPIN);
//write 0 to RW to select writing
	//RWPORT->BSRR |= (1<<(RWPIN+16));
	wait_For_t(2);
	
	//set low to enable
	GPIOB->BSRR |= GPIO_BSRR_BR0;
//wait 20useconds
	wait_For_t(5);
}
	
void LCD_INIT(void){

	 /* Make LCD command port direction as output pins*/
		CLOCK_INIT_PORTA();
	  CLOCK_INIT_PORTB();
	  CLOCK_INIT_PORTC();
    GPIOC_Pin_0();
    GPIOC_Pin_1();
    GPIOC_Pin_2();
    GPIOC_Pin_3();
	  //GPIOA_Pin_0();
    GPIOA_Pin_1();
	  GPIOC_Pin_4();
	  GPIOC_Pin_5();
	  GPIOA_Pin_6();
	
	  GPIOA_Pin_7();//RS
	  //GPIOC_Pin_13();//RW
	  GPIOA_Pin_0();
	  //GPIOC_Pin_14();//EN
	  //GPIOA_Pin_2();
	  GPIOB_Pin_0();

     wait_For_t(20);
	
	LCD_CMD(0x38);  /* Initialize lcd */
	LCD_CMD(0x0C);   /* Display on cursor off */
	LCD_CMD(0x06);  /* Auto increment cursor */
	LCD_CMD(0x01);   /* Display clear */
	LCD_CMD(0x80);  /* First line first position */
}

	
/*Clear LCD Function*/
void LCD_Clear(void){
LCD_CMD(0x01); /* clear display */
LCD_CMD(0x02); /* Return display to its home position */
}

/*Send string to LCD function */
void LCD_String (char *str){
int i;
/* Send each char of string till the NULL */
for(i=0;str[i]!=0;i++){
LCD_Char(str[i]);
}
}


/*Send string to LCD with xy position */
void LCD_String_xy (char row, char pos, char *str){
if (row == 0 && pos<16){
LCD_CMD((pos & 0x0F)|0x80);/* Command of first row and required
position<16 */
}
else if (row == 1 && pos<16){
LCD_CMD((pos & 0x0F)|0xC0);/* Command of second row and required
position<16 */
}
LCD_String(str); /* Call LCD string function */
}



void LCD_int(volatile uint32_t number)
{

char k[4];
sprintf(k, "%d", number);
	LCD_String(k);
	

}

void LCD_Int_xy(char c, char z, volatile uint32_t r)
{
char k[4];
sprintf(k, "%d", r);
LCD_String_xy(c, z, k);

}

