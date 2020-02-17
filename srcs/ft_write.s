	global _ft_write
	extern ___error
	section .text

error:
	mov		r8, rax
	call ___error
	mov [rax], r8
	jmp end

_ft_write:
	push	rdi
	push	rsi
	push	rdx
	mov		rax, 0x02000004
	syscall
	jc error

end:
	pop		rdx
	pop		rsi
	pop		rdi
	ret
