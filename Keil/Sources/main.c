#include "stm32f10x.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"
#include "Girouette.h"
#include "Voiles.h"
int angle;

int main() {
	
	MyGPIO_Init ( GPIOA,  8, In_Floating);
	MyGPIO_Init ( GPIOA,  9, In_Floating);
	MyGPIO_Init ( GPIOA,  12, In_Floating);
	
	Config_Girouette(TIM1);

	
	Init_PWM_Voilier(TIM3);
	
	while(1){
		angle = getAngle(TIM1);
		Change_PWM_Cycle(TIM3,angle_PWM(angle));
		
	}
}
