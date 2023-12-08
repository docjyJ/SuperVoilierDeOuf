#include "stm32f10x.h"
#include "Driver_adxl345.h"
#include "MySPI.h"
#include "stdlib.h"

void adxl345_Init(SPI_TypeDef * SPI) {
	
	MySPI_Init(SPI);
	
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

int adxl345_CheckAccelero (void){
	
	short int X;
	short int Y;
	short int Z;
	
	MySPI_Clear_NSS();
	MySPI_Send(0xF2);

	X = MySPI_Read();
	X = X + (MySPI_Read()<<8);
	
	Y = MySPI_Read();
	Y = Y + (MySPI_Read()<<8);

	Z = MySPI_Read();
	Z = Z	+ (MySPI_Read()<<8);
	
	MySPI_Set_NSS();

	if (abs(Y) >=Z){

		return 1;
	}else {
		return 0;
	}
}

