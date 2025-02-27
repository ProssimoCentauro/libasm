section .text
    global  ft_strcpy

ft_strcpy:
    mov rcx, -1

_loop:
    inc rcx
    mov al, byte[rsi + rcx]
    mov byte[rdi + rcx], al
    cmp al, 0
    jne _loop

_end:
    mov rax, rdi
    ret

section .note.GNU-stack noexec nowrite progbits
