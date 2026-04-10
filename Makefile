CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS  = -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=soft \
          -Os -Wall \
          -ffreestanding -nostdlib

SRCS    = main.c task.c sched.c startup.s switch.s
TARGET  = kernel

all: $(TARGET).uf2

$(TARGET).elf: $(SRCS)
	$(CC) $(CFLAGS) -T linker.ld -o $@ $(SRCS)

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@

$(TARGET).uf2: $(TARGET).bin
	python3 uf2conv.py $< --base 0x00027000 --family 0xADA52840 -o $@

clean:
	rm -f $(TARGET).elf $(TARGET).bin $(TARGET).uf2
