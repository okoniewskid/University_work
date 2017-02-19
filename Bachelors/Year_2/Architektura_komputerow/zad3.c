int main(){
	char *s = "Abcaabcaaax";
	short int y;
asm volatile(
	".intel_syntax noprefix;"
	"mov ecx,%0;"
	"mov edx,2;"
	"mov ebx,1;"
	"mov eax,4;"
	"int 0x80;"
	".att_syntax prefix;"
	: 
	:"r"(s)
	:"eax","ebx","ecx","edx"
	);
	printf("y=%hd \n"y);
	return 0;
}
