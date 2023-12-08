#include "stm32f10x.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"
#include "Girouette.h"
#include "Voiles.h"
int angle;

int main() {
	
	MyGPIO_Init ( GPIOA,  6, In_Floating);
	MyGPIO_Init ( GPIOA,  7, In_Floating);
	MyGPIO_Init ( GPIOB,  1, In_Floating);

	Config_Girouette();
	while(!get_start());
	
	Init_PWM_Voilier();
	
	while(1){
		angle = getAngle();
		Change_PWM_Cycle(angle_PWM(angle));
		
	}
}
