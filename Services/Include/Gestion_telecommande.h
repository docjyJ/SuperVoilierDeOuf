#ifndef MY_GESTION_TEL_H
#define MY_GESTION_TEL_H
#include "stm32f10x.h"

void MyGestion_Tel_Init(void);

void MyGestion_Tel_Command(char cmd);

void MyGestion_Tel_Send(char* cmd);

#endif
