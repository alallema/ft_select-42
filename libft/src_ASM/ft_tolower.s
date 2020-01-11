section .text
    global _ft_tolower; int tolower(int c)

_ft_tolower:
    xor rax, rax

    .ft_isupper:
        cmp rdi, 'A'
        jl .end
        cmp rdi, 'Z'
        jg .end
        add rdi, 32

    .end:
        mov rax, rdi
        ret