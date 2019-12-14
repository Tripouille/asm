	global _ft_strlen
	section .text

_ft_strlen:
	mov		rax, 0

while:
	cmp		byte [rdi], 0
	je		whileDone
	inc		rax
	inc		rdi
	jmp		while

whileDone:
	ret
