#include "stm32f10x.h"
#include "Driver_GPIO.h"

#define TensionBatPort //
#define TensionBatPin //
#define USED_ADC //
#define ADC_CHANNEL //

void MyBatConfigPin (){
	MyGPIO_Init(TensionBatPort, TensionBatPin, In_Analog);
	MyADC_Init(USED_ADC, ADC_CHANNEL);
	MyADC_On(USED_ADC);
}

uint32_t MyBatGetVoltage () {
	return MyADC_Read(USED_ADC);
}