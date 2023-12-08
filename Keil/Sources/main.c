#include "stm32f10x.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"

#include "Gestion_adxl345.h"
#include "Gestion_ds1307_RTC.h"
#include "Gestion_telecommande.h"
#include "GestionBat.h"


int main() {

  uint32_t battery_min = 12;

	
	MyGestion_Tel_Init();
	MyBatConfigPin();
	
	// PIN A V2RIFIER
	
	Myadxl345_Init(SPI2);
	// Myds1307_init() I2C1
	
	
	while(1){
		if (MyBatGetVoltage() < battery_min){
			MyGestion_Tel_Send("Plus de batterie, rentrer l'appareil");
		}
	}
}

