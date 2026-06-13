/* sim/simulator.c
* Simule un système embarqué qui enverrait des données capteurs via UART.
* Ici on remplace l'UART par stdout → le pipe | se charge du reste.
*/

#include <stdio.h>   // printf, fflush
#include <math.h>    // sinf, cosf
#include <unistd.h>  // usleep

int main(void) {
    float t = 0.0f;  // temps simulé, incrémenté à chaque tick

    while (1) {
        // Capteur pression : oscillation lente autour de 1013 hPa
        float pressure = 1013.25f + 50.0f * sinf(t);

        // Capteur température : oscillation encore plus lente
        float temp     = 20.0f + 5.0f * cosf(t * 0.5f);

        // LiDAR : distance en mm, oscillation rapide
        float lidar    = 200.0f + 100.0f * sinf(t * 2.0f);

        // Format des trames : "SIM:<CAPTEUR>:<VALEUR>\r\n"
        // \r\n = CRLF, standard des protocoles série embarqués
        printf("SIM:PRES:%.2f\r\n", pressure);
        printf("SIM:TEMP:%.2f\r\n", temp);
        printf("SIM:LIDAR:%.1f\r\n", lidar);

        fflush(stdout);  // CRUCIAL : vide le buffer immédiatement
                        // Sans ça, le pipe ne reçoit rien pendant des secondes

        t += 0.1f;
        usleep(100000);  // 100ms = 10 Hz de fréquence d'envoi
    }
}