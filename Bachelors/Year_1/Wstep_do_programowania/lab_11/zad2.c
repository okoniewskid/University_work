#include <stdio.h>
#include <math.h>
double newton(double n, double k)
	{
	if (k==0 || k>=n) return 1;
	else return newton(n-1,k-1)+newton(n-1,k);
	}
double praw(double n,double k,double p)
	{
	if (p==0 || k==0 || k>=n) return 1;
	else return pow(p,k)*pow(1-p,n-k)*newton(n,k);
	}
int main()
	{
	double n,k,p;

	printf("Podaj n: ");
	scanf("%lf",&n);
	printf("Podaj k: ");
	scanf("%lf",&k);
	printf("Podaj p: ");
	scanf("%lf",&p);
	printf("%lf\n",praw(n,k,p));
	
	getchar();
	return 0;
	}
