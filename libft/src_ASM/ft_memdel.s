section .text
    global _ft_memdel; void	ft_memdel(void **ap)
    extern _free

_ft_memdel:
    push rbp
    mov rbp, rsp
    sub rsp, 16

    mov [rsp], rdi
    mov rdi, [rdi]
    call _free

    mov rdi, [rsp]
    mov qword[rdi], 0x0
    
    add rsp, 16
    pop rbp
    ret