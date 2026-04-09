#include <stdint.h>
#include "task.h"
#include "hw.h"
#include "sched.h"

task_t tasks[NPRIORITIES];

void task_stack_init(task_t *task, void (*entry)(void), uint32_t *stack, int stack_size)
{
    uint32_t *sp = stack + stack_size;

    *(--sp) = 0x01000000;       /* xPSR - thumb bit */
    *(--sp) = (uint32_t)entry;  /* PC */
    *(--sp) = 0;                /* LR */
    *(--sp) = 0;                /* r12 */
    *(--sp) = 0;                /* r3 */
    *(--sp) = 0;                /* r2 */
    *(--sp) = 0;                /* r1 */
    *(--sp) = 0;                /* r0 */


    /* software saved frame */
    *(--sp) = 0;                /* r11 */
    *(--sp) = 0;                /* r10 */
    *(--sp) = 0;                /* r9 */
    *(--sp) = 0;                /* r8 */
    *(--sp) = 0;                /* r7 */
    *(--sp) = 0;                /* r6 */
    *(--sp) = 0;                /* r5 */
    *(--sp) = 0;                /* r4 */

    task->sp = sp;
}

void task_sleep(uint32_t ms) 
{
    current_task->wake_tick = ticks + ms;

    ready_list[current_task->priority] = ready_list[current_task->priority]->next;

    current_task->next = sleep_list;
    sleep_list = current_task;

    current_task->state = SLEEPING;

    SCB_ICSR |= PENDSV_SET; /* context switch*/
}