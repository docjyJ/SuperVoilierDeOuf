#include "Gestion_ds1307_RTC.h"
#include "MyI2C.h"
#include "Pin.h"


void MyDs1307_MyCallbackErr() {}


void MyDs1307_Init() {
    char info = 17;

    MyI2C_RecSendData_Typedef data;
    data.SlaveAdress7bits = 104;
    data.Ptr_Data = &info;
    data.Nb_Data = 1;

    MyI2C_Init(DS1307_I2C, 2, &MyDs1307_MyCallbackErr);
    MyI2C_PutString(DS1307_I2C, 0x07, &data);
}

MyDs1307_time MyDs1307_GetTime() {
    MyDs1307_time time;

    MyI2C_RecSendData_Typedef data;
    data.SlaveAdress7bits = 104;
    data.Ptr_Data = (char *) (&time);
    data.Nb_Data = 4;

    MyI2C_GetString(DS1307_I2C, 0x00, &data);

    time.secondes = ((time.secondes & 0x70) * 10 >> 4) + (time.secondes & 0x0F);
    time.minutes = ((time.minutes & 0xF0) * 10 >> 4) + (time.minutes & 0x0F);
    time.heures = ((time.heures & 0xF0) * 10 >> 4) + (time.heures & 0x0F);

    return time;
}

void MyDs1307_ResetTime(MyDs1307_time *time) {
    MyI2C_RecSendData_Typedef data;

    time->secondes = ((time->secondes / 10) << 4) + (time->secondes % 10);
    time->minutes = ((time->minutes / 10) << 4) + (time->minutes % 10);
    time->heures = ((time->heures / 10) << 4) + (time->heures % 10);

    data.SlaveAdress7bits = 104;
    data.Ptr_Data = (char *) (time);
    data.Nb_Data = 4;

    MyI2C_PutString(DS1307_I2C, 0x00, &data);
}
