#include "stm32f10x.h"
#include "Gouvernail.h"


int main() {
	MyGouv_Init();
	
	while(1){
		__asm__ ("nop");
	}
}
