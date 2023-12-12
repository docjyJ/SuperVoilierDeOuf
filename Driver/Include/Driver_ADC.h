#ifndef Driver_ADC_h_
#define Driver_ADC_h_

#include "stm32f10x.h"


void MyADC_Init(ADC_TypeDef *ADC, uint8_t channel);

#define MyADC_On(ADC) ADC->CR2 |= ADC_CR2_ADON
#define MyADC_Read(ADC) ADC->DR


#endif
