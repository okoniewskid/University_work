.intel_syntax noprefix
.global _start
.text

-start:	mov eax,1
	mov ebx,1
	mov ecx,offset msg
	mov edx,offset dlugosc
	int 0x80
	ret
	.data

msg:	.ascii "Hello, world"
	.equ	dlugosc,$-msg