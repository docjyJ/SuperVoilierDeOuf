#include "stm32f10x.h"
#include "Driver_USART.h"

void (*USART1_IT_fun) (void);
void USART1_IRQHandler(){
	if (*USART1_IT_fun!= 0){
		USART1_IT_fun();
	}
}

void (*USART2_IT_fun) (void);
void USART2_IRQHandler(){
	if (*USART2_IT_fun!= 0){
		USART2_IT_fun();
	}
}
	
void (*USART3_IT_fun) (void);
void USART3_IRQHandler(){
	if (*USART3_IT_fun!= 0){
		USART3_IT_fun();
	}
}



void MyUsart_Base_Init (USART_TypeDef * USART, uint16_t BaudRate, void (*IT_fun) (void)) {
int Fpclk = 36000000;
if (USART == USART1){
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	Fpclk = 72000000;
	USART1_IT_fun = IT_fun;
}
else if (USART == USART2){
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	USART2_IT_fun = IT_fun;
}
else if (USART == USART3){
	RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
	USART3_IT_fun = IT_fun;
}
else return;

USART->CR1 |= USART_CR1_UE;	//enable
USART->CR1 |= USART_CR1_M;		//word length
USART->CR2 |= USART_CR2_STOP; //stop bit
USART->BRR |= Fpclk/BaudRate;  //baud rate here fpclk/(baudrate/1000)
USART->CR1 |= USART_CR1_TE;
}


