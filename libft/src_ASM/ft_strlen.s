section .text
    global _ft_strlen; size_t   ft_strlen(const char *s)

_ft_strlen:
    xor rax, rax        ; clean rax
    mov rcx, -1         ; set -1 because it's stop at 0
    cld                 ; direction flag
    repne scasb         ; repeat until flag -> 0
    not rcx             ; inverse sign
    sub rcx, 1          ; minus 1 because set -1 instead 0
    mov rax, rcx
    ret

; without repeat string operation
;_ft_strlen:
;    xor rax, rax
;    .loop:
;        cmp byte[rdi + rax], 0
;        jz .end
;        inc rax
;        jmp .loop
;    .end:
;        rets