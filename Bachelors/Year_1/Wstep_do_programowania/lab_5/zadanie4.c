#include <stdio.h>
int main()
{
	int n,i,j;
	i = 0;
	n = 20;
	char tab[n];
	char litera;
	litera = 'a';
	
	while((int)litera != 10)
		{ 
			scanf("%c",&litera);
			tab[i] = litera;
			++i; 
		}
	--i;
	j = 0;
	while(j < i)
		{
			if(tab[j]==tab[i])
				{
					++j;
					--i;
				}
			else{printf("nie jest palindromem\n");break;}
		}
		
	printf("jest palindromem\n");

	return 0;
}
