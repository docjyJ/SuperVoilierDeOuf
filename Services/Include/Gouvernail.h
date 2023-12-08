#ifndef MYGOUV_H
#define MYGOUV_H
#include "stm32f10x.h"

void MyGouv_Init(void);

void MyGouv_Command(char cmd);

void MyGouv_Send(char* cmd);

#endif
