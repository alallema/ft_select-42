%define FALSE		0
%define TRUE 		1

section .text
    global _ft_isalpha; int ft_isalpha(int c)

_ft_isalpha:
    xor rax, rax

    .ft_isupper:
        cmp rdi, 'A'
        jl .false
        cmp rdi, 'Z'
        jle .true

    .ft_islower:
        cmp rdi, 'a'
        jl .false
        cmp rdi, 'z'
        jle .true

    .false:
        mov rax, FALSE
        ret
    
    .true:
        mov rax, TRUE
        ret