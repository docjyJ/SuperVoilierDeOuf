#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"

#define TensionBatPort GPIOA
#define TensionBatPin 4
#define USED_ADC ADC1
#define ADC_CHANNEL 0

void MyBatConfigPin (){
	MyGPIO_Init(TensionBatPort, TensionBatPin, In_Analog);
	MyADC_Init(USED_ADC, ADC_CHANNEL);
	MyADC_On(USED_ADC);
}

uint32_t MyBatGetVoltage () {
	return MyADC_Read(USED_ADC);
}
