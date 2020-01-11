section .text
    global _ft_memalloc; void	*ft_memalloc(size_t size)
    extern _ft_memset
    extern _malloc

_ft_memalloc:
    push rbp
    mov rbp, rsp
    sub rsp, 16

    mov [rsp], rdi    ; save src
    call _malloc

	mov rdi, rax
	mov rsi, 0
	mov rdx, [rsp]
	call _ft_memset

    add rsp, 16
    leave
    ret
