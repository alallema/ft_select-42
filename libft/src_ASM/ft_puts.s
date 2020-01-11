%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

section .data
    .null db "(null)", 0
    .new_line db 10, 0

section .text
    global _ft_puts; int    ft_puts(const char *s)
    extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp
    sub rsp, 16

   cmp rdi, 0
   je .null_return
   jmp .print

    .null_return:
        add rdx, 1
        lea rdi, [rel .null]

    .print:
        mov [rbp - 8], rdi
        call _ft_strlen
        mov rsi, [rbp - 8]

    	mov rdx, rax
        mov rdi, STDOUT
    	mov rax, MACH_SYSCALL(WRITE)
    	syscall
        mov [rbp - 8], rax

        lea rsi, [rel .new_line]
        mov rdx, 1
        mov rdi, STDOUT
        mov rax, MACH_SYSCALL(WRITE)
    	syscall
        jb .error

    .return:
        mov rax, 10
        jmp .end

    .error:
        mov rax, 0

    .end:
        add rsp, 16
        leave
        ret