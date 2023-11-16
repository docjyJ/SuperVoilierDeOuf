#include "stm32f10x.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"
#include "Driver_USART.h"
#include "Gouvernail.h"


int main() {
	
	MyUsart_Base_Init (USART1, 9600);
	MyUsart_Base_Init (USART2, 19200);
	MyUsart_Base_Init (USART3, 38400);
	
	
	while(1){
		__asm__ ("nop");
	}
}
