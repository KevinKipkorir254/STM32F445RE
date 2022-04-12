#ifndef ADC_H_
#define ADC_H_
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


void ADC1_IN1_INIT(void);
uint32_t ADC1_IN1_Read(void);
void ADC1_PC4_INIT(void);
void ADC1_Scan2(void);

#endif

