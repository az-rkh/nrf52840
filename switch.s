.syntax unified
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