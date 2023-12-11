#include "Gestion_Telecommande.h"
#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "Driver_TIMER.h"
#include "Driver_USART.h"
#include "Gestion_ds1307_RTC.h"
#include <stdio.h>
#include "Pin.h"


void MyTel_Command(uint16_t cmd) {
    int16_t leNew = (int16_t) cmd;
    if (leNew < 0) {
        MyGPIO_Set(TEL_DIR_PORT, TEL_DIR_PIN);
        leNew = -leNew;
    } else {
        MyGPIO_Reset(TEL_DIR_PORT, TEL_DIR_PIN);
    }
    MyTimer_PWMCycle(TEL_PWN_TIM, TEL_PWN_CHANNEL, leNew);
}

void MyTel_Init() {
    MyGPIO_Init(TEL_PWN_PORT, TEL_PWN_PIN, AltOut_Ppull);
    MyGPIO_Init(TEL_DIR_PORT, TEL_DIR_PIN, Out_Ppull);

    MyTimer_BaseInit(TEL_PWN_TIM, 109, 35);
    MyTimer_PWM(TEL_PWN_TIM, TEL_PWN_CHANNEL);
    MyTimer_PWMCycle(TEL_PWN_TIM, TEL_PWN_CHANNEL, 0);
    MyTimer_BaseStart(TEL_PWN_TIM);

    MyGPIO_Init(TEL_TX_PORT, TEL_TX_PIN, AltOut_Ppull_10);
    MyGPIO_Init(TEL_RX_PORT, TEL_RX_PIN, In_PullUp);

    MyUsart_Base_Init(TEL_USART, 9600);
    MyUsart_ActiveIT(TEL_USART, 2, MyTel_Command);

    MyDs1307_Init();
}

void MyTel_Send(char *sms) {
    char head[12];
    uint32_t i;

    MyDs1307_time time = MyDs1307_GetTime();

    sprintf(head, "[%02u:%02u:%02u] ", time.heures, time.minutes, time.secondes);

    for (i = 0; i < 11; i++) MyUsart_Send(TEL_USART, head[i]);

    for (i = 0; sms[i]; i++) MyUsart_Send(TEL_USART, sms[i]);

    MyUsart_Send(TEL_USART, '\n');
}
