#include "stm32f10x.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"
#include "girouette.h"
int angle;

int main() {
	
	MyGPIO_Init ( GPIOA,  8, In_PullDown);
	MyGPIO_Init ( GPIOA,  9, In_PullDown);
	MyGPIO_Init ( GPIOA,  12, In_Floating);
	
	Config_Girouette(TIM1);

	while(1){
		angle = getAngle(TIM1);
	}
}
