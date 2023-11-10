#ifndef MYADC_H
#define MYADC_H
#include "stm32f10x.h"


void MyADC_Init(ADC_TypeDef * ADC, uint32_t chanel);

#define MyADC_On(ADC) ADC->CR2 |= ADC_CR2_ADON
#define MyADC_Read(ADC) ADC->DR


#endif
