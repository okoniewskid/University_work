#include <stdio.h> 

 
 int main()
{
int m = 1;
int n;
scanf("%d",&n);

int suma = 0;
int i;
int j;

for (i = 1; i <= n; i++)
{
	for (j = 0; j < i; j++)
	{
		m = m*i;
	}
	suma = suma +m;
	m = 1;
}

printf("%d", suma);
printf("\n");

return 0;

}
