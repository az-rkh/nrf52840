#ifndef HW_H
#define HW_H

#define SCB_ICSR (*(volatile unsigned int *) 0xE000ED04)
#define PENDSV_SET (1 << 28)

#endif