section .text
    global _ft_strdup; char *ft_strdup(const char *s1)
    extern _ft_strlen
    extern _ft_strcpy
    extern _malloc

_ft_strdup:
    push rbp
    mov rbp, rsp
    sub rsp, 16

    mov [rsp], rdi    ; save src
    call _ft_strlen

    inc rax
    mov rdi, rax    ; len in first arg
    call _malloc

    mov rdi, rax    ; dest first arg
    mov rsi, [rsp]  ; src second
    call _ft_strcpy

    add rsp, 16
    leave
    ret