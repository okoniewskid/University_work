#include <stdio.h>
int newton(int n, int k)
	{
if (k==0 || k>=n) return 1;
else return newton(n-1,k-1)+newton(n-1,k);
	}
int main()
	{
	int n,k;
	printf("Podaj n: ");
	scanf("%d",&n);
	printf("Podaj k: ");
	scanf("%d",&k);
	printf("%d\n",newton(n,k));
	getchar();
	return 0;
	}
