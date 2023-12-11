#ifndef MYTIMER_H
#define MYTIMER_H
#include "stm32f10x.h"

void MyTimer_Base_Init (TIM_TypeDef * TIM, uint16_t ARR, uint16_t PSC);
void MyTimer_ActiveIT(TIM_TypeDef * TIM , uint32_t priority, void (*IT_fun) (void));

#define MyTimer_Base_Start(TIM) TIM->CR1 |= TIM_CR1_CEN
#define MyTimer_Base_Stop(TIM) TIM->CR1 &= ~TIM_CR1_CEN

void MyTimer_PWM(TIM_TypeDef * TIM , uint32_t TIM_Channel);
void MyTimer_PWM_Cycle(TIM_TypeDef * TIM , uint32_t TIM_Channel, uint16_t CCR);

void MyTimer_Incremental(TIM_TypeDef * TIM);
void MyTimer_Incremental_Config(TIM_TypeDef * TIM,void (*IT_function) (void));

#endif
