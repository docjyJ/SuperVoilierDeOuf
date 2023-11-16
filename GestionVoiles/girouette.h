#ifndef GIROUETTE_H
#define GIROUETTE_H
#include "stm32f10x.h"

void Config_Girouette(TIM_TypeDef * TIM);
	
int getAngle(TIM_TypeDef * TIM);

void resetAngle(TIM_TypeDef * TIM);

#endif