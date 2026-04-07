#ifndef SCHED_H
#define SCHED_H

#include "task.h"

#define NPRIORITIES 8

extern task_t *current_task;

extern task_t *ready_list[NPRIORITIES];

task_t *scheduler_next(void);

#endif