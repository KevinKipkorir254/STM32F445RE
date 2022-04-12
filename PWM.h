#ifndef PWM_H_
#define PWM_H_
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void Timer4_Clock_Init(void);
void Timer4_Clock_Display(void);
void PWM4_Init(void);
void input_capture_4(void);
uint32_t Capture_high(void);
void PWM_Capture(void);
void PWM4_Channel_1(void);

#endif

