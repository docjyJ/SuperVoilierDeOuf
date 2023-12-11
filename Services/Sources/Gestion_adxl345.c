#include "stm32f10x.h"
#include "Gestion_adxl345.h"
#include "MySPI.h"
#include "stdlib.h"
#include "Pin.h"

void MyAdxl345_Init() {
    MySPI_Init(ADXL345_SPI);

    //POWER_CTL
    MySPI_Clear_NSS();
    MySPI_Send(0x2D);
    MySPI_Send(0x08);
    MySPI_Set_NSS();

    //BW_RATE
    MySPI_Clear_NSS();
    MySPI_Send(0x2C);
    MySPI_Send(0x09);
    MySPI_Set_NSS();

    //DATA_FORMAT
    MySPI_Clear_NSS();
    MySPI_Send(0x31);
    MySPI_Send(0x0B);
    MySPI_Set_NSS();
}

uint8_t MyAdxl345_CheckAccelerometer() {
    MySPI_Clear_NSS();

    MySPI_Send(0xF2);

    //X
    MySPI_Read();
    MySPI_Read();
    int16_t Y = MySPI_Read() + (MySPI_Read() << 8);
    int16_t Z = MySPI_Read() + (MySPI_Read() << 8);

    MySPI_Set_NSS();

    return abs(Y) >= Z;
}

