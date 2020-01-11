section .text
    global _ft_memcpy; void *memcpy(void *restrict dst, const void *restrict src, size_t n)

_ft_memcpy:
    mov rax, rdi    ; save dest

    cmp rdx, 0      ; if len == 0
    je .end

    mov rcx, rdx    ; copy len in cx

    cld             ; clear direction flag
    rep movsb       ; mov data
    jmp .end

    .end:
        ret