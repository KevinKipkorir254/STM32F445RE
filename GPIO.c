#include "stm32f4xx.h"                  // Device header
#include "GPIO.h"
/* In using this code for other PORTs remember to chage the Registers*/
//libraries to set pins 

//Setting the different clocks for the GPIOs

void CLOCK_INIT_PORTA (void){
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
}

void CLOCK_INIT_PORTB (void){
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
}

void CLOCK_INIT_PORTC (void){
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}

void CLOCK_INIT_PORTD (void){
RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
}

void CLOCK_INIT_PORTE (void){
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
}

void CLOCK_INIT_PORTF (void){
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
}

void CLOCK_INIT_PORTG (void){
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
}

void CLOCK_INIT_PORTH (void){
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
}

/*PORT configuration taht includes*/
//setting as General Output Mode
//Type register set to open push pull
//Speed of output high speed output
//Pull-up Pull-down Register

void GPIOA_Pin_0(void){
//setting Pin as General purpose output
	GPIOA->MODER |= GPIO_MODER_MODE0_0;
	GPIOA->MODER &=~ GPIO_MODER_MODE0_1;
	
	//Type Register set to open push pull
	GPIOA->OTYPER &=~ (GPIO_OTYPER_OT_0);

//Speed of output high speed output
   GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;

//No Pull-up Pull-down Register
    GPIOA->PUPDR 	&=~ (GPIO_PUPDR_PUPD0);
}


void GPIOA_Pin_1(void){
//setting Pin as General purpose output
	GPIOA->MODER |= GPIO_MODER_MODE1_0;
	GPIOA->MODER &=~ GPIO_MODER_MODE1_1;
	
	//Type Register set to open push pull
	GPIOA->OTYPER &=~ (GPIO_OTYPER_OT_1);

//Speed of output high speed output
   GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR1;

//No Pull-up Pull-down Register
    GPIOA->PUPDR 	&=~ (GPIO_PUPDR_PUPD1);
}

void GPIOA_Pin_2(void){
//setting Pin as General purpose output
	GPIOA->MODER |= GPIO_MODER_MODE2_0;
	GPIOA->MODER &=~ GPIO_MODER_MODE2_1;
	
	//Type Register set to open push pull
	GPIOA->OTYPER &=~ (GPIO_OTYPER_OT_2);

//Speed of output high speed output
   GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;

//No Pull-up Pull-down Register
    GPIOA->PUPDR 	&=~ (GPIO_PUPDR_PUPD2);
}

void GPIOA_Pin_3(void){
//setting Pin as General purpose output
	GPIOA->MODER |= GPIO_MODER_MODE3_0;
	GPIOA->MODER &=~ GPIO_MODER_MODE3_1;
	
	//Type Register set to open push pull
	GPIOA->OTYPER &=~ (GPIO_OTYPER_OT_3);

//Speed of output high speed output
   GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3;

//No Pull-up Pull-down Register
    GPIOA->PUPDR 	&=~ (GPIO_PUPDR_PUPD3);
}

void GPIOA_Pin_4(void){
//setting Pin as General purpose output
	GPIOA->MODER |= GPIO_MODER_MODE4_0;
	GPIOA->MODER &=~ GPIO_MODER_MODE4_1;
	
	//Type Register set to open push pull
	GPIOA->OTYPER &=~ (GPIO_OTYPER_OT_4);

//Speed of output high speed output
   GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;

//No Pull-up Pull-down Register
    GPIOA->PUPDR 	&=~ (GPIO_PUPDR_PUPD4);
}

void GPIOA_Pin_5(void){
//setting Pin as General purpose output
	GPIOA->MODER |= GPIO_MODER_MODE5_0;
	GPIOA->MODER &=~ GPIO_MODER_MODE5_1;
	
	//Type Register set to open push pull
	GPIOA->OTYPER &=~ (GPIO_OTYPER_OT_5);

//Speed of output high speed output
   GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;

//No Pull-up Pull-down Register
    GPIOA->PUPDR 	&=~ (GPIO_PUPDR_PUPD5);
}

