%define FALSE		0
%define TRUE 		1

section .text
    global _ft_isdigit; int ft_isdigit(int c)

_ft_isdigit:
    xor rax, rax
    cmp rdi, '0'
    jl .false
    cmp rdi, '9'
    jg .false
    mov rax, TRUE
    ret

    .false:
        mov rax, FALSE
        ret