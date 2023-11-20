#include "stm32f10x.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"
#include "Driver_USART.h"
#include "Gouvernail.h"

void Blop1(){
	int test = MyUsart_Receive(USART1);
	test++;
	MyUsart_Send(USART1, 'O');
}


int main() {
	
	MyUsart_Base_Init (USART1, 9600, Blop1);
	MyUsart_Base_Init (USART2, 19200, 0);
	MyUsart_Base_Init (USART3, 38400, 0);
	MyUsart_Send(USART1, 'i');
	
	while(1){
		__asm__ ("nop");
	}
}
