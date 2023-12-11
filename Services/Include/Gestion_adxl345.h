#ifndef GESTION_ADXL345_H_
#define GESTION_ADXL345_H_

#include "stm32f10x.h"


void Myadxl345_Init(SPI_TypeDef * SPI);

int Myadxl345_CheckAccelero (void);

#endif
