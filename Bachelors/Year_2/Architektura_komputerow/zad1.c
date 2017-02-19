#include <stdio.h>
int main() {
	char s[] = "Abcdefg";
	short int y;
	
	asm volatile(
	".intel_syntax noprefix;" 
	
	"mov ecx,%1;"
	"call zliczznaki;"
	"mov %0,ax;"
	"jmp wyjscie;"
	
	"zliczznaki:"
	"push bx;"
	"xor ax,ax;"
	"petla:"
	"mov bl,[ecx];"
	"cmp bl,0;"
	"jz koniec;"
	"inc ax;"
	"inc ecx;"
	"jmp petla;"
	"koniec:"
	"pop bx;"
	"ret;"
	"wyjscie:"
	"mov %0,ax;"
	".att_syntax prefix;" 
	:"=r"(y) 
	:"r"(s) 
	:"ecx","ax","bx"
	);
	printf("s=%s,y=%hd \n",s,y);
	return 0;
}

