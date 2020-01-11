section .text
    global _ft_bzero; void	ft_bzero(void *s, size_t n)

_ft_bzero:
	xor rax, rax    ; put rax at 0
	mov rcx, rsi    ; move len to cx
    
    cld             ; clear flag
	rep stosb

    ret