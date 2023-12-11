#include "stm32f10x.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"

#include "Gestion_adxl345.h"
#include "Gestion_ds1307_RTC.h"
#include "Gestion_telecommande.h"
#include "GestionBat.h"
#include "Gestion_Girouette.h"
#include "Gestion_Voiles.h"

#include "Pin.h"

int angle;
uint32_t battery;

int main() {
  uint32_t battery_min = 10*1000;
	bool low_bat_sent = false;

	
	MyGestion_Tel_Init();
	MyGestion_Tel_Send("Initialisation...");

	MyBatConfigPin();
	Myadxl345_Init(USED_SPI);
	MyConfig_Girouette();
	while(!MyGet_start());

	MyInit_PWM_Voilier();
  MyGestion_Tel_Send("Initialisation complète");

	while(1){
		battery = MyBatGetVoltage();
		if (battery < battery_min && !low_bat_sent){
			low_bat_sent = true;
			MyGestion_Tel_Send("Plus de batterie, rentrer l'appareil");
		}
		
		if(Myadxl345_CheckAccelero()){
			MyLacher_Voiles();
		}else{
			angle = MyGetAngle();
			MyChange_PWM_Cycle(MyAngle_PWM(angle));
		}
	}
}

