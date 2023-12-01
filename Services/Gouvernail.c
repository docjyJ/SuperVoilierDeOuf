#include "Gouvernail.h"
#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_TIMER.h"

#include "Driver_USART.h"

void MyGouv_Init() {
	MyGPIO_Init(GPIOA, 1, AltOut_Ppull); // TODO: LA PIN ?
	MyGPIO_Init(GPIOA, 2, Out_Ppull);
	
	MyTimer_Base_Init(TIM2, 50, 71); // TODO: FRECANCE ?
	MyTimer_PWM(TIM2, 2);
	MyTimer_PWM_Cycle(TIM2, 2, 0);
	MyTimer_Base_Start(TIM2);
	
	MyGPIO_Init ( GPIOB,  10, AltOut_Ppull_10);
	MyGPIO_Init ( GPIOB,  11, In_PullUp);
	
	MyUsart_Base_Init (USART3, 9600);
	MyUsart_ActiveIT (USART3, 2, MyGouv_Command);
}

void MyGouv_Command(int8_t cmd) {
	if (cmd < 0) {
		MyGPIO_Set(GPIOA, 2);
		MyTimer_PWM_Cycle(TIM2, 2, cmd * 250);
	}
	else {
		MyGPIO_Reset(GPIOA, 2);
		MyTimer_PWM_Cycle(TIM2, 2, - cmd * 250);
	}
}
