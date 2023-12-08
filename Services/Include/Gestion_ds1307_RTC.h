#ifndef GESTION_DS1307_RTC_H_
#define GESTION_DS1307_RTC_H_

#include "stm32f10x.h"

typedef struct
	{
		char secondes;  
		char minutes;  
		char heures;  
		char jours;  
	}MyDs1307_time;


void MyDs1307_Init(I2C_TypeDef * I2C);

void MyDs1307_ResetTime(I2C_TypeDef * I2C, MyDs1307_time * time);
	
MyDs1307_time MyDs1307_GetTime(I2C_TypeDef * I2C);

#endif
