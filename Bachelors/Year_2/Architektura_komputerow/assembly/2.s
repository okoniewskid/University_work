	.intel_syntax noprefix
	.global _start
	.text
	
_start:	mov ebp,esp
	mov eax,4
	mov ebx,1
	mov ecx,[ebp+8]
	mov edx,5
	int 0x80
	mov eax,1
	mov ebx,0
	int 0x80