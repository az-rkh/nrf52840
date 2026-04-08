#ifndef SCHED_H
#define SCHED_H

#include "task.h"

#define NPRIORITIES 8


extern uint32_t ticks;

extern task_t *current_task;

extern task_t *ready_list[NPRIORITIES];
extern task_t *sleep_list = {0};

task_t *scheduler_next(void);
void systick_init(uint32_t ticks_per_period);
void systick_handler(void);

#endif