#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j = 0;
	int a = 1;
	int tab[4][4];
	
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			tab[i][j] = a++;
		}
	}
	
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf(" %d ", tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			printf(" %d ", tab[j][i]);
		}
		printf("\n");
	}
	
	return 0;
}
