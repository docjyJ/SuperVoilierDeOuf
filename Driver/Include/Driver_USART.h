#ifndef Driver_USART_h_
#define Driver_USART_h_

#include "stm32f10x.h"

void MyUSART_Init(USART_TypeDef *USART, uint16_t baudRate);

void MyUSART_ActiveIT(USART_TypeDef *USART, uint8_t priority, void (*IT_fun)(uint16_t));

void MyUSART_Send(USART_TypeDef *USART, char data);

#endif
