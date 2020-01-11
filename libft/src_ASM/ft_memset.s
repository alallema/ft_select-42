section .text
    global _ft_memset; void *memset(void *b, int c, size_t len)

_ft_memset:
    push rbp
    mov rbp, rsp
    sub rsp, 16

    mov rax, rsi    ; move value to register would be copied
    mov rcx, rdx    ; copy len in cx
    mov rsp, rdi

    cld             ; clear direction flag
    rep stosb       ; stores data from register to memory
    
    mov rax, rsp
    add rsp, 16
    leave
    ret