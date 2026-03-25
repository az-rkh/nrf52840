ENTRY(reset_handler)

MEMORY
{
    FLASH (rx): ORIGIN = 0x00000000, LENGTH = 1024K
    SRAM (rwx): ORIGIN = 0x20000000, LENGTH = 256K
}



SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
    }
}