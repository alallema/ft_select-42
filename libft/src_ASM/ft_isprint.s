%define FALSE		0
%define TRUE 		1

section .text
    global _ft_isprint; int ft_isprint(int c)

_ft_isprint:
    xor rax, rax
    cmp rdi, 32
    jl .false
    cmp rdi, 126
    jg  .false
    mov rax, TRUE
    ret

    .false:
        mov rax, FALSE
        ret