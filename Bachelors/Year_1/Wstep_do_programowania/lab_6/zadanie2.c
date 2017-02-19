#include<stdio.h>
int main()
{
	float suma = 0;
	float tab[7];
	float tab1[7] ;
	int i;
	printf("podaj pierwsza tablice rzeczywistych");
	for(i = 0; i < 7; ++i)
	{
		scanf("%f", &tab[i] );
	}
	
	printf("podaj drugiej tablice rzeczywistych");
	
	for(i = 0; i < 7; ++i)
	{
		scanf("%f", &tab1[i] );
	}
	for(i = 0; i < 7; ++i)
	{
		suma = suma + (tab[i] * tab1[i]);
	}

printf("%f\n" , suma);

return 0;
}
