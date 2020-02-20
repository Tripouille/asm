	global _ft_strlen
	section .text

_ft_strlen:
	push	rbp
	mov		rbp, rsp
	mov		rax, 0

while:
	cmp		byte [rdi], 0
	je		out
	inc		rax
	inc		rdi
	jmp		while

out:
	leave
	ret
