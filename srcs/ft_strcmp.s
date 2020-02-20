	global _ft_strcmp
	section .text

_ft_strcmp:
	push	rbp
	mov		rbp, rsp
	mov		r8, 0

while:
	mov		r8b, [rdi]
	cmp		r8b, [rsi]
	jne		out
	test	r8, r8		;Set ZF=1 if r8 == 0 test = and
	je		out
	inc		rdi
	inc		rsi
	jmp		while

out:
	mov		rax, 0
	mov		al, r8b
	mov		r9, 0
	mov		r9b, [rsi]
	sub		rax, r9
	leave
	ret
