#include <stdio.h>
#include "sensors.h"
#include "outputs.h"

void sensor_update_pressure(float val) {
    printf("[SENSOR] Pression  : %.2f hPa\n", val);
    output_pressure(val);
}

void sensor_update_temp(float val) {
    printf("[SENSOR] Temp      : %.2f degrés\n", val);
    output_temp(val);
}

void sensor_update_lidar(float val) {
    printf("[SENSOR] LiDAR     : %.1f mm\n", val);
    output_lidar(val);
}