#ifndef GESTION_ADXL345_H_
#define GESTION_ADXL345_H_

#include "stm32f10x.h"

void MyAdxl345_Init(void);

uint8_t MyAdxl345_CheckAccelerometer(void);

#endif
