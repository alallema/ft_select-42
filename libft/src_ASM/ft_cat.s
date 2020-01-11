%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define READ				3
%define WRITE				4

section .bss
buff:
	.data resb 4096
	.len equ $ - buff.data

section .text
    global _ft_cat; void    ft_cat(int fd)
    extern _ft_bzero

_ft_cat:
    push rbp
    mov rbp, rsp
    sub rsp, 16

    mov [rsp], rdi

    .read:
        mov rdi, [rsp]
        mov rsi, buff.data
        mov rdx, buff.len
	    mov rax, MACH_SYSCALL(READ)
	    syscall

        jb .end
		cmp rax, 0
		je .end

        mov rdi, STDOUT
        lea rsi, [rel buff.data]
	    mov rdx, rax
	    mov rax, MACH_SYSCALL(WRITE)
        syscall

        jb .end
        jmp .read

    .end:
        add rsp, 16
        leave
        ret