#include <stdio.h>
int main()
{
	int i=0;
	int d1 = 0;
	int d2 = 0;
	int tab[10];
	int cyfra;
	
	while (cyfra > 0)
		{
			scanf("%d", &cyfra);
			if(cyfra>0)
			tab[i] = cyfra;
			i++;
			
			while(j > 0)
			{
				j = cyfra/10;
				d1++;
			}
		}
		
	printf("%d",d1);
		
	return 0;
}
