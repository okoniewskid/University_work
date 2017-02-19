#include <stdio.h>
int main()
{
	int n,i,j;
	n = 50;
	int tab[n];
	for(i = 0; i < n; ++i)
		{
			printf("podaj %d element\n", i);
			scanf("%d", &tab[i]);
			if(tab[i]<0){break;}
		}
	for(j = i; j > 0; --j)
		{
			printf("%d\n", tab[j]);
		}
	return 0;
}
