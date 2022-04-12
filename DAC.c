#include "stm32f4xx.h"  // Device header
#include "DAC.h"
#include "LCD8.h"
//Enable DAC RCC
// In order to avoid parasitic consumption, the PA4 or PA5 pin should first be configured to analog (AIN).
//Each DAC channel can be powered on by setting its corresponding ENx bit in the DAC_CR register.
//delay for T_wake up
//Each DAC channel output buffer can be enabled and disabled using the corresponding BOFFx bit in the DAC_CR register.
// 12-bit right alignment: the software has to load data into the DAC_DHR12Rx [11:0] bits (stored into the DHRx[11:0] bits)
//DACoutput VREF= DOR/4096
//The TSELx[2:0] control bits determine which out of 8 possible events will trigger conversion as shown in Table 94.
// TSELx[2:0] bit cannot be changed when the ENx bit is set.

                                      /*Noise Generation*/
//DAC noise generation is selected by setting WAVEx[1:0] to “01”.
//It is possible to reset LFSR wave generation by resetting the WAVEx[1:0] bits

            /*Triangle-wave generation*/
//DAC triangle-wave generation is selected by setting WAVEx[1:0] to “10”.
// The amplitude is configured through the MAMPx[3:0] bits in the DAC_CR register.
	
	void DAC1_Sine(void)
	{
	
RCC->APB1ENR |= RCC_APB1ENR_DACEN;//enable DAC
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;//enable GPIOA
		
//set to analog PA4 to analog pin
GPIOA->MODER |= GPIO_MODER_MODE4_1;
GPIOA->MODER |= GPIO_MODER_MODE4_0;//analog mode

//set to high speed
GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;


GPIOA->PUPDR &=~(GPIO_PUPDR_PUPD4_0);
GPIOA->PUPDR &=~(GPIO_PUPDR_PUPD4_1);//00 to set analog, the rest are dont care		
		
GPIOA->BSRR |= GPIO_BSRR_BS4;
	
DAC->CR |=DAC_CR_TEN1 ;
	
DAC->CR &=~ DAC_CR_MAMP1_0;
DAC->CR |= DAC_CR_MAMP1_1;
DAC->CR &=~ DAC_CR_MAMP1_2;
DAC->CR |= DAC_CR_MAMP1_3;
		
DAC->CR &=~ DAC_CR_BOFF1;//enable buffer
DAC->DHR12R1 |= 3000;//write data in the 12 bit register
DAC->CR |= DAC_CR_TSEL1_0 | DAC_CR_TSEL1_1 | DAC_CR_TSEL1_2;//111 software trigger

DAC->CR |= DAC_CR_WAVE1_0;
DAC->CR &=~ DAC_CR_WAVE1_1;//01 wave generator
		
//setting the DAC
DAC->CR |=DAC_CR_EN1 ;
wait_For_t(20);
	
DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;
		
	
	}
	
	void Triangular_Wave_Generatio(void)
	{
	//DAC triangle-wave generation is selected by setting WAVEx[1:0] to “10”.
	//The amplitude is configured through the MAMPx[3:0] bits in the DAC_CR register.
	//The triangle counter is incremented as long as it is less than the maximum amplitude defined by the MAMPx[3:0] bits.
	
	
	
	}
	
						
						