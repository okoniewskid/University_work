#include <stdio.h>

int main()
{
	int n = 3;
	int m = 3;
	int i;
	int j;
	
	for (i = 1; i < n+1; i++)
	{
		for (j = 1; j < n+m; j++)
		{
			printf("*");
		}
		m++;
		printf("\n");
	}
	
	return 0;
}
