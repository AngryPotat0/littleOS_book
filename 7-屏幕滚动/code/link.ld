ENTRY(loader)
OUTPUT_FORMAT(elf32-i386)
SECTIONS {
    . = 0x01000000;

    .__mbHeader : {
        *(.__mbHeader)
    }
    .text ALIGN (0x1000):
    {
        *(.text)
        *(.rodata*)
    }

    .data ALIGN (0x1000):
    {
        *(.data)
    }

    .bss ALIGN (0x1000):
    {
        *(COMMON)
        *(.bss)
    }
}
