#include <stdio.h>

int main()
{
	int n = 20;
	int i;
	int j;
	
	for (i = 1; i < n+1; i++)
	{
		for (j = 1; j < n+1; j++)
		{
			printf("0 ");
		}
		printf("\n");
	}
	
	return 0;
}
