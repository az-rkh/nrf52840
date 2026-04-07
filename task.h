#ifndef TASK_H
#define TASK_H

#include <stdint.h>

typedef enum state_t {READY, RUNNING, SLEEPING};

typedef struct task {
    uint32_t *sp;
    uint8_t priority;
    state_t state;
} task_t;

void task_stack_init(task_t *task, void (*entry)(void), uint32_t *stack, int stack_size);

#endif