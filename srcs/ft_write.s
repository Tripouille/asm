	global _ft_write
	section .text

_ft_write:
	push	rdi
	push	rsi
	push	rdx
	mov		rax, 0x02000004
	syscall
	pop		rdx
	pop		rsi
	pop		rdi
	ret
