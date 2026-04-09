#include <stdint.h>
#include "sched.h"
#include "task.h"
#include "hw.h"

task_t *current_task = 0;
task_t *ready_list[NPRIORITIES] = {0};
uint32_t ticks;
task_t *sleep_list = 0;

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
    SCB_ICSR |= PENDSV_SET;

    task_t *prev = 0;

    for (task_t *t = sleep_list; t != 0; t = t->next) {

        if (t->wake_tick <= ticks) {
            task_t *tmp = t->next;
            t->state = READY;
            t->next = ready_list[t->priority];
            ready_list[t->priority] = t;
            if (prev == 0) 
                sleep_list = tmp;
            else 
                prev->next = tmp;
        }
        else
            prev = t;
    }
}