section .text
    global ft_strcmp

ft_strcmp:
    mov rcx, -1

_loop:
    inc rcx
    mov al, byte[rdi + rcx]
    cmp al, 0
    je _end
    cmp al, byte[rsi + rcx]
    je _loop

_end:
    sub al, byte[rsi + rcx]
    movsx rax, al
    ret

section .note.GNU-stack noexec nowrite progbits
