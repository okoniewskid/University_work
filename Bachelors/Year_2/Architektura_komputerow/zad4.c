#include <stdio.h>
int main(){
	char *s = "AbcaabcAahaaax";
	char t[] = {0};
	//short int y;
asm volatile(
	".intel_syntax noprefix;"

	"mov ebx,%0;"
	"mov cx,0;"
	"petla:"
	"mov al,[ebx];" 
	"cmp al,0;"
	"jz koniec;"
	"cmp al,'a';"
	"jnz niea;"
	"inc cx;"
	"niea:"
	"inc ebx;"
	"jmp petla;"
	"koniec:"
	
	"mov ebx,%1;"
	"add cl,'0';"
	"mov [ebx],cl;"
	"mov ecx,%1;"
	"mov edx,1;"
	"mov ebx,1;"
	"mov eax,4;"
	"int 0x80;"
	
	".att_syntax prefix;"
	:
	:"r"(s),"r"(t)
	:"eax","ebx","ecx","edx"
	);
	return 0;
}
