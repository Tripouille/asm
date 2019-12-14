	extern _ft_strlen
	global _ft_strcpy
	section .text

_ft_strcpy:
	push	rdi
	mov		rdi, rsi
	call	_ft_strlen
	pop		rdi
	mov		rcx, rax
	inc		rcx
	mov		rax, rdi
	rep		movsb
	ret
