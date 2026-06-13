/* fw/main.c — boucle principale du firmware */
#include <stdio.h>
#include "parser.h"
#include "sensors.h"
#include "outputs.h"
#include "scheduler.h"

int main(void) {
    char line[128];

    while (fgets(line, sizeof(line), stdin)) { // printf redirigé dans le stdin
        scheduler_tick(); // comme une interruption timer sur un vrai µC
        parse_line(line);
    }

    return 0;
}