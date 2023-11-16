#ifndef MYUSART_H
#define MYUSART_H
#include "stm32f10x.h"

void MyUsart_Base_Init (USART_TypeDef * USART, uint16_t BAUDRATE);
void MyUsart_Send(USART_TypeDef * USART, uint32_t ARG);
uint32_t MyUsart_Receive(USART_TypeDef * USART);

#endif
