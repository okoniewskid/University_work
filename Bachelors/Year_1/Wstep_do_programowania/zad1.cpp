#include <stdlib.h>
#include <conio.h>
#include <stdafx.h>

int liczba = 0;
int a,b = 0;
int i, j = 0;
int tab1[100], tab2[100];

int main()
{
	while(liczba >= 0){

		scanf("%d",&liczba);

		if (liczba >= 0){
			
			tab1[a] = liczba;
			a++;
		}
		else printf("- - - - - - - - - - - - -\n");
	}

	liczba = 0;

	while(liczba >= 0){

		scanf("%d",&liczba);

		if (liczba >= 0){
			
			tab2[b] = liczba;
			b++;
		}
		else printf("- - - - - - - - - - - - -");
	}

	printf("\nPierwsza liczba: ");

	for (i = 0; i < a; i++)
	{
		printf("%d",tab1[i]);
	}

	printf("\nDruga liczba: ");

	for (i = 0; i < b; i++)
	{
		printf("%d",tab2[i]);
	}

	// dodawanie

	// je¿eli pierwsza podana liczba jest wiêksza od drugiej liczby
	if (a >= b)
	{
		for (i = b; i >= 0; i--)
		{
			tab1[i + (a - b)] = tab1[i + (a - b)] + tab2[i];
		}

		printf("\nWynik dodania tych liczb/tablic to: ");

		for (i = 0; i < a; i++)
		{
			printf("%d",tab1[i]);
		}

		printf("\nDalsza czêœæ programu: ");

		for (i = a - 1; i >= 0; i--)
		{
			if (tab1[i] >= 10 && i != 0)
			{	
				tab1[i - 1] = tab1[i - 1]  + tab1[i] / 10;
				tab1[i] = tab1[i] % 10;
			}
			else
			{
				if (tab1[i] >= 10)
				{
					for (j = a + 1; j > 0; j--)
					{
						tab1[j] = tab1[j - 1];
					}
					
					tab1[i] = tab1[i] / 10;
					tab1[i + 1] = tab1[i + 1] % 10;
					a++;
				}
			}
		}

		printf("\nWynik poprawny dodawnia liczb/tablic: ");

		for (i = 0; i < a; i++)
		{
			printf("%d",tab1[i]);
		}
	}
	
	// je¿eli pierwsza podana liczba jest mniejsza od drugiej liczby
	if (b >= a)
	{
		for (i = a; i >= 0; i--)
		{
			tab2[i + (b - a)] = tab2[i + (b - a)] + tab1[i];
		}

		printf("\nWynik dodania tych liczb/tablic to: ");

		for (i = 0; i < b; i++)
		{
			printf("%d",tab2[i]);
		}

		printf("\nDalsza czêœæ programu: ");

		for (i = b - 1; i >= 0; i--)
		{
			if (tab2[i] >= 10 && i != 0)
			{	
				tab2[i - 1] = tab2[i - 1]  + tab2[i] / 10;
				tab2[i] = tab2[i] % 10;
			}
			else
			{
				if (tab2[i] >= 10)
				{
					for (j = b + 1; j > 0; j--)
					{
						tab2[j] = tab2[j - 1];
					}
					
					tab2[i] = tab2[i] / 10;
					tab2[i + 1] = tab2[i + 1] % 10;
					b++;
				}
			}
		}

		printf("\nWynik poprawny dodawnia liczb/tablic: ");

		for (i = 0; i < b; i++)
		{
			printf("%d",tab2[i]);
		}
	}

	scanf("%d");

	return 0;
}
