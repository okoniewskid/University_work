#include <stdio.h> 
int main() 
{ 
	int a; 
	int i; 
	int suma = 0; 
	for (a = 1; a < 9000; a++) 
	{ for (i = 1; i < a; i++) 
		{ 
			if ((a%i) == 0) { suma = suma + i; } 
		} 
	if (suma == a) 
		{ 
		printf("Suma %d",suma); 
		printf("\n");
		} 
		suma = 0; 
	} 
		return 0; 
		
}
