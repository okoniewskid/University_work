#include <stdio.h>

int main()
{
float suma;
float n;
float i;

suma = 0;
i = 1;

printf("Podaj lczbę naturalną\n");
scanf("%f",&n);

while (n >= i)
	{
		suma = 1/i*i;
		i = i + 1;
	}
printf("Wartosc sumy 1/i*i =%f",suma);
return 0;
}
