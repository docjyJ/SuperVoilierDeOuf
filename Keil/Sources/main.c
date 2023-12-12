#include "Gestion_Telecommande.h"
#include "Gestion_Batterie.h"
#include "Gestion_Voiles.h"

int main() {
    uint32_t battery_min = 10 * 1000, battery, i;

    MyTel_Init();
    MyTel_Send("Initialisation...");
    MyBat_Init();
    MyVoile_Init();
    MyTel_Send("Initialisation complete");

    while (1) {
        battery = MyBat_GetVoltage();
        if (battery < battery_min) {
            MyTel_Send("Plus de batterie !");
        }

        MyVoile_UpdateVoile();
        for (i = 420; i; i--);
    }
}

