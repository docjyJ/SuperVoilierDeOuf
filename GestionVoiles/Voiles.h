#ifndef VOILES_H
#define VOILES_H
#include "stm32f10x.h"
#define TIM_VOILES TIM4
void Init_PWM_Voilier(void);

void Change_PWM_Cycle(int Cycle);
#define MAX_ANGLE_VOILES 100
#define MIN_ANGLE_VOILES 50

void Lacher_Voiles(void);
void Serrer_Voiles(void);

int convert_360_to_180(int angle);

int angle_voiles(int angle);

int angle_PWM(int angle);


#endif

