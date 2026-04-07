  ENTRY(reset_handler)

  MEMORY
  {
      FLASH (rx) : ORIGIN = 0x00027000, LENGTH = 0xCD000
      RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 0x40000
  }

  SECTIONS
  {
      .text :
      {
          KEEP(*(.vectors))
          *(.text*)
          *(.rodata*)
          __etext = .;
      } > FLASH

      .data : AT(__etext)
      {
          __data_start__ = .;
          *(.data*)
          __data_end__ = .;
      } > RAM

      .bss :
      {
          __bss_start__ = .;
          *(.bss*)
          *(COMMON)
          __bss_end__ = .;
      } > RAM

      __StackTop = ORIGIN(RAM) + LENGTH(RAM);
  }