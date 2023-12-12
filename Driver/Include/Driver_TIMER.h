#ifndef Driver_TIMER_h_
#define Driver_TIMER_h_

#include "stm32f10x.h"

#define MyTimer_Start(TIM) TIM->CR1 |= TIM_CR1_CEN
#define MyTimer_Stop(TIM) TIM->CR1 &= ~TIM_CR1_CEN
#define MyTimer_ResetCount(TIM) TIM->CNT = 0
#define MyTimer_GetCount(TIM) TIM->CNT

void MyTIM_BaseInit(TIM_TypeDef *TIM, uint16_t ARR, uint16_t PSC);

void MyTIM_ActiveIT(TIM_TypeDef *TIM, uint8_t priority, void (*IT_fun)(void));

void MyTimer_PWMInit(TIM_TypeDef *TIM, uint8_t channel);

void MyTimer_PWMCycle(TIM_TypeDef *TIM, uint8_t channel, uint16_t CCR);

void MyTimer_IncrementalInit(TIM_TypeDef *TIM);

void MyTimer_IncrementalActiveIT(TIM_TypeDef *TIM, uint8_t priority, void (*IT_function)(void));

#endif
