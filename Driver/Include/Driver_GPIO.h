#ifndef Driver_GPIO_h_
#define Driver_GPIO_h_

#include "stm32f10x.h"

#define In_Floating         0x04
#define In_PullDown         0x08
#define In_PullUp           0x18
#define In_Analog           0x00
#define Out_Ppull           0x02
#define Out_Ppull_height    0x12
#define Out_OD              0x06
#define Out_OD_height       0x16
#define AltOut_Ppull        0x0A
#define AltOut_Ppull_50     0x0B
#define AltOut_OD           0x0E
#define AltOut_Ppull_10     0x09

void MyGPIO_Init(GPIO_TypeDef *GPIO, uint16_t GPIO_Pin, uint16_t GPIO_Conf);

#define MyGPIO_Read(GPIO, GPIO_Pin) ((GPIO->IDR >> GPIO_Pin) & 1)
#define MyGPIO_Set(GPIO, GPIO_Pin) GPIO->ODR |= 1 << GPIO_Pin
#define MyGPIO_Reset(GPIO, GPIO_Pin) GPIO->ODR &= ~(1 << GPIO_Pin)
#define MyGPIO_Toggle(GPIO, GPIO_Pin) GPIO->ODR ^= 1 << GPIO_Pin

#endif
