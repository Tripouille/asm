	global _ft_list_size
	section .text

_ft_list_size:
	push	rbp
	mov		rbp, rsp
	mov		rax, 0

while:
	cmp		qword rdi, 0
	je		out
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		while

out:
	leave
	ret
