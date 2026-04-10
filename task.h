#ifndef TASK_H
#define TASK_H

#include <stdint.h>

#define NPRIORITIES 8

typedef enum {READY, RUNNING, SLEEPING} state_t;

typedef struct task {
    uint32_t *sp;
    uint8_t priority;
    state_t state;
    struct task *next;
    uint32_t wake_tick;
} task_t;

extern task_t tasks[NPRIORITIES];

extern void task_stack_init(task_t *task, void (*entry)(void), uint32_t *stack, int stack_size);
extern void task_sleep(uint32_t ms);

#endif