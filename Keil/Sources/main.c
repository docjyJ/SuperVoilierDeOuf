#include "Gestion_Telecommande.h"
#include "Gestion_Batterie.h"
#include "Gestion_Voiles.h"


int main() {
    uint32_t battery_min = 10 * 1000;
    uint8_t low_bat_sent = 0x01;

    MyTel_Init();
    MyTel_Send("Initialisation...");
    MyBat_Init();
    MyVoile_Init();
    MyTel_Send("Initialisation complete");

    while (1) {
        if (MyBat_GetVoltage() < battery_min && low_bat_sent) {
            low_bat_sent = 0x00;
            MyTel_Send("Plus de batterie, rentrer l'appareil");
        }

        MyVoile_UpdateVoile();
    }
}

