#include "Driver_ds1307_RTC.h"
#include "MyI2C.h"

#include <stdlib.h>


void ds1307_My_CallbackErr (){
}


void ds1307_init(I2C_TypeDef * I2C){
	
	char info  = 17;
	
	MyI2C_RecSendData_Typedef data;
	
	data.SlaveAdress7bits=104;
	data.Ptr_Data = &info;
	data.Nb_Data = 1;
	
	MyI2C_Init(I2C, 2, &ds1307_My_CallbackErr);
	
	MyI2C_PutString(I2C, 0x07, &data);
}

ds1307_time ds1307_get_time(I2C_TypeDef * I2C){
	
	char dixaines_secondes;
	char dixaines_minutes;
	char dixaines_heures;
	
	
	ds1307_time time;
	
	MyI2C_RecSendData_Typedef data;
	
	data.SlaveAdress7bits=104;
	data.Ptr_Data = (char *) (&time);
	data.Nb_Data = 4;

	

	
	MyI2C_GetString (I2C, 0x00, &data);
	
	dixaines_secondes = (time.secondes & (0x70));
	time.secondes = (dixaines_secondes*10>> 4)+ (time.secondes & (0x0F));

	dixaines_minutes = (time.minutes & (0xF0));
	time.minutes = (dixaines_minutes*10>> 4) + (time.minutes & (0x0F));
	
	dixaines_heures = (time.heures & (0xF0));
	time.heures = ( dixaines_heures *10>> 4 ) + (time.heures & (0x0F));
	
	
	return (time);
}

void ds1307_reset_time(I2C_TypeDef * I2C, ds1307_time * time){
	MyI2C_RecSendData_Typedef data;

	
	time->secondes = ((time->secondes /10) << 4) + (time->secondes %10);
	time->minutes = ((time->minutes /10) << 4) + (time->minutes %10);
	time->heures = ((time->heures /10) << 4) + (time->heures %10);

	
	data.SlaveAdress7bits=104;
	data.Ptr_Data = (char *) (time);
	data.Nb_Data = 4;
	
	
	
	MyI2C_PutString(I2C, 0x00, &data);

}
