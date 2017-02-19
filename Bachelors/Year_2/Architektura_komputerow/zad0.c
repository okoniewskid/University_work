#include <stdio.h>
int main() {
	short int x=1;
	short int y=0;
	
	asm volatile(
	".intel_syntax noprefix;" //przejscie na skladnie intel
	"mov ax,%1;"  // % -> odwolanie do zmeinnej
	"mov cx,100;"
	"mov bx,0;"
	"petla:"
	"add bx,ax;"
	"sub cx,1;"
	"jnz petla;"
	"mov %0,bx;"
	".att_syntax prefix;" //przejscie na skladnie domyslna att
	:"=r"(y) //output r -> register/rejestr, =r -> wpisanie do wartosci rejestru
	:"r"(x) //input
	:"ax","bx","cx" //jakie rejestry zmodyfikujemy
	);
	printf("x=%hd,y=%hd ",x,y);
	return 0;
}
