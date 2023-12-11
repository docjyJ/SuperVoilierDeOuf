#include "Gestion_Voiles.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "stm32f10x.h"

#include "Pin.h"

void MyInit_PWM_Voilier(){
	MyGPIO_Init(GPIO_PWM_VOILE,PIN_PWM_VOILE,AltOut_Ppull);
	MyTimer_Base_Init(USED_TIM_VOILES,1600,900);
	MyTimer_Base_Start(USED_TIM_VOILES);
	MyTimer_PWM(USED_TIM_VOILES,3);
}

void MyChange_PWM_Cycle(int Cycle) {
	MyTimer_PWM_Cycle(USED_TIM_VOILES,3,(16*Cycle)/10);
}

void MyLacher_Voiles(){
	MyChange_PWM_Cycle(MIN_ANGLE_VOILES);
}
void MySerrer_Voiles(){
	MyChange_PWM_Cycle(MAX_ANGLE_VOILES);
}

int MyConvert_360_to_180(int angle){
	return 360-angle;
}

int MyAngle_voiles(int angle){
	int angle_final;
	if (angle > 180) angle = MyConvert_360_to_180(angle);
	if(angle < 45) angle_final = 0; 
	else {
		angle_final = ((angle-45)*90)/135;
	}
	return angle_final;
}

int MyAngle_PWM(int angle){
	return 100-((int)MyAngle_voiles(angle)/1.8);
}
