#include "stm32f10x.h"
#include "Driver_GPIO.h"


void MyGPIO_Init(GPIO_TypeDef *GPIO, uint16_t GPIO_Pin, uint16_t GPIO_Conf) {
    if (GPIO == GPIOA) RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    else if (GPIO == GPIOB) RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    else if (GPIO == GPIOC) RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    else if (GPIO == GPIOD) RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
    else if (GPIO == GPIOE) RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
    else return;

    if (GPIO_Pin < 8) {
        uint8_t dec = (GPIO_Pin & 0x7) << 2;
        GPIO->CRL &= ~(0xF << dec);
        GPIO->CRL |= (GPIO_Conf & 0xF) << dec;
    } else if (GPIO_Pin < 16) {
        uint8_t dec = (GPIO_Pin & 0x7) << 2;
        GPIO->CRH &= ~(0xF << dec);
        GPIO->CRH |= (GPIO_Conf & 0xF) << dec;
    } else return;

    if (GPIO_Conf & 0x10)
        MyGPIO_Set(GPIO, GPIO_Pin);
    else
        MyGPIO_Reset(GPIO, GPIO_Pin);
}
