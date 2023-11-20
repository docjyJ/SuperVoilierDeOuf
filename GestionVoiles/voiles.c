#include "Voiles.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "stm32f10x.h"

void Init_PWM_Voilier(TIM_TypeDef * TIM){
	MyGPIO_Init(GPIOA,6,AltOut_Ppull);
	MyTimer_Base_Init(TIM,1600,900);
	MyTimer_Base_Start(TIM);
	MyTimer_PWM(TIM,1);
}

void Change_PWM_Cycle(TIM_TypeDef * TIM, int Cycle) {
	MyTimer_PWM_Cycle(TIM,1,(16*Cycle)/10);
}

void Lacher_Voiles(TIM_TypeDef * TIM){
	Change_PWM_Cycle(TIM,MIN_ANGLE_VOILES);
}
void Serrer_Voiles(TIM_TypeDef * TIM){
	Change_PWM_Cycle(TIM,MAX_ANGLE_VOILES);
}

int convert_360_to_180(int angle){
	return 360-angle;
}

int angle_voiles(int angle){
	int angle_final;
	if (angle > 180) angle = convert_360_to_180(angle);
	if(angle < 45) angle_final = 0; 
	else {
		angle_final = ((angle-45)*90)/135;
	}
	return angle_final;
}

int angle_PWM(int angle){
	return 100-((int)angle_voiles(angle)/1.8);
}