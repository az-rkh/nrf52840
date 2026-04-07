#include <stdint.h>
#include "sched.h"
#include "task.h"

task_t *current_task = 0;
task_t *ready_list[NPRIORITIES] = {0};

task_t *scheduler_next(void)
{
    for (int i = NPRIORITIES - 1; i >= 0; i--) {
        if (ready_list[i] != 0) {
            return ready_list[i];
        }
    }
    return 0;
}