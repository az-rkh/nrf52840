#ifndef SCHED_H
#define SCHED_H

#include "task.h"

extern task_t *current_task;

task_t *scheduler_next(void);

#endif