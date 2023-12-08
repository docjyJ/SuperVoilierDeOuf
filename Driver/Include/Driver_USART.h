#ifndef MYUSART_H
#define MYUSART_H
#include "stm32f10x.h"

void MyUsart_Base_Init (USART_TypeDef * USART, uint16_t BaudRate);
void MyUsart_ActiveIT(USART_TypeDef * USART, uint32_t  priority, void (*IT_fun) (char));
void MyUsart_Send(USART_TypeDef * USART, char data);

#endif
