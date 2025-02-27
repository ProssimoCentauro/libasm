section .text
    global ft_strlen

ft_strlen:
    mov rax, -1

_loop:
    inc rax
    cmp byte[rdi + rax], 0
    jne _loop

_end:
    ret

section .note.GNU-stack noexec nowrite progbits
