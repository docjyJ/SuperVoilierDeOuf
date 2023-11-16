#include "stm32f10x.h"
#include "Driver_TIMER.h"




void MyTimer_Base_Init (TIM_TypeDef * TIM, uint16_t ARR, uint16_t PSC){
	     if (TIM == TIM1) RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	else if (TIM == TIM2) RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	else if (TIM == TIM3) RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	else if (TIM == TIM4) RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	else return;
	
	TIM->ARR = ARR;
	TIM->PSC = PSC;
}


void (*TIM1_UP_IT_fun) (void);
void TIM1_UP_IRQHandler(){
	TIM1->SR &= ~TIM_SR_UIF;
	(*TIM1_UP_IT_fun)();
}


void (*TIM2_IT_fun) (void);
void TIM2_IRQHandler(){
	TIM2->SR &= ~TIM_SR_UIF;
	(*TIM2_IT_fun)();
}

void (*TIM3_IT_fun) (void);
void TIM3_IRQHandler(){
	TIM3->SR &= ~TIM_SR_UIF;
	(*TIM3_IT_fun)();
}

void (*TIM4_IT_fun) (void);
void TIM4_IRQHandler(){
	TIM4->SR &= ~TIM_SR_UIF;
	(*TIM4_IT_fun)();
}



void MyTimer_ActiveIT(TIM_TypeDef * TIM , uint32_t  priority, void (*IT_fun) (void)){
	IRQn_Type TIM_IRQn;
	     if (TIM == TIM1) { TIM_IRQn = TIM1_UP_IRQn; TIM1_UP_IT_fun = IT_fun; }
	else if (TIM == TIM2) { TIM_IRQn = TIM2_IRQn; TIM2_IT_fun = IT_fun; }
	else if (TIM == TIM3) { TIM_IRQn = TIM3_IRQn; TIM3_IT_fun = IT_fun; }
	else if (TIM == TIM4) { TIM_IRQn = TIM4_IRQn; TIM4_IT_fun = IT_fun; }
	else return;
	
	TIM->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM_IRQn);
	NVIC_SetPriority(TIM_IRQn, priority);
}


void MyTimer_PWM(TIM_TypeDef * TIM , uint32_t TIM_Channel){
	switch (TIM_Channel) {
		case 1:
			TIM->CCER |= TIM_CCER_CC1E;
		  TIM->CCMR1 &= ~(TIM_CCMR1_CC1S | TIM_CCMR1_OC1M);
		  TIM->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;
		  if (TIM == TIM1) TIM->BDTR = TIM_BDTR_MOE;
		  break;
		case 2:
			TIM->CCER |= TIM_CCER_CC2E;
		  TIM->CCMR1 &= ~(TIM_CCMR1_CC2S | TIM_CCMR1_OC2M);
		  TIM->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
		  if (TIM == TIM1) TIM->BDTR = TIM_BDTR_MOE;
		  break;
		case 3:
			TIM->CCER |= TIM_CCER_CC3E;
		  TIM->CCMR2 &= ~(TIM_CCMR2_CC3S | TIM_CCMR2_OC3M);
		  TIM->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;
		  if (TIM == TIM1) TIM->BDTR = TIM_BDTR_MOE;
		  break;
		case 4:
			TIM->CCER |= TIM_CCER_CC4E;
		  TIM->CCMR2 &= ~(TIM_CCMR2_CC4S | TIM_CCMR2_OC4M);
		  TIM->CCMR2 |= TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4M_2;
		  if (TIM == TIM1) TIM->BDTR = TIM_BDTR_MOE;
		  break;
	}
}

void MyTimer_PWM_Cycle(TIM_TypeDef * TIM , uint32_t TIM_Channel, uint16_t CCR){
	     if (TIM_Channel == 1) TIM->CCR1 = CCR;
	else if (TIM_Channel == 2) TIM->CCR2 = CCR;
	else if (TIM_Channel == 3) TIM->CCR3 = CCR; 
	else if (TIM_Channel == 4) TIM->CCR4 = CCR;
}

void MyTimer_Incremental(TIM_TypeDef * TIM){
	TIM->ARR = 359;
	TIM->CCMR1 &= ~(TIM_CCMR1_CC1S) & ~(TIM_CCMR1_CC2S);
	TIM->CCMR1 |= TIM_CCMR1_CC1S | TIM_CCMR1_CC2S;
	TIM->CCMR1 |= TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC2M_0;
		
		
	TIM->CCER &= ~(TIM_CCER_CC1E) & ~(TIM_CCER_CC2E);
	TIM->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E;
		
	TIM->SMCR &= ~(TIM_SMCR_SMS);
	TIM->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;
		
	TIM->CR1 |= TIM_CR1_CEN;
}

