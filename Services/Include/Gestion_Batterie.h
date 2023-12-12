#ifndef GESTION_BATTERIE_H_
#define GESTION_BATTERIE_H_

#include "stm32f10x.h"

void MyBat_Init(void);

uint32_t MyBat_GetVoltage(void);

#endif
