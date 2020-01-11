section .text
    global _ft_atoi; int	ft_atoi(const char *str)

_ft_atoi:
	push rbp
	mov rbp, rsp
    sub rsp, 16

	xor rax, rax
	xor rsp, rsp
	mov rsp, 1
	.begin:
		cmp byte[rdi], 32
		je .loop
		cmp byte[rdi], 9
		jl .sign
		cmp byte[rdi], 13
		jg .sign
		jmp .loop

	.loop:
		inc rdi
		jmp .begin

	.sign:
		cmp byte[rdi], 45
		je .sign_neg
		cmp byte[rdi], 43
		je .sign_pos
		jmp .atoi

	.sign_neg:
		mov rsp, -1

	.sign_pos:
		inc rdi

	.atoi:
		cmp byte[rdi], 0
		je .end
		cmp byte[rdi], 48
		jl .end
		cmp byte[rdi], 57
		jg .end
		mov rcx, 10
		mul rcx
		movzx rcx, byte[rdi]
		add rax, rcx
		sub rax, 48
		inc rdi
		jmp .atoi

	.end:
		mov rcx, rsp
		mul rcx
		add rsp, 16
		leave
		ret
