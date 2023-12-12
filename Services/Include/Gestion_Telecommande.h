#ifndef GESTION_TELECOMMANDE_H_
#define GESTION_TELECOMMANDE_H_

#include "stm32f10x.h"

void MyTel_Init(void);

void MyTel_Send(char *cmd);

#endif
