section .text
    global _ft_toupper; int ft_toupper(int c)

_ft_toupper:
    xor rax, rax

    .ft_islower:
        cmp rdi, 'a'
        jl .end
        cmp rdi, 'z'
        jg .end
        sub rdi, 32

    .end:
        mov rax, rdi
        ret