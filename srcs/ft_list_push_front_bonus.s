	global _ft_list_push_front
	extern _ft_create_elem
	section .text

_ft_list_push_front:
	push	rbp
	mov		rbp, rsp

	push	rdi
	mov		rdi, rsi
	call	_ft_create_elem
	pop		rdi
	mov		r8, [rdi]
	mov		[rax + 8], r8
	mov		[rdi], rax

	leave
	ret
