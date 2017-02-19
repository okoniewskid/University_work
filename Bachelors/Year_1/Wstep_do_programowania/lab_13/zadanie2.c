#include <stdio.h>
#include <math.h>

int bit_liczby(int numer, int liczba)
{
		int pom = liczba & (int)pow(2,numer);
		if (pom==0) return 0;
		else return 1;
	
}

int main()
{
int numer, liczba;
	scanf("%d",&liczba);	
	scanf("%d",&numer);
	printf("%d",bit_liczby(numer,liczba));
	
	return 0;
}

