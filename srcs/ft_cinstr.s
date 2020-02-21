	global _ft_cinstr
	section .text

_ft_cinstr:
	push	rbp
	mov		rbp, rsp
	mov		rax, 0
	mov		r8, 0

while:
	cmp		byte [rsi + rax], 0
	je		not_found
	mov		r8b, [rsi + rax]
	cmp		rdi, r8
	je		out
	inc		rax
	jmp		while

not_found:
	mov		rax, -1

out:
	leave
	ret
