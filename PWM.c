#include "stm32f4xx.h"                  // Device header
#include "GPIO.h"
#include "ADC.h"
#include "LCD8.h"
#include "PWM.h"
#include "UART.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

//timers
//counts up to ARR then clears



void Timer4_Clock_Init(void)
{
	
//Enable Timer 4 clock
RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;

	
//set timer prescaler
	TIM4->PSC = 0;
	
//set ARR value wich will be the maximum value
	TIM4->ARR = 6000;

	
//Enable timer 4
	//change direction using DIR
	//set phase correct using SMs
	TIM4->CR1 |= TIM_CR1_CEN;
	
}

void Timer4_Clock_Display(void)
{	
	USART2_TX_Int( TIM4->CNT);
	USART2_TX_Int(0x0A);//Go to the next line

}

void PWM4_Init(void)
{
	//write valuse to set or reset pin on Compture and compare register 4
	//frequency is deermoned by the value of the ARR
	
	//enable clocks for GPIO, alternate function and Timer 4
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;//because pinB9 is output
	
	
	//set output pin
	GPIOB->MODER |= GPIO_MODER_MODE9_1;//10 for alternate function
	GPIOB->MODER  &=~   GPIO_MODER_MODE9_0;
	
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;//11 FAST SPEED
	
	GPIOB->OTYPER &=~ (GPIO_OTYPER_OT_9);//OUTPUT PUSH PULL
  
	GPIOB->PUPDR &=~(GPIO_PUPDR_PUPD9);//00 no pull up or pull down
	//set alternate function
  GPIOB->AFR[1] |=(2<<4);

	

	//PWM Frequency = fclk/psc/ARR
	//PWM Duty = CCR4/ARR
	
	TIM4->CCER |= TIM_CCER_CC4E;//Capture/Compare 4 output enable.
	TIM4->CR1 |= TIM_CR1_ARPE;// Auto-reload preload enable
	TIM4->CCMR2 |=  TIM_CCMR2_OC4M_1;
	TIM4->CCMR2 |=  TIM_CCMR2_OC4M_2;//In PWM mode 1
	TIM4->CCMR2 |=  TIM_CCMR2_OC4PE;// Output compare 4 preload enable




//set timer prescaler
	TIM4->PSC = 64;
	
//set ARR value wich will be the maximum value
	TIM4->ARR = 1000;
	
	//value for compare
	TIM4->CCR4 |= 800;

		TIM4->CR1 &=~ TIM_CR1_ARPE;// Auto-reload preload enable
//Enable timer 4

   TIM4->EGR |= TIM_EGR_UG;// Update generation
	//change direction using DIR
	//set phase correct using SMs
	TIM4->CR1 |= TIM_CR1_CEN;
	
	 
	
}


void input_capture_4(void)
{
 	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;//because pinB9 is output
	
	
	//set output pin
	GPIOB->MODER |= GPIO_MODER_MODE6_1;//10 for alternate function
	GPIOB->MODER &=~GPIO_MODER_MODE6_0;
	
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9;//high speed output
	
	GPIOB->OTYPER &=~ (GPIO_OTYPER_OT_6);//OUTPUT PUSH PULL 
  
	GPIOB->PUPDR &=~(GPIO_PUPDR_PUPD6);//00 no pull up or pull down
	//set alternate function
  GPIOB->AFR[0] |=(2<<24);
	
		TIM4->CR1 |= TIM_CR1_ARPE;// Auto-reload preload enable
	TIM4->CCMR1 |= TIM_CCMR1_CC1S_0;
	TIM4->CCMR1 &=~ TIM_CCMR1_CC1S_1;//TI1
	
	TIM4->CCMR1 |= TIM_CCMR1_IC1F_0;
	TIM4->CCMR1 |= TIM_CCMR1_IC1F_1;
	TIM4->CCMR1 &=~ TIM_CCMR1_IC1F_2;
	TIM4->CCMR1 &=~ TIM_CCMR1_IC1F_3;
	
	TIM4->CCER  &=~ TIM_CCER_CC1NP;
	TIM14->CCER &=~ TIM_CCER_CC1P;//rising edge
	
	TIM4->CCMR1 &=~ TIM_CCMR1_IC1PSC_0;
	TIM4->CCMR1 &=~ TIM_CCMR1_IC1PSC_1;//every valide rise
	
	TIM4->CCER |= TIM_CCER_CC1E;//capture enable
	
	
	//set timer prescaler
	TIM4->PSC = 72;
	
//set ARR value wich will be the maximum value
	TIM4->ARR = 1000;
	
	//value for compare
	TIM4->CCR1 |= 100;

	TIM4->CR1 &=~ TIM_CR1_ARPE;// Auto-reload preload enable
//Enable timer 4

   TIM4->EGR |= TIM_EGR_UG;// Update generation
	//change direction using DIR
	//set phase correct using SMs
	TIM4->CR1 |= TIM_CR1_CEN;

}


