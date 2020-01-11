section .text
    global _ft_strcpy; char *ft_strcpy(char * dst, const char * src)

_ft_strcpy:
    mov rax, rdi            ; save dest

    cmp rsi, 0
    je .end

    .loop:
        cld                 ; clear direction flag
        movsb               ; mov data
        cmp byte[rsi], 0
        je .end
        jmp .loop

    .end:
        mov byte[rdi], 0
        ret