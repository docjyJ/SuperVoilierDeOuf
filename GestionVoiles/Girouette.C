#include "girouette.h"
#include "Driver_TIMER.h"
#include "stm32f10x.h"

void Config_Girouette(TIM_TypeDef * TIM) {
	MyTimer_Base_Init(TIM, 1439, 0);
	MyTimer_Incremental(TIM);
	MyTimer_Base_Start(TIM);
}


int getAngle(TIM_TypeDef * TIM){
	return TIM->CNT/4;
}

void resetAngle(TIM_TypeDef * TIM){
	TIM->CNT = 0;
} 
