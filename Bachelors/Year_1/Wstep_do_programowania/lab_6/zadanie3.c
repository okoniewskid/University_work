#include<stdio.h>
int main() 
{ 
	int i=0; 
	float tab1[10]; 
	float tab2[10]; 
	
	printf("pierwsza tablica"); 
	for(i=0; i<10; i++) 
	{ 
		scanf("%f", &tab1[i]); 
	} 
	
	printf("druga"); 
	for(i=0; i<10; i++) 
	{ 
		scanf("%f", &tab2[i]); 
	} 
	for(i=0; i<10; ++i) 
	{ 
		if(tab1[i] < tab2[i]) 
		{ 
			printf("dla i od %d poprzedza leksykograficznie tablicę\n ", i); 
		}
		if(i == 10 && !(tab1[i] < tab2[i])) 
		{
			printf("dla i od %d poprzedza Nie leksykograficznie tablicę\n ", i); 
		} 
	} 
	return 0; 
}
