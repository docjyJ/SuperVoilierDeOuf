#include "Girouette.h"
#include "Driver_TIMER.h"
#include "stm32f10x.h"
#include "Driver_GPIO.h"

#define TIM_GIR TIM3
void Config_Girouette(void) {
	MyTimer_Base_Init(TIM_GIR, 1439, 0);	
	MyTimer_Incremental_Config(TIM_GIR);
}

int getAngle(void){
	return TIM_GIR->CNT/4;
}

void resetAngle(void){
	TIM_GIR->CNT = 0;
} 



void EXTI1_IRQHandler(void) {

	// Remise à zéro du compteur  
	TIM3->CNT=0x0; 

	// Remise à zéro du flag 
	EXTI->PR |= 0x1 <<5;
}

void Girouette_RAZ(void){
	while ((MyGPIO_Read(GPIOB,1)) == 0);
	MyTimer_Base_Start(TIM3);
}

