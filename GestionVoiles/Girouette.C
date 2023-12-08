#include "Girouette.h"
#include "Driver_TIMER.h"
#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_TIMER.h"

#define TIM_GIR TIM3

bool start = false;

bool get_start(){
	return start;
}

void Girouette_RAZ(void){
	RESET_TIM(TIM_GIR);
	start = true;
}

void Config_Girouette(void) {
	
	MyTimer_Base_Init(TIM_GIR, 1439, 0);
	MyTimer_Incremental_Config(TIM_GIR,&Girouette_RAZ);
	TIM3->DIER |= TIM_DIER_UIE;

}

int getAngle(void){
	return TIM_GIR->CNT/4;
}

void resetAngle(void){
	TIM_GIR->CNT = 0;
} 






