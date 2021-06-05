# 使用GRUB

我们使用GRUB来引导我们的操作系统。

首先创建一个文件夹，其内部结构如下：

	littleOS
	|--iso
	| |-- boot
	| | |-- grub
	| | | |-- menu.lst
	| | | |-- stage2_eltorito
	|--kernel
	| |-- loader.s
	|--bch.txt
	|--link.ld
	|--Makefile

 

其中menu.lst2为GRUB的配置文件，写入以下内容：

    default=0
    timeout=0
    
    title os
    kernel /boot/kernel.elf

我们指定默认启动项为0（按照开机选择界面的顺序对应），进入默认启动项的等待时间为0，也就是开机直接进入开机选择界面的第一个操作系统，title就是操作系统的标题，显示在开机选择界面上，这个可以随便写，再下面一行就是操作系统程序的位置

然后配置bochs，在bch.txt中写入如下内容：

    megs:       32
    display_library: sdl2
    romimage:     file=/usr/share/bochs/BIOS-bochs-latest
    vgaromimage:   file=/usr/share/bochs/VGABIOS-lgpl-latest
    ata0-master:   type=cdrom, path=os.iso, status=inserted
    boot:       cdrom
    log:       bochslog.txt
    clock:      sync=realtime, time0=local
    cpu:       count=1, ips=1000000
    magic_break: enabled = 1

现在，我们就可以编写我们的操作系统代码了，kernel文件夹下放置我们的操作系统的代码，现在只有一个最基本的loader.s，写入代码：

```assembly
global loader                   ; the entry symbol for ELF

MAGIC_NUMBER equ 0x1BADB002     ; magic number
FLAGS        equ 0x0            ; multiboot flags
CHECKSUM     equ -MAGIC_NUMBER  ; checksum

KERNEL_STACK_SIZE equ 8192      ; size of stack

section .__mbHeader
align 4
    dd MAGIC_NUMBER
    dd FLAGS
    dd CHECKSUM

section .bss
align 4                         ; align at 4 bytes
kernel_stack:
    resb KERNEL_STACK_SIZE      ; reserve stack for the kernel

section .text:
align 4

loader:
    mov eax, 0xAABBCCDD

.loop:
    jmp .loop
```

在解释上面这一堆代码之前，我们先介绍以下GRUB的一些“规定”

