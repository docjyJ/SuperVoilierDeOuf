#ifndef GESTION_VOILES_H
#define GESTION_VOILES_H
#include "stm32f10x.h"

void MyInit_PWM_Voilier(void);

void MyChange_PWM_Cycle(int Cycle);
#define MAX_ANGLE_VOILES 100
#define MIN_ANGLE_VOILES 50

void MyLacher_Voiles(void);
void MySerrer_Voiles(void);

int MyConvert_360_to_180(int angle);

int MyAngle_voiles(int angle);

int MyAngle_PWM(int angle);


#endif

