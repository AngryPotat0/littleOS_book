C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
CFLAGS = -g -m32 -ffreestanding -c -std=c11

OBJ = ${C_SOURCES:.c=.o}

LDFLAGS = -T link.ld -melf_i386


CC = i386-elf-gcc


os.iso: kernel.elf
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

kernel.elf: kernel/loader.o ${OBJ}
	i386-elf-ld $(LDFLAGS) $^ -o kernel.elf

run: os.iso
	bochs -f bch.txt -q


%.o: %.c
	${CC} ${CFLAGS} $< -o $@

%.o: %.s
	nasm $< -f elf -o $@

clean:
	rm -rf *.elf
	rm -rf kernel/*.o drivers/*.o
