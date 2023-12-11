#include "Gestion_Girouette.h"
#include "Driver_TIMER.h"
#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_TIMER.h"

#include "Pin.h"

bool start = false;

bool MyGet_start(){
	return start;
}

void MyGirouette_RAZ(void){
	RESET_TIM(USED_TIM_GIR);
	start = true;
}

void MyConfig_Girouette(void) {
	
	MyGPIO_Init ( GPIO_PHA_GIR,  PIN_PHA_GIR, In_Floating);
	MyGPIO_Init ( GPIO_PHB_GIR,  PIN_PHB_GIR, In_Floating);
	MyGPIO_Init ( GPIO_IDX_GIR,  PIN_IDX_GIR, In_Floating);
	
	MyTimer_Base_Init(USED_TIM_GIR, 1439, 0);
	MyTimer_Incremental_Config(USED_TIM_GIR,&MyGirouette_RAZ);
	USED_TIM_GIR->DIER |= TIM_DIER_UIE;

}

int MyGetAngle(void){
	return USED_TIM_GIR->CNT/4;
}

void MyResetAngle(void){
	USED_TIM_GIR->CNT = 0;
} 






