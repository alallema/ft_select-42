section .text
    global _ft_strcat; char *ft_strcat(char *restrict s1, const char *restrict s2)
    extern _printf
    extern _ft_strcpy
    extern _ft_strlen
    extern _ft_puts

_ft_strcat:
    push rbp
    mov rbp, rsp
    sub rsp, 16

    mov [rsp], rdi

    call _ft_strlen

    mov rdi, [rsp]

    add rdi, rax
    call _ft_strcpy

    mov rax, [rsp]
    add rsp, 16
    leave
    ret