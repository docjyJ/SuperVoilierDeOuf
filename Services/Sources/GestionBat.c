#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"

#include "Pin.h"

void MyBatConfigPin (){
	MyGPIO_Init(GPIO_TEN_BAT, PIN_TEN_BAT, In_Analog);
	MyADC_Init(USED_ADC_BAT, ADC_CHANNEL_BAT);
	MyADC_On(USED_ADC_BAT);
}

uint32_t MyBatGetVoltage () {
	return (MyADC_Read(USED_ADC_BAT)*1000)/85;
}
