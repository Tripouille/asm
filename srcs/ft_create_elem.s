	global _ft_create_elem
	extern _malloc
	section .text

_ft_create_elem:
	push	rbp
	mov		rbp, rsp

	push	rdi
	mov		rdi, 16
	call	_malloc
	pop		rdi
	mov		[rax], rdi
	mov		qword [rax + 8], 0

	leave
	ret
