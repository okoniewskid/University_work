#include <stdio.h>

int main(){

asm volatile(
	".intel_syntax noprefix;"
	
	".att_syntax prefix;"
	:"=r"() 
	:"r"()
	:
	);
	printf(" ",);
	return 0;
}
