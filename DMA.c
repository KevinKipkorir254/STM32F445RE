#include "stm32f4xx.h"                  // Device header
#include "DMA.h"

volatile int Ticks;
void delay_ms_init(void)
{
SysTick_Config(SystemCoreClock/1000);//does some math that gives me an ms delay

}

void delay_ms(int ms)
{
	
	Ticks=0;
while(Ticks<ms);

}

void SysTick_Handler(void)
{

Ticks++;
}
