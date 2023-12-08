#ifndef DRIVER_ADXL345_H_
#define DRIVER_ADXL345_H_

#include "stm32f10x.h"


void adxl345_Init(SPI_TypeDef * SPI);

int adxl345_CheckAccelero (void);

#endif
