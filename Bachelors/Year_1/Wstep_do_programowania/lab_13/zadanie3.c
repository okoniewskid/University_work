#include <stdio.h>
#include <math.h>

int bit_liczby(int numer, int liczba)
{
	int n = 0;
	int pom = liczba & (int)pow(2,numer);
	int pom2 = sizeof(liczba)*8
	if(n <= pom2)
	{
		n = n+1;
		if (pom==0) return printf("0");
		else 		return printf("1");
	}
}

int main()
{
int numer=0;
int liczba;
	scanf("%d",&liczba);	

	printf("%d",bit_liczby(numer,liczba));
	
	return 0;
}


