#include <stdio.h>
#include "scheduler.h"

static int tick_count = 0;

void scheduler_tick(void) {
    tick_count++;
    if (tick_count % 30 == 0)  // toutes les 30 trames
        printf("[SCHEDULER] tick #%d\n", tick_count);
}