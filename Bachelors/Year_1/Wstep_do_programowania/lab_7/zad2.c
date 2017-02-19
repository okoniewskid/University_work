#include <stdio.h>
#include <math.h>
int newton(int n, int k)
	{
	if (k==0 || k>=n) return 1;
	else return newton(n-1,k-1)+newton(n-1,k);
	}
double praw(double n,double k,double p)
	{
	if (p==0 || k==0 || k>=n) return 1;
	else return pow(p,n,k)*newton(n,k);
	}
int main()
	{
	int n,k;
	printf("Podaj n: ");
	scanf("%d",&n);
	printf("Podaj k: ");
	scanf("%d",&k);
	printf("Podaj p: ");
	scanf("%d",&p);
	printf("%d\n",praw(n,k,p));
	getchar();
	return 0;
	}
