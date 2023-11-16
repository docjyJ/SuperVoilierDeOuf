


#include "Driver_TIMER.h"
#include "stm32f10.h"


int getAngle(TIM_TypeDef * TIM){
	return TIM->CNT;
}

void resetAngle(TIM_TypeDef * TIM){
	TIM->CNT = 0;
} 
