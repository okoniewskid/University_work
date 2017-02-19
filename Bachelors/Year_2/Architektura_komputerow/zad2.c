#include <stdio.h>
int main() {
	char s[] = "Abcdefg";
	char t[] = {0,0,0,0,0,0,0,0};
	asm volatile(
	".intel_syntax noprefix;" 
	"mov ecx,%0;"
	"mov ebx,%1;"
	"call przepiszznak;"
	"jmp wyjscie;"
	
	"przepiszznak:"
	"push ax;"
	"mov al,[ecx];"
	"mov [ebx],al;"
	"pop ax;"
	"ret;"
	"wyjscie:"
	".att_syntax prefix;" 
	:
	:"r"(s),"r"(t)
	:"ebx","ecx"
	);
	printf("s=%s,t=%s \n",s,t);
	return 0;
}
