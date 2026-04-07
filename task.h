#ifndef TASK_H
#define TASK_H

#include <stdint.h>

struct task {
    uint32_t *sp;
} task_t;

#endif