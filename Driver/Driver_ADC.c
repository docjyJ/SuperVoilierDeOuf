#include "stm32f10x.h"
#include "Driver_ADC.h"


void MyADC_Init(ADC_TypeDef * ADC, uint32_t chanel) {
	     if (ADC==ADC1) RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	else if (ADC==ADC2) RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
	else return;
	
  RCC->CFGR &= ~RCC_CFGR_ADCPRE;
	RCC->CFGR |= RCC_CFGR_ADCPRE_1;
	
	if(chanel < 18) {
		ADC->SQR3 &= ~0x1F;
		ADC->SQR3 |= chanel;
		ADC->SQR1 &= ~ADC_SQR1_L;
		ADC->CR2 = ADC_CR2_CONT;
	  MyADC_On(ADC1);
	}
}