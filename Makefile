OBJECTS = loader.o kernel/kernel.o kernel/framebuffer.o kernel/io.o kernel/serial.o
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
		 -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf iso/boot/grub/stage2_eltorito os.iso

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

os.iso:
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R                              \
                -b boot/grub/stage2_eltorito    \
                -no-emul-boot                   \
                -boot-load-size 4               \
                -A os                           \
                -input-charset utf8             \
                -quiet                          \
                -boot-info-table                \
                -o os.iso                       \
                iso

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

iso/boot/grub/stage2_eltorito:
	mkdir -p iso/boot/grub
	cp stage2_eltorito iso/boot/grub/
	cp menu.lst iso/boot/grub/

run:
	bochs -f bochsrc.txt -q

clean:
	-rm -rf *.o kernel/*.o kernel.elf os.iso iso bochslog.txt com1.out