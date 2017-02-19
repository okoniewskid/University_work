#include <stdio.h> 
int main() 
{ 
	int i,l,x; l = 14; 
		for(i = 1; i <= l; ++i) 
		{ x = l % i; 
			if(x == 0){printf("%d\n", i);} 
		} 
}
