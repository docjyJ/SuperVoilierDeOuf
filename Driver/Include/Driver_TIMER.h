#ifndef Driver_TIMER_h_
#define Driver_TIMER_h_

#include "stm32f10x.h"

#define MyTimer_BaseStart(TIM) TIM->CR1 |= TIM_CR1_CEN
#define MyTimer_BaseStop(TIM) TIM->CR1 &= ~TIM_CR1_CEN
#define MyTimer_ResetCount(TIM) TIM->CNT = 0
#define MyTimer_GetCount(TIM) TIM->CNT

void MyTimer_BaseInit(TIM_TypeDef *TIM, uint16_t ARR, uint16_t PSC);

void MyTimer_ActiveIT(TIM_TypeDef *TIM, uint8_t priority, void (*IT_fun)(void));

void MyTimer_PWM(TIM_TypeDef *TIM, uint8_t TIM_Channel);

void MyTimer_PWMCycle(TIM_TypeDef *TIM, uint8_t TIM_Channel, uint16_t CCR);

void MyTimer_Incremental(TIM_TypeDef *TIM);

void MyTimer_IncrementalConfig(TIM_TypeDef *TIM, uint8_t priority, void (*IT_function)(void));

#endif
