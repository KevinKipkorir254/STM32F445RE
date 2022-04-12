#ifndef UART_H_
#define UART_H_

void USART2_Init(void);
void USART1_Init(void);
unsigned char USART2_RX(void);
void USART2_TX(unsigned char);
void USART1_TX(unsigned char TXData);
void USART2_TX_String(char *str);
unsigned char USART1_RX(void);
void USART1_TX_String(char *str);
void USART2_TX_Int(int value);

#endif
