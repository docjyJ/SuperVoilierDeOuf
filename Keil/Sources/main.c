#include "stm32f10x.h"
#include "Driver_GPIO.h"
#include "adxl345.h"
#include "ds1307_RTC.h"


int main() {
	/*	
	MyGPIO_Init(GPIOA,5,Out_Ppull);
	
	
	adxl345_Init();
	
	while (1) {
		
		if (adxl345_CheckAccelero()==1){
			MyGPIO_Set(GPIOA,5);
		}else {
			MyGPIO_Reset(GPIOA,5);
		}
	}
	
	*/
	
	
	ds1307_time time;
	
	time.secondes=0;
	time.minutes=0;

	
	
	ds1307_init(I2C1);
	ds1307_reset_time(I2C1, &time);
	while (1){
			time = ds1307_get_time(I2C1);
	}

}


