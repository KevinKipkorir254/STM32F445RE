#ifndef GPIO_H_
#define GPIO_H_

//initializint the clocks
void CLOCK_INIT_PORTA (void);
void CLOCK_INIT_PORTB (void);
void CLOCK_INIT_PORTC (void);
void CLOCK_INIT_PORTD (void);
void CLOCK_INIT_PORTE (void);
void CLOCK_INIT_PORTF (void);
void CLOCK_INIT_PORTG (void);
void CLOCK_INIT_PORTH (void);


//initializing the PORTS
void GPIOA_Pin_0(void);
void GPIOA_Pin_1(void);
void GPIOA_Pin_2(void);
void GPIOA_Pin_3(void);
void GPIOA_Pin_4(void);
void GPIOA_Pin_5(void);
void GPIOA_Pin_6(void);

void GPIOB_Pin_0(void);

void GPIOC_Pin_0(void);
void GPIOC_Pin_1(void);
void GPIOC_Pin_2(void);
void GPIOC_Pin_3(void);
void GPIOC_Pin_4(void);
void GPIOC_Pin_5(void);
void GPIOA_Pin_7(void);
void GPIOC_Pin_8(void);
void GPIOC_Pin_13(void);//RW
void GPIOC_Pin_14(void);//EN

//settint the pin to high
void Set_PinAO_high(void);
void Set_PinA1_high(void);
void Set_PinA2_high(void);
void Set_PinA3_high(void);
void Set_PinA4_high(void);
void Set_PinA5_high(void);
void Set_PinA6_high(void);
void Set_PinA7_high(void);

void Set_PinC0_high(void);
void Set_PinC1_high(void);
void Set_PinC2_high(void);
void Set_PinC3_high(void);
void Set_PinC4_high(void);
void Set_PinC5_high(void);
void Set_PinC8_high(void);
void Set_PinC13_high(void);
void Set_PinC14_high(void);

//setting the pin to low
void Set_PinA0_Low(void);
void Set_PinA1_Low(void);
void Set_PinA2_Low(void);
void Set_PinA3_Low(void);
void Set_PinA4_Low(void);
void Set_PinA5_Low(void);
void Set_PinA6_Low(void);
void Set_PinA7_Low(void);

void Set_PinC0_Low(void);
void Set_PinC1_Low(void);
void Set_PinC2_Low(void);
void Set_PinC3_Low(void);
void Set_PinC4_Low(void);
void Set_PinC5_Low(void);
void Set_PinC8_Low(void);
void Set_PinC13_Low(void);
void Set_PinC14_Low(void);





/*Settin an input with no PUPDR that means we have to use external resistors*/
void GPIOC_set_input6(void);


//setting and input with PUPDR 
void GPIOA_set_input2(void);



/*Checkin the value of the pin*/
int Check_Pin_6(void);




#endif

