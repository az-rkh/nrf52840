.syntax unified

.thumb_func
.global start_scheduler
start_scheduler:
    mrs r0, msp
    msr psp, r0
    mov r0, #2
    msr control, r0
    isb
    ldr r0, =0xE000ED04     /* SCB_ICSR */
    ldr r1, =0x10000000     /* PENDSV_SET */
    str r1, [r0]
    bx lr

.thumb_func
.global pendsv_handler
pendsv_handler:
    mrs r0, psp
    stmdb r0!, {r4-r11}
    ldr r1, =current_task
    ldr r1, [r1]
    str r0, [r1]

    push {lr}
    bl scheduler_next
    pop {lr}

    ldr r1, =current_task
    str r0, [r1]
    ldr r0, [r0]
    ldmia r0!, {r4-r11}
    msr psp, r0

    bx lr