#include<stdio.h>
#include<limits.h>
#include<float.h>
int main()
{
int a;
a = (int)FLT_MAX;
printf("Maksymalna wartosc FLOAT zrzutowana na INT wynosi: %d",a);
 
printf("\n");
a = (int)DBL_MAX;
printf("Maksymalna wartosc DOUBLE zrzutowana na INT wynosi: %d",a);
 
printf("\n");
a = (double)LONG_MAX;
printf("Maksymalna wartosc LONG zrzutowana na INT wynosi: %d",a);
 
printf("\n");
float aa;
aa = (float)INT_MAX;
printf("Maksymalna wartosc INT zrzutowana na FLOAT wynosi: %f",aa);
printf("\n");
}
