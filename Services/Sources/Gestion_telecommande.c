#include "Gestion_telecommande.h"
#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_TIMER.h"
#include "Driver_USART.h"
#include "Gestion_ds1307_RTC.h"

#include <stdio.h>
#include "Pin.h"

#define BAUDRATE_USART 9600
#define TIM_FREQ_TEL 72
#define REZ_PWM_TEL 110

void MyGestion_Tel_Init() {
	MyGPIO_Init(GPIO_PWM_TEL, PIN_PWM_TEL, AltOut_Ppull);
	MyGPIO_Init(GPIO_SENS_TEL, PIN_SENS_TEL, Out_Ppull);
	
	MyTimer_Base_Init(USED_TIM_TEL, REZ_PWM_TEL-1, TIM_FREQ_TEL/2-1);
	MyTimer_PWM(USED_TIM_TEL, 2);
	MyTimer_PWM_Cycle(USED_TIM_TEL, 2, 0);
	MyTimer_Base_Start(USED_TIM_TEL);
	
	MyGPIO_Init (GPIO_TX_TEL, AltOut_Ppull_10);
	MyGPIO_Init (GPIO_RX_TEL, In_PullUp);
	
	MyUsart_Base_Init (USED_USART_TEL, BAUDRATE_USART);
	MyUsart_ActiveIT (USED_USART_TEL, 2, MyGestion_Tel_Command);
	
	MyDs1307_Init(USED_I2C);

}

void MyGestion_Tel_Command(char cmd) {
	int8_t leNew = (int8_t) cmd;
	if (leNew < 0) {		
		MyGPIO_Set(GPIO_SENS_TEL, PIN_SENS_TEL);
		leNew = -leNew;
	}
	else {
		MyGPIO_Reset(GPIO_SENS_TEL, PIN_SENS_TEL);
	}
	MyTimer_PWM_Cycle(USED_TIM_TEL, 2, leNew);
}

void MyGestion_Tel_Send(char* sms) {
	char head[12];
	int i;
	
	MyDs1307_time time = MyDs1307_GetTime(USED_I2C);

	sprintf(head, "[%02d:%02d:%02d] ", time.heures, time.minutes, time.secondes);
	
	
	for (i = 0; i < 11; i++) MyUsart_Send(USED_USART_TEL, head[i]);
	
  for (i = 0; sms[i]; i++) MyUsart_Send(USED_USART_TEL, sms[i]);

	
	MyUsart_Send(USED_USART_TEL, '\n');
}