uint32_t Capture_high(void)
{
	uint32_t p;
 while(!(TIM4->SR & TIM_SR_CC1IF))//wait for capture
 {
 }

 p = TIM4->CCR1;
 return p;
 
}

void PWM_Capture(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;//because pinB6
	
	GPIOB->MODER |= GPIO_MODER_MODE6_1;//10 for alternate function
	GPIOB->MODER &=~GPIO_MODER_MODE6_0;
	
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6;//high speed output
	
	GPIOB->OTYPER &=~ (GPIO_OTYPER_OT_6);//OUTPUT PUSH PULL 
  
	GPIOB->PUPDR &=~(GPIO_PUPDR_PUPD6);//00 no pull up or pull down
	//set alternate function
  GPIOB->AFR[0] |=(2<<24);
	
		GPIOB->MODER |= GPIO_MODER_MODE7_1;//10 for alternate function
	GPIOB->MODER &=~GPIO_MODER_MODE7_0;
	
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR7;//high speed output
	
	GPIOB->OTYPER &=~ (GPIO_OTYPER_OT_7);//OUTPUT PUSH PULL 
  
	GPIOB->PUPDR &=~(GPIO_PUPDR_PUPD7);//00 no pull up or pull down
	//set alternate function
  GPIOB->AFR[0] |=(2<<28);
	
	//clock and GPIO initialiations
	TIM4->CCMR1 |= TIM_CCMR1_CC1S_0;
	TIM4->CCMR1 &=~ TIM_CCMR1_CC1S_1;//TI1	
	
  TIM4->CCER &=~ TIM_CCER_CC1P;
	TIM4->CCER &=~ TIM_CCER_CC1NP;//rising edge
	
	TIM4->CCMR1 |= TIM_CCMR1_CC2S_0;
	TIM4->CCMR1 &=~ TIM_CCMR1_CC2S_1;//TI1	for CCR2

	TIM4->CCER |= TIM_CCER_CC2P;
	TIM4->CCER &=~ TIM_CCER_CC2NP;//rising edge and falling edge
	
	TIM4->SMCR &=~ TIM_SMCR_TS_0;	
	TIM4->SMCR |= TIM_SMCR_TS_1;	
	TIM4->SMCR |= TIM_SMCR_TS_2;//110 filtered timer iput 2
	
	TIM4->SMCR &=~ TIM_SMCR_SMS_0;	
	TIM4->SMCR &=~ TIM_SMCR_SMS_1;	
	TIM4->SMCR |= TIM_SMCR_SMS_2;//100 reset cunter on rising edge
	
	TIM4->CCER |=(TIM_CCER_CC1E)|(TIM_CCER_CC2E);
	
//set timer prescaler
	TIM4->PSC = 72;
	
//set ARR value wich will be the maximum value
	TIM4->ARR = 1000;

		TIM4->CR1 &=~ TIM_CR1_ARPE;// Auto-reload preload enable
//Enable timer 4

   TIM4->EGR |= TIM_EGR_UG;// Update generation
	//change direction using DIR
	//set phase correct using SMs
	TIM4->CR1 |= TIM_CR1_CEN;


}


void PWM4_Channel_1(void)
{
	//Enable Timer 4 clock
RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;


GPIOB->MODER &=~ GPIO_MODER_MODE6_0;	
GPIOB->MODER |= GPIO_MODER_MODE6_1;	//10 for alternate function
	
GPIOB->OTYPER &=~ GPIO_OTYPER_OT6;//push-pull
	
GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6;//11 high speed
	
GPIOB->PUPDR &=~ GPIO_PUPDR_PUPDR6;//no pull-up or pull-down 
	
GPIOB->AFR[0] |= (2<<24);//select alternate function
	
	
	
//timer 4 channel 1
TIM4->CCMR1 &=~ TIM_CCMR1_OC1M_0;
TIM4->CCMR1 |= TIM_CCMR1_OC1M_1;
TIM4->CCMR1 |= TIM_CCMR1_OC1M_2;//select PWM 1 for channel 110

TIM4->CCMR1 |= TIM_CCMR1_OC1PE;
TIM4->CR1   |= TIM_CR1_ARPE;
TIM4->EGR |= TIM_EGR_UG;
TIM4->CCER &=~ TIM_CCER_CC1P;//set as active low
TIM4->CCER |= TIM_CCER_CC1E;
	
//set timer prescaler
	TIM4->PSC = 72;
	
//set ARR value wich will be the maximum value
	TIM4->ARR = 1000;
	
	//value for compare
	TIM4->CCR1 |= 500;

		TIM4->CR1 &=~ TIM_CR1_ARPE;// Auto-reload preload enable
//Enable timer 4

   TIM4->EGR |= TIM_EGR_UG;// Update generation
	//change direction using DIR
	//set phase correct using SMs
	TIM4->CR1 |= TIM_CR1_CEN;
}


