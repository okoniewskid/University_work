#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j = 0;
	int a = 1;
	int n = 3;
	int tab[3][3];
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(a == n)
			{
				tab[i][j] = a;
				a=1;
			}
			else
			{
			tab[i][j] = a++;
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j <= n; j++)
		{
			printf(" %d ", tab[i][j]);
		}
		printf("\n");
	}
	return 0;
}
