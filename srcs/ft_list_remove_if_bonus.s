	global _ft_list_remove_if
	extern _free
	section .text

remove_elem:
	pop		rdi ; restore rdi
	push	rdi

	;link prev to next
	mov		r12, [rdi]
	push	r12
	mov		r12, [r12 + 8]
	mov		[rdi], r12
	pop		r12 ; restore elem in r12

	;free data pointer
	mov		rdi, [r12]
	call	r13 ; free function
	;free elem
	mov		rdi, r12
	call	_free
	pop		rdi
	jmp		post_compare


_ft_list_remove_if:
	push	rbp
	mov		rbp, rsp

	;End the recursion
	cmp		qword [rdi], 0
	je		out

	push	r12 ;tmp
	push	r13 ;free function
	push	rdx
	push	rcx
	push	rsi
	push	rdi

	mov		r13, rcx
	;Call compare function
	mov		rdi, [rdi] ; get elem
	mov		rdi, [rdi] ; get data pointer

	mov		r12, rsp ; save rsp
	and		rsp, -16
	call	rdx
	mov		rsp, r12
	cmp		ax, 0
	je		remove_elem
	;if not remove elem move rdi to the pointer on the next elem
	pop		rdi
	mov		rdi, [rdi]
	lea		rdi, [rdi + 8]

post_compare:
	;actualize rdi
	pop		rsi
	pop		rcx
	pop		rdx

	call _ft_list_remove_if

	pop		r13
	pop		r12

out:
	leave
	ret
