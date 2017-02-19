#include <stdio.h>

int main()
{
	char z;
	
	while(z!=EOF)
	{
		z=getchar();
		printf("%c",z);
	}
	return 0;
}
