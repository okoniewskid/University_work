#include <stdio.h>
int main()
{
	int i,j;
	int tab[8] = {5,5,8,7,3,3,9,11};
	for(i = 3; i >= 0; --i)
		{
			printf("%d\n",tab[i]);
		}
	for(j = 4; j <= 7; ++j)
	 {
		 printf("%d\n",tab[j]);
	 }
		
	return 0;
}
