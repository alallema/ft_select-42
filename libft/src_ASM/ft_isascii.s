%define FALSE		0
%define TRUE 		1

section .text
    global _ft_isascii; int ft_isascii(int c)

_ft_isascii:
    xor rax, rax
    cmp rdi, 0
    jl .false
    cmp rdi, 127
    jg  .false
    mov rax, TRUE
    ret

    .false:
        mov rax, FALSE
        ret