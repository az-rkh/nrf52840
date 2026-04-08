#include <stdint.h>
#include "sched.h"
#include "task.h"
#include "hw.h"

task_t *current_task = 0;
task_t *ready_list[NPRIORITIES] = {0};
uint32_t ticks;

task_t *scheduler_next(void)
{
    for (int i = NPRIORITIES - 1; i >= 0; i--) {
        if (ready_list[i] != 0) {
            return ready_list[i];
        }
    }
    return 0;
}

void systick_init(uint32_t ticks_per_period) 
{                                       
    SYSTICK_LOAD = ticks_per_period - 1;
    SYSTICK_VAL  = 0;                                                                
    SYSTICK_CTRL = SYSTICK_CLKSRC | SYSTICK_TICKINT | SYSTICK_ENABLE;                
}

void systick_handler(void)
{
    ticks++;
}