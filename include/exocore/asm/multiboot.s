MULTIBOOT_ARCHITECTURE_I386 equ 0
MULTIBOOT_ARCHITECTURE_MIPS equ 4

MULTIBOOT_TAG_END equ 0
MULTIBOOT_TAG_INFORMATION_REQUEST equ 1
MULTIBOOT_TAG_ADDRESS equ 2
MULTIBOOT_TAG_ENTRY_ADDRESS equ 3
MULTIBOOT_TAG_CONSOLE_FLAGS equ 4
MULTIBOOT_TAG_FRAMEBUFFER equ 5
MULTIBOOT_TAG_MODULE_ALIGNMENT equ 6

MULTIBOOT_MAGIC equ 0xe85250d6 ; Multiboot magic number.
MULTIBOOT_ARCHITECTURE equ MULTIBOOT_ARCHITECTURE_I386 ; Multiboot architecture identifier.
