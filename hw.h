#ifndef HW_H
#define HW_H

#define SCB_ICSR (*(volatile unsigned int *) 0xE000ED04)
#define PENDSV_SET (1 << 28)

#define SYSTICK_CTRL  (*(volatile uint32_t *)0xE000E010)
#define SYSTICK_LOAD  (*(volatile uint32_t *)0xE000E014)                             
#define SYSTICK_VAL   (*(volatile uint32_t *)0xE000E018)
                                                                                       
#define SYSTICK_CLKSRC  (1 << 2)   /* use processor clock */                         
#define SYSTICK_TICKINT (1 << 1)   /* enable interrupt */                            
#define SYSTICK_ENABLE  (1 << 0)

#endif