#include "Gestion_Girouette.h"
#include "Driver_TIMER.h"
#include "stm32f10x.h"
#include "Driver_GPIO.h"

#include "Pin.h"

uint8_t Gestion_Girouette_Start = 0x01;

void MyGirouette_RAZ() {
    MyTimer_ResetCount(GIR_TIM);
    Gestion_Girouette_Start = 0x00;
}

void MyGir_Init() {
    MyGPIO_Init(GIR_PHA_PORT, GIR_PHA_PIN, In_Floating);
    MyGPIO_Init(GIR_PHB_PORT, GIR_PHB_PIN, In_Floating);
    MyGPIO_Init(GIR_IDX_PORT, GIR_IDX_PIN, In_Floating);

    MyTimer_BaseInit(GIR_TIM, 1439, 0);
    MyTimer_Incremental(GIR_TIM);
    MyTimer_IncrementalConfig(GIR_TIM, 4, &MyGirouette_RAZ);

    while (Gestion_Girouette_Start);
}

uint16_t MyGir_GetAngle() {
    return MyTimer_GetCount(GIR_TIM) / 4;
}






