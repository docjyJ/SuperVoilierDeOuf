#ifndef GESTION_GIROUETTE_H
#define GESTION_GIROUETTE_H
#include "stdbool.h"
#include "stm32f10x.h"
#define RESET_TIM(Timer) (Timer->CNT = 0)

bool MyGet_start(void);
void MyConfig_Girouette(void);
	
int MyGetAngle(void);

void MyResetAngle(void);



#endif
