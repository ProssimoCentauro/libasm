section .text
    global ft_read

ft_read:
    mov rax, 0
    syscall
    ret

section .note.GNU-stack noexec nowrite progbits
