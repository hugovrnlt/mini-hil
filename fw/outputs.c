#include <stdio.h>
#include "outputs.h"

// Simule ce que feraient les vraies sorties hardware (DAC, PWM, GPIO)

void output_pressure(float val) {
    // Sur vrai microControl : écriture registre DAC
    if (val > 1050.0f)
        printf("[OUTPUT] PRESSION HAUTE -> GPIO alarme \n");
    else
        printf("[OUTPUT] Pression OK\n");
}

void output_temp(float val) {
    // Sur vrai microControl : duty cycle PWM ventilateur par ex
    int pwm = (int)((val / 40.0f) * 100.0f);
    printf("[OUTPUT] Temp -> PWM ventilateur : %d\n", pwm);
}

void output_lidar(float val) {
    // Sur vrai microControl : écriture DAC 12 bits
    int dac = (int)((val / 400.0f) * 4095.0f);
    printf("[OUTPUT] LiDAR -> DAC : %d/4095\n", dac);
}