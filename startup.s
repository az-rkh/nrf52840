  .section .vectors, "a"
  .word __StackTop
  .word reset_handler
  .word default_handler   /* NMI */
  .word default_handler   /* HardFault */
  .word default_handler   /* MemManage */
  .word default_handler   /* BusFault */
  .word default_handler   /* UsageFault */
  .word 0
  .word 0
  .word 0
  .word 0
  .word default_handler   /* SVC */
  .word 0
  .word 0
  .word pendsv_handler    /* PendSV */  ← change this
  .word default_handler   /* SysTick */

  .section .text
  .thumb_func
  reset_handler:
      ldr r0, =__data_start__
      ldr r1, =__data_end__
      ldr r2, =__etext
  1:  cmp r0, r1
      bge 2f
      ldr r3, [r2], #4
      str r3, [r0], #4
      b 1b

  2:  ldr r0, =__bss_start__
      ldr r1, =__bss_end__
      mov r2, #0
  3:  cmp r0, r1
      bge 4f
      str r2, [r0], #4
      b 3b

  4:  bl main
      b .

  .thumb_func
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

  .thumb_func
  default_handler:
      b .