#ifndef DRIVER_DS1307_RTC_H_
#define DRIVER_DS1307_RTC_H_

#include "stm32f10x.h"

typedef struct
	{
		char secondes;  
		char minutes;  
		char heures;  
		char jours;  
	}ds1307_time;


void ds1307_init(I2C_TypeDef * I2C);

void ds1307_reset_time(I2C_TypeDef * I2C, ds1307_time * time);
	
ds1307_time ds1307_get_time(I2C_TypeDef * I2C);

#endif
