	global _ft_read
	extern ___error
	section .text

error:
	mov		r8, rax
	call ___error
	mov [rax], r8
	jmp end

_ft_read:
	push	rdi
	push	rsi
	push	rdx
	mov		rax, 0x02000003
	syscall
	jc error

end:
	pop		rdx
	pop		rsi
	pop		rdi
	ret
