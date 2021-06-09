extern kmain
global loader                   ; the entry symbol for ELF

MAGIC_NUMBER equ 0x1BADB002     ; magic number
FLAGS        equ 0x0            ; multiboot flags
CHECKSUM     equ -MAGIC_NUMBER  ; checksum

KERNEL_STACK_SIZE equ 8192      ; size of stack

section .__mbHeader
align 0x4
	dd MAGIC_NUMBER             ; write the magic number to the machine code,
    dd FLAGS                    ; the flags,
    dd CHECKSUM                 ; and the checksum

section .bss
align 4                         ; align at 4 bytes
kernel_stack:
    resb KERNEL_STACK_SIZE      ; reserve stack for the kernel

section .text:
align 4

loader:
    call kmain

.loop:
    jmp .loop