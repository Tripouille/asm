	global _ft_write
	section .text

_ft_write:
	push	rdi
	push	rsi
	push	rdx
	push	rax
	mov		rax, 0x02000004
	syscall
	pop		rax
	pop		rdx
	pop		rsi
	pop		rdi
	ret
