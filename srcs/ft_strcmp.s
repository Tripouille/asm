	global _ft_strcmp
	section .text

_ft_strcmp:
	push	rdi
	push	rsi
	mov		r8, 0
	mov		r9, 0

while:
	mov		r8b, [rdi]
	mov		r9b, [rsi]
	cmp		r8, r9
	jne		out
	test	r8, r8		;Set ZF=1 if r8 == 0
	je		out
	inc		rdi
	inc		rsi
	jmp		while

out:
	mov		rax, r8
	sub		rax, r9
	pop		rsi
	pop		rdi
	ret
