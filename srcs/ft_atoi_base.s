	global _ft_atoi_base
	extern _ft_cinstr
	section .data

	forbidden_char		db " +-", 9, 10, 11, 12, 13, 0

	section .text

next_space:
	inc		rdi
	jmp		skip_spaces

minus:
	inc		r8
	inc		rdi
	jmp		skip_signs

error:
	mov		rax, 0
	jmp		out

_ft_atoi_base:
	push	rbp
	mov		rbp, rsp
	mov		rax, 0
	mov		rcx, 0
	mov		rdx, 0
	mov		r8, 0
	mov		r9, 0

check_null:
	test	rdi, rdi
	je		out
	test	rsi, rsi
	je		out

skip_spaces:
	cmp		byte [rdi], ' '
	je		next_space
	cmp		byte [rdi], 13
	ja		skip_signs
	cmp		byte [rdi], 8
	ja		next_space

skip_signs:
	cmp		byte [rdi], '-'
	je		minus
	cmp		byte [rdi], '+'
	jne		base_is_valid
	inc		rdi
	jmp		skip_signs

base_is_valid:
	push	r8
	push	rdi

while_base_is_valid:
	cmp		byte [rsi + rcx], 0
	je		check_base_size
	push	rsi
	mov		dl, [rsi + rcx]
	mov		rdi, rdx
	lea		rsi, [rsi + rcx + 1]
	call	_ft_cinstr
	cmp		rax, 0
	jge		error
	mov		rsi, forbidden_char
	call	_ft_cinstr
	cmp		rax, 0
	jge		error
	pop		rsi
	inc		rcx
	jmp		while_base_is_valid

check_base_size:
	pop		rdi
	cmp		rcx, 3
	jl		error

convert:
	cmp		byte [rdi], 0
	je		convert_done
	push	rdi
	mov		dl, [rdi]
	mov		rdi, rdx
	call	_ft_cinstr
	cmp		rax, -1
	je		convert_done
	mov		r10, rax
	mov		rax, rcx
	mul		r9
	mov		r9, rax
	add		r9, r10
	pop		rdi
	inc		rdi
	jmp		convert

convert_done:
	mov		rax, r9
	pop		r8
	and		r8, 1
	jz		out
	neg		rax

out:
	leave
	ret
