#include <stdint.h>
#include "task.h"
#include "sched.h"
#include "hw.h"


uint32_t task1_stack[256];
uint32_t task2_stack[512];



void task1(void) 
{
    while (1) {
        P0_OUT ^= (1 << LED_BLUE_PIN);
        task_sleep(100);
    }
}



void task2(void)
{
    while (1) {
        P0_OUT ^= (1 << LED_BLUE_PIN);
        task_sleep(1000);
    }
}



int main() 
{
    P0_DIR |= (1 << LED_BLUE_PIN);


    tasks[0].priority = 1;
    tasks[1].priority = 2;

    task_stack_init(&tasks[0], task1, task1_stack, 256);
    task_stack_init(&tasks[1], task2, task2_stack, 512);

    ready_list[tasks[0].priority] = &tasks[0];
    ready_list[tasks[1].priority] = &tasks[1];

    current_task = scheduler_next();
    systick_init(64000);
    start_scheduler();
}