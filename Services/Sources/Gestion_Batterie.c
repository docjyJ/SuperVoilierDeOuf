#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"

#include "Pin.h"

void MyBat_Init() {
    MyGPIO_Init(BAT_PORT, BAT_PIN, In_Analog);
    MyADC_Init(BAT_ADC, BAT_CHANNEL);
    MyADC_On(BAT_ADC);
}

uint32_t MyBat_GetVoltage() {
    return MyADC_Read(BAT_ADC) * 200 / 17;
}
