#include "stm32f4xx.h"                  // Device header
#include "UART.h"
#include "LCD8.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

//USART2_TX(12);//delete previous
//USART2_TX(11);//enter, go to the next line


void USART2_Init(void)
{
//enable clocks for UART and the GPIO
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
//configure PA1 and PA3 to alternate function
	GPIOA->MODER &=~ GPIO_MODER_MODER2_0;
	GPIOA->MODER |= GPIO_MODER_MODER2_1;//10 alternate	function
//Type Register set to open push pull
	GPIOA->OTYPER &=~ (GPIO_OTYPER_OT_2);
//Speed of output high speed output
   GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;
//No Pull-up Pull-down Register
    GPIOA->PUPDR 	&=~ (GPIO_PUPDR_PUPD2);
	

	GPIOA->MODER &=~ GPIO_MODER_MODER3_0;
	GPIOA->MODER |= GPIO_MODER_MODER3_1;//10 alternate function
//Type Register set to open push pull
	GPIOA->OTYPER &=~ (GPIO_OTYPER_OT_3);
//Speed of output high speed output
   GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3;
//No Pull-up Pull-down Register
    GPIOA->PUPDR 	&=~ (GPIO_PUPDR_PUPD3);
	
	
	
//selecting the alternate function
	GPIOA->AFR[0] |= (7<<8);//alternate function PA2 TX
  GPIOA->AFR[0] |= (7<<12);//alternate function PA3 RX

//setting the buad rate 9600 for 8 megahertz
	USART2->BRR |=(104<<4);
	USART2->BRR |=(1250);

	//enable UART, TX, RX
	USART2->CR1 |= USART_CR1_UE;//UART enable
	USART2->CR1 |= USART_CR1_TE;//TX enabled
	USART2->CR1 |= USART_CR1_RE;//RX enaled
	
	
	
}

unsigned char USART2_RX(void)
{
unsigned char buffer;
while(!(USART2->SR & USART_SR_RXNE))
{}//wait until data is received
	buffer = USART2->DR;
	return buffer;

}


void USART2_TX(unsigned char TXData)
{

USART2->DR = TXData;
	while(!(USART2->SR & USART_SR_TC)){}
}

void USART2_TX_String(char *str)
{

	unsigned char j=0;
	
	  USART2_TX(' ');
	  USART2_TX('%');
	
	while (str[j]!=0)		/* Send string till null */
	{
		USART2_TX(str[j]);
		j++;
		//wait_For_t(2);
	}

}

void USART1_Init(void)
{
//enable clocks for UART and the GPIO
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
//configure PA1 and PA3 to alternate function
	GPIOB->MODER &=~ GPIO_MODER_MODER6_0;
	GPIOB->MODER |= GPIO_MODER_MODER6_1;//10 alternate	function
//Type Register set to open push pull
	GPIOB->OTYPER &=~ (GPIO_OTYPER_OT_6);
//Speed of output high speed output
   GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6;
//No Pull-up Pull-down Register
    GPIOB->PUPDR 	&=~ (GPIO_PUPDR_PUPD6);
	

	GPIOB->MODER &=~ GPIO_MODER_MODER7_0;
	GPIOB->MODER |= GPIO_MODER_MODER7_1;//10 alternate function
//Type Register set to open push pull
	GPIOB->OTYPER &=~ (GPIO_OTYPER_OT_7);
//Speed of output high speed output
   GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR7;
//No Pull-up Pull-down Register
    GPIOB->PUPDR 	&=~ (GPIO_PUPDR_PUPD7);
	
	
	
//selecting the alternate function
	GPIOB->AFR[0] |= (7<<24);//alternate function PB6 TX
  GPIOB->AFR[0] |= (7<<28);//alternate function PB7 RX

//setting the buad rate to 9600     546.875   
	USART1->BRR |=(104<<4);
	USART1->BRR |=(1250);
	
	//enable UART, TX, RX
	USART1->CR1 |= USART_CR1_UE;//UART enable
	USART1->CR1 |= USART_CR1_TE;//TX enabled
	USART1->CR1 |= USART_CR1_RE;//RX enaled
	
}



void USART1_TX(unsigned char TXData)
{

        USART1->DR = TXData;
	while(!(USART1->SR & USART_SR_TC)){}
}

unsigned char USART1_RX(void)
{
unsigned char buffer;
while(!(USART1->SR & USART_SR_RXNE))
{}//wait until data is received
	buffer = USART1->DR;
	return buffer;

}

void USART1_TX_String(char *str)
{

	unsigned char j=0;
	
	  USART1_TX(' ');
	  wait_For_t(2);
		USART1_TX(' ');
	  wait_For_t(2);
	  USART1_TX('%');
	  wait_For_t(2);
	while (str[j]!=0)		/* Send string till null */
	{
		USART1_TX(str[j]);
		j++;
		wait_For_t(2);
	}

}

void USART2_TX_Int(int value)
{

	char l[10];
	sprintf(l, "%d", value);
	USART2_TX_String(l);

}
