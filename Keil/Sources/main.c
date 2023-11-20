#include "stm32f10x.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"
#include "Driver_USART.h"
#include "Gouvernail.h"

void Blop1(char test){
	test++;
	MyUsart_Send(USART3, 'O');
}


int main() {
	MyGPIO_Init ( GPIOB,  10, AltOut_Ppull_10);
	MyGPIO_Init ( GPIOB,  11, In_PullUp);
	
	MyUsart_Base_Init (USART3, 9600);
	MyUsart_ActiveIT (USART3, 2, Blop1);
	
	
	
	while(1){
		MyUsart_Send(USART3, 'i');
	}
}
