	global _ft_strcmp
	section .text

_ft_strcmp:
	push	rdi
	push	rsi

while:
	mov		r8, [rdi]
	mov		r9, [rsi]
	cmp		r8b, r9b
	jne		out
	inc		rdi
	inc		rsi
	jmp		while

out:
	mov		rax, -1
	mov		ax, 252
	;sub		r8b, r9b
	;mov		ax, r8w
	;sub		al, r9b
	;mov		al, 15
	;sub		al, 10
	pop		rsi
	pop		rdi
	ret
