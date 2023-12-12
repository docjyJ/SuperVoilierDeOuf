#ifndef PIN_H
#define PIN_H

// ADXL345
#define ADXL345_SPI SPI2
/* SPI2 IO
 * NSS PB12
 * SCK PB13
 * MISO PB14
 * MOSI PB15
 */

// Bartterie
#define BAT_PORT GPIOA
#define BAT_PIN 4
#define BAT_ADC ADC1
#define BAT_CHANNEL 4

// DS1307
#define DS1307_I2C I2C1
/* I2C1 IO
 * SCL PB6
 * SDA PB7
 */

// Girouette
#define GIR_PHA_PORT GPIOA
#define GIR_PHA_PIN 6
#define GIR_PHB_PORT GPIOA
#define GIR_PHB_PIN 7
#define GIR_IDX_PORT GPIOB
#define GIR_IDX_PIN 1
#define GIR_TIM TIM3

// Telecommande
#define TEL_USART USART3
#define TEL_RX_PORT GPIOB
#define TEL_RX_PIN 11
#define TEL_TX_PORT GPIOB
#define TEL_TX_PIN 10
#define TEL_PWN_TIM TIM2
#define TEL_PWN_CHANNEL 2
#define TEL_PWN_PORT GPIOA
#define TEL_PWN_PIN 1
#define TEL_DIR_PORT GPIOA
#define TEL_DIR_PIN 10

//Voiles
#define VOILE_PORT GPIOB
#define VOILE_PIN 8
#define VOILE_TIM TIM4
#define VOILE_CHANNEL 3

#endif
