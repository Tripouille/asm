	extern _ft_strlen
	global _ft_strcpy
	section .text

_ft_strcpy:
	push	rdi
	mov		rdi, rsi		;move rsi in rdi for strlen.
	call	_ft_strlen
	pop		rdi
	mov		rcx, rax		;copy the return of strlen in rcx.
	inc		rcx				;+1 for '\0'.
	mov		rax, rdi
	rep		movsb			;copy of rsi in rdi, rcx times.
	ret
