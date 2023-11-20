#include "stm32f10x.h"
#include "Driver_USART.h"

void (*USART1_IT_fun) (char);
void USART1_IRQHandler(){
	USART1_IT_fun(USART1->DR);
}

void (*USART2_IT_fun) (char);
void USART2_IRQHandler(){
	USART2_IT_fun(USART2->DR);
}
	
void (*USART3_IT_fun) (char);
void USART3_IRQHandler(){
	USART3_IT_fun(USART3->DR);
}

void MyUsart_Send(USART_TypeDef * USART, char data) {
	while(!(USART->SR & USART_SR_TC));
	USART->DR |= data;
}



void MyUsart_Base_Init (USART_TypeDef * USART, uint16_t BaudRate) {
	int Fpclk = 36000000;
	
	if (USART == USART1){
		RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
		Fpclk = 72000000;
	}
	else if (USART == USART2) RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	else if (USART == USART3) RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
	else return;
	
	USART->CR1 &= ~USART_CR1_M;		//word length
	USART->CR1 |= USART_CR1_UE;	//enable
	USART->CR2 &= ~USART_CR2_STOP; //stop bit
	USART->BRR |= Fpclk/BaudRate;  //baud rate here fpclk/(baudrate)
	USART->CR1 |= USART_CR1_TE;
	USART->SR |= USART_SR_TC;
}

void MyUsart_ActiveIT(USART_TypeDef * USART, uint32_t  priority, void (*IT_fun) (char)){
	IRQn_Type USART_IRQn;
	     if (USART == USART1) { USART_IRQn = USART1_IRQn; USART1_IT_fun = IT_fun; }
	else if (USART == USART2) { USART_IRQn = USART2_IRQn; USART2_IT_fun = IT_fun; }
	else if (USART == USART3) { USART_IRQn = USART3_IRQn; USART3_IT_fun = IT_fun; }
	else return;
	
	USART->CR1 |= USART_CR1_RXNEIE;
	USART->CR1 |= USART_CR1_RE;
	NVIC_EnableIRQ(USART_IRQn);
	NVIC_SetPriority(USART_IRQn, priority);
}
