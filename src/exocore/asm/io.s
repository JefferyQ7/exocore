section .text

global io_read_ui8

align 8
io_read_ui8:

    mov rdx, rdi ; Port is the first argument.

    ; Read a byte from the port in dx.
    in al, dx

    ret

global io_read_ui16

align 8
io_read_ui16:

    mov rdx, rdi ; Port is the first argument.

    ; Read a word from the port in dx.
    in ax, dx

    ret

global io_read_ui32

align 8
io_read_ui32:

    mov rdx, rdi ; Port is the first argument.

    ; Read a dword from the port in dx.
    in eax, dx

    ret

global io_write_ui8

align 8
io_write_ui8:

    mov rdx, rdi ; Port is the first argument.
    mov eax, esi ; Value is the second argument.

    ; Write a byte to the port in dx.
    out dx, al

    ret

global io_write_ui16

align 8
io_write_ui16:

    mov rdx, rdi ; Port is the first argument.
    mov eax, esi ; Value is the second argument.

    ; Write a word to the port in dx.
    out dx, ax

    ret

global io_write_ui32

align 8
io_write_ui32:

    mov rdx, rdi ; Port is the first argument.
    mov eax, esi ; Value is the second argument.

    ; Write a dword to the port in dx.
    out dx, eax

    ret

global io_wait

align 8
io_wait:

    ; We assume the 0x80 port to be free.
    out 0x80, al

    ret
