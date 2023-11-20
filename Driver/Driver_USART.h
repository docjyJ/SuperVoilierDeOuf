#ifndef MYUSART_H
#define MYUSART_H
#include "stm32f10x.h"

void MyUsart_Base_Init (USART_TypeDef * USART, uint16_t BaudRate, void (*IT_fun) (void));


#define MyUsart_Send(USART,data) USART2->DR |= data
#define MyUsart_Receive(USART) USART->DR


#endif
