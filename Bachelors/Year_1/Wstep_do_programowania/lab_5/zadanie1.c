#include <stdio.h>
int main()
{
	int a,b,c;
	printf("podaj a: ");
	scanf("%d",&a);
	
	printf("podaj b: ");
	scanf("%d",&b);
	
	printf("podaj c: ");
	scanf("%d",&c);
	
	if(a>b)
		{
			if(a>c)
				{printf("a jest najwieksze");}
		}
		else 
		{
			if(b>c)
				{printf("b jest najwieksze");}
			else{printf("c jest najwieksze");}
		}
	return 0;
}