void GPIOA_Pin_6(void){
//setting Pin as General purpose output
	GPIOA->MODER |= GPIO_MODER_MODE6_0;
	GPIOA->MODER &=~ GPIO_MODER_MODE6_1;
	
	//Type Register set to open push pull
	GPIOA->OTYPER &=~ (GPIO_OTYPER_OT_6);

//Speed of output high speed output
   GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6;

//No Pull-up Pull-down Register
    GPIOA->PUPDR 	&=~ (GPIO_PUPDR_PUPD6);
}


void GPIOA_Pin_7(void){
//setting Pin as General purpose output
	GPIOA->MODER |= GPIO_MODER_MODE7_0;
	GPIOA->MODER &=~ GPIO_MODER_MODE7_1;
	
	//Type Register set to open push pull
	GPIOA->OTYPER &=~ (GPIO_OTYPER_OT_7);

//Speed of output high speed output
   GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR7;

//No Pull-up Pull-down Register
    GPIOA->PUPDR 	&=~ (GPIO_PUPDR_PUPD7);
}






void GPIOB_Pin_0(void){
//setting Pin as General purpose output
	GPIOB->MODER |= GPIO_MODER_MODE0_0;
	GPIOB->MODER &=~ GPIO_MODER_MODE0_1;
	
	//Type Register set to open push pull
	GPIOB->OTYPER &=~ (GPIO_OTYPER_OT_0);

//Speed of output high speed output
   GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;

//No Pull-up Pull-down Register
    GPIOB->PUPDR 	&=~ (GPIO_PUPDR_PUPD0);
}







void GPIOC_Pin_8(void){
//setting Pin as General purpose output
	GPIOC->MODER |= GPIO_MODER_MODE8_0;
	GPIOC->MODER &=~ (GPIO_MODER_MODE8_1);
	
	//Type Register set to open push pull
	GPIOC->OTYPER &=~ (GPIO_OTYPER_OT_8);

//Speed of output high speed output
   GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8;

//No Pull-up Pull-down Register
    GPIOC->PUPDR 	&=~ (GPIO_PUPDR_PUPD8);
}

void GPIOC_Pin_0(void){
//setting Pin as General purpose output
	GPIOC->MODER |= GPIO_MODER_MODE0_0;
	GPIOC->MODER &=~ (GPIO_MODER_MODE0_1);
	
	//Type Register set to open push pull
	GPIOC->OTYPER &=~ (GPIO_OTYPER_OT_0);

//Speed of output high speed output
   GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;

//No Pull-up Pull-down Register
    GPIOC->PUPDR 	&=~ (GPIO_PUPDR_PUPD0);
}

void GPIOC_Pin_1(void){
//setting Pin as General purpose output
	GPIOC->MODER |= GPIO_MODER_MODE1_0;
	GPIOC->MODER &=~ (GPIO_MODER_MODE1_1);
	
	//Type Register set to open push pull
	GPIOC->OTYPER |= (GPIO_OTYPER_OT_1);

//Speed of output high speed output
   GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR1;

//No Pull-up Pull-down Register
    GPIOC->PUPDR 	&=~ (GPIO_PUPDR_PUPD1);
}

void GPIOC_Pin_2(void){
//setting Pin as General purpose output
	GPIOC->MODER |= GPIO_MODER_MODE2_0;
	GPIOC->MODER &=~ (GPIO_MODER_MODE2_1);
	
	//Type Register set to open push pull
	GPIOC->OTYPER &=~ (GPIO_OTYPER_OT_2);

//Speed of output high speed output
   GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;

//No Pull-up Pull-down Register
    GPIOC->PUPDR 	&=~ (GPIO_PUPDR_PUPD2);
}

void GPIOC_Pin_3(void){
//setting Pin as General purpose output
	GPIOC->MODER |= GPIO_MODER_MODE3_0;
	GPIOC->MODER &=~ (GPIO_MODER_MODE3_1);
	
	//Type Register set to open push pull
	GPIOC->OTYPER &=~ (GPIO_OTYPER_OT_3);

//Speed of output high speed output
   GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3;

//No Pull-up Pull-down Register
    GPIOC->PUPDR 	&=~ (GPIO_PUPDR_PUPD3);
}

