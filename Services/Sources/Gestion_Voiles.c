#include "Gestion_Voiles.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "Gestion_Girouette.h"
#include "stm32f10x.h"
#include "Pin.h"
#include "Gestion_adxl345.h"

void MyVoile_Init() {
    MyAdxl345_Init();
    MyGir_Init();

    MyGPIO_Init(VOILE_PORT, VOILE_PIN, AltOut_Ppull);
    MyTimer_BaseInit(VOILE_TIM, 1599, 899);
    MyTimer_BaseStart(VOILE_TIM);
    MyTimer_PWM(VOILE_TIM, VOILE_CHANNEL);
}

void MyVoile_UpdateVoile(){
    if (MyAdxl345_CheckAccelerometer()) {
        MyTimer_PWMCycle(VOILE_TIM, VOILE_CHANNEL, 80);
    } else {
        uint16_t angle = MyGir_GetAngle();
        if (angle > 180) angle = 360 - angle;

        if (angle < 45) angle = 160;
        else angle = (315 - angle) * 16 / 27;

        MyTimer_PWMCycle(VOILE_TIM, VOILE_CHANNEL, angle);
    }
}
