#ifndef GIROUETTE_H
#define GIROUETTE_H
#include "stdbool.h"
#include "stm32f10x.h"
#define RESET_TIM(Timer) (Timer->CNT = 0)

bool get_start(void);
void Config_Girouette(void);
	
int getAngle(void);

void resetAngle(void);



#endif
