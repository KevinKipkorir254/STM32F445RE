#include "stm32f4xx.h"                  // Device header
#include "GPIO.h"
#include "LCD8.h"
#include "ADC.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

	//using the temperature sensor
	//calbration(ensure ADC is of)
	/*do the calibration*/
//working with Potentiometer
//help by Eddie Amaya
void ADC1_IN1_INIT(void)
	{
//set clock to 14MHz prscaler
		ADC->CCR |= ADC_CCR_ADCPRE_0;
		ADC->CCR |= ADC_CCR_ADCPRE_1;
		
		//RCC clock for ADC and for alternate function
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
		
		//Enable GPIO port
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

		//configure input push pull
		  //setting up the input
	    /*/setting up the mode*/
		  GPIOB->MODER |= (GPIO_MODER_MODE1_1);
	    GPIOB->MODER |= (GPIO_MODER_MODE1_0);//11 so to set analog
	  
  		 //setting up the PUPDR
	     //since we have pulled down push pull alternate function 
    	GPIOB->PUPDR &=~(GPIO_PUPDR_PUPD1_0);
    	GPIOB->PUPDR &=~(GPIO_PUPDR_PUPD1_1);//00 to set analog, the rest are dont care
		
       //Enable end of conversion interrupt
	      ADC1->CR1 |= ADC_CR1_EOCIE;
				
				//ADC Resolution 8 bit
				ADC1->CR1 &=~  ADC_CR1_RES_0;
				ADC1->CR1 |=  ADC_CR1_RES_1;
	 
      	//Set sampling rate choose maximum for the highst precision
	      ADC1->SMPR2 |= ADC_SMPR2_SMP9_0;
      	ADC1->SMPR2 |= ADC_SMPR2_SMP9_1;
      	ADC1->SMPR2 |= ADC_SMPR2_SMP9_2;
	
		    //set channels in sequence reg
		    ADC1->SQR3 |=(9<<0);
		
		    //Enable ADC that is ADON
		    //Enable continuous mode
		    ADC1->CR2 |= (ADC_CR2_ADON)|(ADC_CR2_CONT);
		
		    //delai for 2ms
		    wait_For_t(20);
		
		    //turn on ADC adon for the second time
		    //delay 2 ms
		    ADC1->CR2 |= ADC_CR2_ADON;
		    wait_For_t(20);
		
		    //Run clibration
		    //delay to allow the finish
		     wait_For_t(2);
		
		
		
	}
	
 uint32_t ADC1_IN1_Read(void)
{
 volatile uint32_t p;
ADC1->CR2 |= ADC_CR2_SWSTART;
		while(!(ADC1->SR & ADC_SR_EOC))//wait until conversion complete while not equal to one wait
		{}
		p = ADC1->DR;
	
	return p;
}
	
	
void ADC1_PC4_INIT(void)
{
	
	//set clock to 14MHz prscaler
		ADC->CCR |= ADC_CCR_ADCPRE_0;
		ADC->CCR |= ADC_CCR_ADCPRE_1;
		
		//RCC clock for ADC and for alternate function
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
		
		//Enable GPIO port
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

		//configure input push pull
		  //setting up the input
	    /*/setting up the mode*/
		  GPIOC->MODER |= (GPIO_MODER_MODE4_1);
	    GPIOC->MODER |= (GPIO_MODER_MODE4_0);//11 so to set analog
	  
  		 //setting up the PUPDR
	     //since we have pulled down push pull alternate function 
    	GPIOB->PUPDR &=~(GPIO_PUPDR_PUPD4_0);
    	GPIOB->PUPDR &=~(GPIO_PUPDR_PUPD4_1);//00 to set analog, the rest are dont care
		
       //Enable end of conversion interrupt
	      ADC1->CR1 |= ADC_CR1_EOCIE;
				
				//ADC Resolution 8 bit
				ADC1->CR1 &=~  ADC_CR1_RES_0;
				ADC1->CR1 &=~  ADC_CR1_RES_1;
	 
      	//Set sampling rate choose maximum for the highst precision
	      ADC1->SMPR1 |= ADC_SMPR1_SMP14_0;
      	ADC1->SMPR1 |= ADC_SMPR1_SMP14_1;
      	ADC1->SMPR1 |= ADC_SMPR1_SMP14_2;
				
	
		    //set channels in sequence reg
		    ADC1->SQR3 |=(14<<0);
		
		    //Enable ADC that is ADON
		    //Enable continuous mode
		    ADC1->CR2 |= (ADC_CR2_ADON)|(ADC_CR2_CONT);
		
		    //delai for 2ms
		    wait_For_t(20);
		
		    //turn on ADC adon for the second time
		    //delay 2 ms
		    ADC1->CR2 |= ADC_CR2_ADON;
		    wait_For_t(20);
		
		    //Run clibration
		    //delay to allow the finish
		     wait_For_t(2);

}




