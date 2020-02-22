	global _ft_list_remove_if
	extern _free
	extern _show_list ;a enlever
	section .text

free:
	;link prev with next.
	pop		rdi


	push	rdi
	mov		rdi, [rdi]
	sub		rsp, 8
	call	_show_list
	add		rsp, 8
	pop		rdi


	mov		r15, [rdi]
	mov		r13, [r15 + 8]
	mov		[rdi], r13
	;free data with free_fct.
	push	rdi
	mov		rdi, [r15]
	call	r14
	jmp		next2
	;free the elem
	mov		rdi, r15
	call	_free
	jmp		next2
	;don't change rdi
	pop		rdi
	mov		r12, rdi
	push	rdi

_ft_list_remove_if:
	push	rbp
	mov		rbp, rsp
	push	r12
	push	r13
	push	r14
	push	r15
	push	rdx
	push	rsi
	push	rdi

	cmp		qword [rdi], 0
	je		out

	mov		r14, rcx
	mov		rdi, [rdi] ; get elem
	lea		r12, [rdi + 8] ; save the next elem
	mov		rdi, [rdi] ; get data pointer
	call	rdx
	cmp		ax, 0
	je		free

next2:
	pop		rdi
	pop		rsi
	pop		rdx
	mov		rcx, r14
	mov		rdi, r12 ; copy the next in rdi
	call	_ft_list_remove_if

out:
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	leave
	ret
