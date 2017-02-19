#include <stdio.h>
#define LENGTH 8
int main()
{
int i;
int tab[LENGTH] = { 1 , 2 , 2 , 1 , 3 , 1 , 3 , 3 };
// Szukanie najwiêkszej wartoœci
int maxValue = tab[0];
for( i = 1; i < LENGTH ; i++ )
{
if( tab[i] > maxValue ){ maxValue = tab[i]; }
}
int valuesCount[maxValue+1];
int posortowane[LENGTH];
// Zerowanie tablicy
for( i = 0 ; i <= maxValue ; i++ ){ valuesCount[i] = 0; }
// Zliczanie
for( i = 0 ; i < LENGTH ; i++ )
{
valuesCount[tab[i]] = valuesCount[tab[i]] + 1;
}
for( i = 1 ; i < LENGTH ; i++ )
{
valuesCount[i] = valuesCount[i] + valuesCount[i-1];
}
// Dystrybucja
for( i = LENGTH-1 ; i >= 0 ; i-- )
{
posortowane[valuesCount[tab[i]]-1] = tab[i];
valuesCount[tab[i]] = valuesCount[tab[i]] - 1;
}
// Wypisanie
printf("Nieposortowana: ");
for( i = 0 ; i < LENGTH ; i++ )
{
printf("%i ", tab[i]);
}
printf("\n");
printf("Posortowana: ");
for( i = 0 ; i < LENGTH ; i++ )
{
printf( "%i ", posortowane[i] );
}
printf("\n");
return 0;
}