	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
	section .text

_ft_strdup:
	push	rbp
	mov		rbp, rsp

	push	rdi
	call	_ft_strlen
	mov		rdi, rax
	inc		rdi
	sub		rsp, 8
	call	_malloc
	add		rsp, 8
	pop		rsi
	mov		rdi, rax
	call	_ft_strcpy

	leave
	ret
