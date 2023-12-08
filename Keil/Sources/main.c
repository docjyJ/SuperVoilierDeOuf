#include "stm32f10x.h"
#include "Gouvernail.h"
#include "GestionBat.h"

uint32_t Bat = 0;

int main() {
	MyGouv_Init();
	
	
	while(1){
		MyBatConfigPin();
		Bat = MyBatGetVoltage();
		__asm__ ("nop");
	}
}