void GPIOC_Pin_4(void){
//setting Pin as General purpose output
	GPIOC->MODER |= GPIO_MODER_MODE4_0;
	GPIOC->MODER &=~ (GPIO_MODER_MODE4_1);
	
	//Type Register set to open push pull
	GPIOC->OTYPER &=~ (GPIO_OTYPER_OT_4);

//Speed of output high speed output
   GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;

//No Pull-up Pull-down Register
    GPIOC->PUPDR 	&=~ (GPIO_PUPDR_PUPD4);
}

void GPIOC_Pin_5(void){
//setting Pin as General purpose output
	GPIOC->MODER |= GPIO_MODER_MODE5_0;
	GPIOC->MODER &=~ (GPIO_MODER_MODE5_1);
	
	//Type Register set to open push pull
	GPIOC->OTYPER &=~ (GPIO_OTYPER_OT_5);

//Speed of output high speed output
   GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;

//No Pull-up Pull-down Register
    GPIOC->PUPDR 	&=~ (GPIO_PUPDR_PUPD5);
}

void GPIOC_Pin_13(void){//RW
	
	//setting Pin as General purpose output
	GPIOC->MODER |= GPIO_MODER_MODE13_0;
	GPIOC->MODER &=~ (GPIO_MODER_MODE13_1);
	
	//Type Register set to open push pull
	GPIOC->OTYPER &=~ (GPIO_OTYPER_OT_13);

//Speed of output high speed output
   GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR13;

//No Pull-up Pull-down Register
    GPIOC->PUPDR 	&=~ (GPIO_PUPDR_PUPD13);
	
	
}
void GPIOC_Pin_14(void){//EN

	//setting Pin as General purpose output
	GPIOC->MODER |= GPIO_MODER_MODE14_0;
	GPIOC->MODER &=~ (GPIO_MODER_MODE14_1);
	
	//Type Register set to open push pull
	GPIOC->OTYPER &=~ (GPIO_OTYPER_OT_14);

//Speed of output high speed output
   GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14;

//No Pull-up Pull-down Register
    GPIOC->PUPDR 	&=~ (GPIO_PUPDR_PUPD14);
}










//setting The Pin high
void Set_PinAO_high(void){
//using BSRR to turn on
	GPIOA->BSRR |= GPIO_BSRR_BS0;
}

void Set_PinA1_high(void){
//using BSRR to turn on
	GPIOA->BSRR |= GPIO_BSRR_BS1;
}

void Set_PinA2_high(void){
//using BSRR to turn on
	GPIOA->BSRR |= GPIO_BSRR_BS2;
}

void Set_PinA3_high(void){
//using BSRR to turn on
	GPIOA->BSRR |= GPIO_BSRR_BS3;
}

void Set_PinA4_high(void){
//using BSRR to turn on
	GPIOA->BSRR |= GPIO_BSRR_BS4;
}

void Set_PinA5_high(void){
//using BSRR to turn on
	GPIOA->BSRR |= GPIO_BSRR_BS5;
}

void Set_PinA6_high(void){
//using BSRR to turn on
	GPIOA->BSRR |= GPIO_BSRR_BS6;
}

void Set_PinA7_high(void){
//using BSRR to turn on
	GPIOA->BSRR |= GPIO_BSRR_BS7;
}

void Set_PinC8_high(void){
//using BSRR to turn on
	GPIOC->BSRR |= GPIO_BSRR_BS8;
}

void Set_PinC0_high(void){
//using BSRR to turn on
	GPIOC->BSRR |= GPIO_BSRR_BS0;
}

void Set_PinC1_high(void){
//using BSRR to turn on
	GPIOC->BSRR |= GPIO_BSRR_BS1;
}

void Set_PinC2_high(void){
//using BSRR to turn on
	GPIOC->BSRR |= GPIO_BSRR_BS2;
}

void Set_PinC3_high(void){
//using BSRR to turn on
	GPIOC->BSRR |= GPIO_BSRR_BS3;
}

