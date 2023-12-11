#ifndef GESTION_DS1307_RTC_H_
#define GESTION_DS1307_RTC_H_

#include "stm32f10x.h"

typedef struct {
    uint8_t secondes;
    uint8_t minutes;
    uint8_t heures;
    uint8_t jours;
} MyDs1307_time;

void MyDs1307_Init(void);

void MyDs1307_ResetTime(MyDs1307_time *time);

MyDs1307_time MyDs1307_GetTime(void);

#endif
