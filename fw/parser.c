#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "sensors.h"

void parse_line(const char *line) {
    float value;

    if (sscanf(line, "SIM:PRES:%f", &value) == 1) {
        sensor_update_pressure(value);
    } else if (sscanf(line, "SIM:TEMP:%f", &value) == 1) {
        sensor_update_temp(value);
    } else if (sscanf(line, "SIM:LIDAR:%f", &value) == 1) {
        sensor_update_lidar(value);
    } else {
        fprintf(stderr, "[PARSER] trame inconnue: %s", line);
    }
}