void Set_PinC4_high(void){
//using BSRR to turn on
	GPIOC->BSRR |= GPIO_BSRR_BS4;
}

void Set_PinC5_high(void){
//using BSRR to turn on
	GPIOC->BSRR |= GPIO_BSRR_BS5;
}

void Set_PinC13_high(void){
//using BSRR to turn on
	GPIOC->BSRR |= GPIO_BSRR_BS13;
}

void Set_PinC14_high(void){
//using BSRR to turn on
	GPIOC->BSRR |= GPIO_BSRR_BS14;
}


//setting the Pins as low
void Set_PinA0_Low(void){
//Using BSRR to set low
	 GPIOA->BSRR |= GPIO_BSRR_BR0;
}

void Set_PinA1_Low(void){
//Using BSRR to set low
	 GPIOA->BSRR |= GPIO_BSRR_BR1;
}

void Set_PinA2_Low(void){
//Using BSRR to set low
	 GPIOA->BSRR |= GPIO_BSRR_BR2;
}

void Set_PinA3_Low(void){
//Using BSRR to set low
	 GPIOA->BSRR |= GPIO_BSRR_BR3;
}

void Set_PinA4_Low(void){
//Using BSRR to set low
	 GPIOA->BSRR |= GPIO_BSRR_BR4;
}

void Set_PinA5_Low(void){
//Using BSRR to set low
	 GPIOA->BSRR |= GPIO_BSRR_BR5;
}

void Set_PinA6_Low(void){
//Using BSRR to set low
	 GPIOA->BSRR |= GPIO_BSRR_BR6;
}

void Set_PinA7_Low(void){
//Using BSRR to set low
	 GPIOA->BSRR |= GPIO_BSRR_BR7;
}

void Set_PinC8_Low(void){
//Using BSRR to set low
	 GPIOC->BSRR |= GPIO_BSRR_BR8;
}

void Set_PinC0_Low(void){
//Using BSRR to set low
	 GPIOC->BSRR |= GPIO_BSRR_BR0;
}

void Set_PinC1_Low(void){
//Using BSRR to set low
	 GPIOC->BSRR |= GPIO_BSRR_BR1;
}

void Set_PinC2_Low(void){
//Using BSRR to set low
	 GPIOC->BSRR |= GPIO_BSRR_BR2;
}

void Set_PinC3_Low(void){
//Using BSRR to set low
	 GPIOC->BSRR |= GPIO_BSRR_BR3;
}

void Set_PinC4_Low(void){
//Using BSRR to set low
	 GPIOC->BSRR |= GPIO_BSRR_BR4;
}

void Set_PinC5_Low(void){
//Using BSRR to set low
	 GPIOC->BSRR |= GPIO_BSRR_BR5;
}

void Set_PinC13_Low(void){
//Using BSRR to set low
	 GPIOC->BSRR |= GPIO_BSRR_BR13;
}

void Set_PinC14_Low(void){
//Using BSRR to set low
	 GPIOC->BSRR |= GPIO_BSRR_BR14;
}

/*Settin an input with no PUPDR that means we have to use external debouncing*/
void GPIOC_set_input6(void){
//setting up the input
	//setting up the mode
	GPIOC->MODER &=~(GPIO_MODER_MODE6);//00 so it is an input 
	//setting up the PUPDR
	//since we have pulled down externally we dont need pull up or pull down
	GPIOC->PUPDR &=~(GPIO_PUPDR_PUPD6);
}
void GPIOA_set_input2(void){
//setting up the input
	//setting up the mode
	GPIOC->MODER &=~(GPIO_MODER_MODE2);//00 so it is an input 
	//setting up the PUPDR
	//since we have pulled down externally we dont need pull up or pull down
	GPIOC->PUPDR &=~(GPIO_PUPDR_PUPD2_0);
	GPIOC->PUPDR |=(GPIO_PUPDR_PUPD2_1);
}




/*Pollinr to check the IDR value */

int Check_Pin_6(void){
int i;	
i=(GPIOC->IDR & GPIO_IDR_ID6);
	return i;
}

