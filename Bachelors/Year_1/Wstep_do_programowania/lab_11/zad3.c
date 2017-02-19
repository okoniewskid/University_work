#include <stdio.h>
#include <math.h>
double newton(double n, double k)
	{
	if (k==0 || k>=n) return 1;
	else return newton(n-1,k-1)+newton(n-1,k);
	}
double Cumulative(double n,double k,double p)
	{
	double i;
	if (p==0 || k==0 || k>=n) return 1;
	double wynik = 0;
	for(i=0;i<k;i++)
	{
	wynik = wynik + pow(p,k)*pow(1-p,n-k)*newton(n,k);
	}
	return wynik;
}

int main()
	{
	double n,k,p;
	double i=0;

	printf("Podaj n: ");
	scanf("%lf",&n);
	printf("Podaj k: ");
	scanf("%lf",&k);
	printf("Podaj p: ");
	scanf("%lf",&p);
	printf("%lf\n",Cumulative(n,k,p));
	
	getchar();
	return 0;
	}

