#ifndef VOILES_H
#define VOILES_H
#include "stm32f10x.h"

void Init_PWM_Voilier(TIM_TypeDef * TIM);

void Change_PWM_Cycle(TIM_TypeDef * TIM, int Cycle);
#define MAX_ANGLE_VOILES 100
#define MIN_ANGLE_VOILES 50

void Lacher_Voiles(TIM_TypeDef * TIM);
void Serrer_Voiles(TIM_TypeDef * TIM);

int convert_360_to_180(int angle);

int angle_voiles(int angle);

int angle_PWM(int angle);


#endif

