#include "stm32f4xx.h"                  // Device header
#include "stm32f446xx.h"
#include "GPIO.h"
#include "ADC.h"
#include "LCD8.h"
#include "PWM.h"
#include "UART.h"
#include "DAC.h"
#include "DPOT.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void DPOT_init(uint32_t upper_value, uint32_t lower_value)
	
{

	
  ADC1_IN1_INIT();
	USART1_Init();
	USART2_Init();
	CLOCK_INIT_PORTA();
	GPIOA_Pin_0();
	GPIOA_Pin_1();
	GPIOA_Pin_5();
	USART2_TX_String("STRATING DPOT SETUP");
	
	uint32_t p;
	char k[5];
	
	p = ADC1_IN1_Read();
	sprintf(k, "S%d", p);
	USART1_TX_String(k);
	USART2_TX_String(k);
	Set_PinA5_Low();
	
	//as long as p<120 or p>130
while((p<lower_value)||(p>upper_value)){	
	//while p<125 set U/D to 1 and increment
	while(p<lower_value)
	{
		
	p = ADC1_IN1_Read();//read value
	sprintf(k, "A%d", p);//phrase value
	USART2_TX_String(k);//send value 
	USART1_TX_String(k);
		if((p>lower_value)&&(p<upper_value)){
		break;
		}
		
	Set_PinA1_high();//U/D increment selector for 
  Set_PinAO_high();
		wait_For_t(5);
	Set_PinA0_Low();
		wait_For_t(1);
		
	}
	
	if((p>lower_value)&&(p<upper_value)){
		break;
		}
	
	//when greater than 2950 set u/D as 0 and decrement
	while(p>upper_value)
	{
		
		p = ADC1_IN1_Read();
	sprintf(k, "B%d", p);
	USART2_TX_String(k);
	USART1_TX_String(k);	
		if((p>lower_value)&&(p<upper_value)){
		break;
		}
	Set_PinA1_Low();//U/D increment selector to down counter
  Set_PinAO_high();
		wait_For_t(2);
	Set_PinA0_Low();
		wait_For_t(1);
		
		
	}
	
	if((p>lower_value)&&(p<upper_value)){
		break;
		}
	
}
Set_PinA5_high();
USART2_TX_String("DPOT SETTUP COMPLETE");

}

