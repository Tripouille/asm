	global _ft_list_sort
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

	mov		r8, [rdi] ; r8 = reference
	cmp		r8, 0
	je		out

	mov		r10, rsi ; r10 = compare function
	mov		r12, r8   ; r12 = lower
	mov		r13, [r8 + 8] ; r13 = actual (in while)
	mov		r14, r8 ; r14 = actual prev

while:
	cmp		r13, 0
	je		post_while
	mov		rdx, [r12] ; r12 = lower ([r12] = data pointer)
	mov		rdi, [rdx] ; data (like int or not)
	mov		rdx, [r13] ; r13 = actual (in while)
	mov		rsi, [rdx] ; data
	push	r10
	call	r10
	cmp		ax, 0
	jg		save_lower
post_cmp:
	pop		r10
	mov		r14, r13
	mov		r13, [r13 + 8]
	jmp		while

post_while:
	pop		rdi
	push	rdi
	cmp		r12, [rdi]
	je		next
	; next du prev = lower next
	mov		rdx, [r12 + 8]
	mov		[r15 + 8], rdx
	; lower next = debut de list
	mov		rdx, [rdi]
	mov		[r12 + 8], rdx
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
