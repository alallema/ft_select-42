%define FALSE		0
%define TRUE 		1

section .text
    global _ft_isalnum; int ft_isalnum(int c)
    extern _ft_isalpha
    extern _ft_isdigit

_ft_isalnum:
    call _ft_isalpha
    cmp rax, TRUE
    je .true

    call _ft_isdigit
    cmp rax, TRUE
    je .true
    mov rax, FALSE
    ret

    .true:
        mov rax, TRUE
        ret