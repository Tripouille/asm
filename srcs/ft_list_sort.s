	global _ft_list_sort
	extern _pouet
	section .text


save_lower:
	mov		r12, r13
	mov		r15, r14 ; r15 = lower prev
	jmp		post_cmp

_ft_list_sort:
	push	rbp
	mov		rbp, rsp
	push	r12
	push	r13
	push	r14
	push	r15
	push	rdi

	;rdi == 0 ?
	mov		r8, [rdi] ; r8 = actual
	mov		rdi, 0
	mov		r10, rsi
	mov		rsi, 0
	mov		r12, r8   ; r12 = lower
	cmp		r8, 0
	je		out
	mov		r13, [r8 + 8] ; r13 = elem to compare to
	mov		r14, r8

while:
	cmp		r13, 0
	je		post_while
	mov		rdx, [r12]
	mov		rdi, [rdx]
	mov		rdx, [r13]
	mov		rsi, [rdx]
	push	r8
	push	r10
	;sub		rsp, 8
	mov		rax, 0
	call	r10
	;add		rsp, 8
	cmp		ax, 0
	jg		save_lower

post_cmp:
	mov		r14, r13 ; r14 = prev de actual
	pop		r10
	pop		r8
	mov		r13, [r13 + 8]
	jmp		while
post_while:
	pop		rdi
	push	rdi
	cmp		r12, r8
	je		next
	; next du prev = lower next
	mov		rdx, [r12 + 8]
	mov		[r15 + 8], rdx
	; lower next = debut de list
	mov		[r12 + 8], r8
	; debut de list = lower
	mov		[rdi], r12

next:
	mov		r8, [rdi]
	lea		rdi, [r8 + 8]
	mov		rsi, r10
	call	_ft_list_sort

out:
	pop		rdi
	pop		r15
	pop		r14
	pop		r13
	pop		r12
	leave
	ret
