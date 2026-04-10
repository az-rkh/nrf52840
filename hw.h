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

/* GPIO port 0 */
#define P0_BASE    0x50000000
#define P0_OUT     (*(volatile uint32_t *)(P0_BASE + 0x504))
#define P0_OUTSET  (*(volatile uint32_t *)(P0_BASE + 0x508))
#define P0_OUTCLR  (*(volatile uint32_t *)(P0_BASE + 0x50C))
#define P0_DIR     (*(volatile uint32_t *)(P0_BASE + 0x514))

#define LED_BLUE_PIN  8   /* P0.08 */

#endif