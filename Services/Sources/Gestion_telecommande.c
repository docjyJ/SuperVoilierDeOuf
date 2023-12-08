#include "Gestion_telecommande.h"
#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_TIMER.h"
#include "Driver_USART.h"
#include "Gestion_ds1307_RTC.h"
#include <stdio.h>


#define USED_TIM TIM2
#define TIM_FREQ 72
#define REZ_PWM 110
#define USED_USART USART3
#define GPIO_RX GPIOB, 11
#define GPIO_TX GPIOB, 10
#define BAUDRATE 9600
#define GPIO_PWM
#define GPIO_SENS_PORT GPIOA
#define GPIO_SENS_PIN 10
#define GPIO_PWM_PORT GPIOA
#define GPIO_PWM_PIN 1
#define USED_I2C I2C1



void MyGestion_Tel_Init() {
	MyGPIO_Init(GPIO_PWM_PORT, GPIO_PWM_PIN, AltOut_Ppull);
	MyGPIO_Init(GPIO_SENS_PORT, GPIO_SENS_PIN, Out_Ppull);
	
	MyTimer_Base_Init(USED_TIM, REZ_PWM-1, TIM_FREQ/2-1);
	MyTimer_PWM(USED_TIM, 2);
	MyTimer_PWM_Cycle(USED_TIM, 2, 0);
	MyTimer_Base_Start(USED_TIM);
	
	MyGPIO_Init (GPIO_TX, AltOut_Ppull_10);
	MyGPIO_Init (GPIO_RX, In_PullUp);
	
	MyUsart_Base_Init (USED_USART, BAUDRATE);
	MyUsart_ActiveIT (USED_USART, 2, MyGestion_Tel_Command);
	
	MyDs1307_Init(USED_I2C);
}

void MyGestion_Tel_Command(char cmd) {
	int8_t leNew = (int8_t) cmd;
	if (leNew < 0) {		
		MyGPIO_Set(GPIO_SENS_PORT, GPIO_SENS_PIN);
		leNew = -leNew;
	}
	else {
		MyGPIO_Reset(GPIO_SENS_PORT, GPIO_SENS_PIN);
	}
	MyTimer_PWM_Cycle(USED_TIM, 2, leNew);
}

void MyGestion_Tel_Send(char* sms) {
	char head[12];
	int i;
	
	MyDs1307_time time = MyDs1307_GetTime(USED_I2C);
	sprintf(head, "[%02d:%02d:%02d] ", time.heures, time.minutes, time.secondes);
	
	
	for (i = 0; i < 11; i++) MyUsart_Send(USED_USART, head[i]);
	
  for (i = 0; sms[i]; i++) MyUsart_Send(USED_USART, sms[i]);

	
	MyUsart_Send(USED_USART, '\n');
}
