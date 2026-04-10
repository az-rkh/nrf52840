  .syntax unified
  .section .vectors, "a"
  .word __StackTop
  .word reset_handler
  .word nmi_handler       /* NMI */
  .word hardfault_handler /* HardFault */
  .word memmanage_handler /* MemManage */
  .word busfault_handler  /* BusFault */
  .word usagefault_handler /* UsageFault */
  .word 0
  .word 0
  .word 0
  .word 0
  .word default_handler   /* SVC */
  .word 0
  .word 0
  .word pendsv_handler    /* PendSV */
  .word systick_handler   /* SysTick */

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
  nmi_handler:
      b .

  .thumb_func
  hardfault_handler:
      b .

  .thumb_func
  memmanage_handler:
      b .

  .thumb_func
  busfault_handler:
      b .

  .thumb_func
  usagefault_handler:
      b .

  .thumb_func
  default_handler:
      b .