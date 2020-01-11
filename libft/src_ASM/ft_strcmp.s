section .text
	global _ft_strcmp; int	ft_strcmp(const char *s1, const char *s2)
	extern _ft_strlen

_ft_strcmp:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	cmp byte[rsi], 0
	je .end

	mov r8, rdi		; save s1
	mov r9, rsi		; save s2

	call _ft_strlen
	mov rdi, rsi
	mov rdx, rax	; save len

	call _ft_strlen

	mov rdi, r8		; restore s1
	mov rsi, r9

	cmp rax, rdx
	jle .shortestone
	jmp .shortesttwo

	.shortestone:
		mov rcx, rdx

	.shortesttwo:
		mov rcx, rax

	cld
	rep cmpsb

	dec rdi

	.end:
		movzx rdi, byte[rdi]
		dec rsi
		movzx rsi, byte[rsi]

		sub rsi, rdi
		mov rax, rsi
		not rax
		inc rax

		add rsp, 16
		leave
		ret
