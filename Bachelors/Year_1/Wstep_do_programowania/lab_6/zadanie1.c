#include<stdio.h> 
int main() 
{ 
	int i=0; 
	float tab[10]; 
	int dodatnie, ujemne, zera; 
	dodatnie=0; 
	ujemne=0; 
	zera=0; 
	
	for(i=0; i<10; ++i) 
	{ 
		scanf("%f", &tab[i]); 
	} 
	for(i=0; i<10; i++) 
	{ 
		if(tab[i] == 0) 
		{
			++zera;
		} 
		if(tab[i] >0) 
		{
			++dodatnie;
		} 
		if(tab[i] < 0)
		{
			++ujemne;
		} 
	} 
	printf("dodatnie: %d\n" ,dodatnie); 
	printf("ujemne: %d\n" ,ujemne); 
	printf("zera: %d\n" ,zera); 
	return 0;
}
