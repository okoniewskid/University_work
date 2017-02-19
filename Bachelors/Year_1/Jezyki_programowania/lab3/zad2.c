#include <stdio.h> 
#include <limits.h> 
#include <float.h> 
#include <math.h> 
void pierwsze() 
{ 
	float wynik; 
	float x1; 
	x1=FLT_EPSILON; 
	wynik = 1.0; 
	wynik=(wynik+x1/2)+x1/2; 
	printf("%.20f\n", wynik); 
	wynik = 1.0; 
	wynik=wynik+(x1/2+x1/2); 
	printf("%.20f\n", wynik); 
}
void drugie() 
{ 
	int a; 
	a=INT_MAX; 
	a++; 
	printf("%i",a); 
}
void trzecie() 
{ 
	float x1,x2; 
	int i; 
	int k=pow(10,9); 
	for(i=1;i<=k;i++) { x1=x1+1./i; } 
	printf("\n zadanie 2c \n%f",x1); 
	for(i=k;i>1;i--) { x2=x2+(1./i);} 
}
void czwarte() 
{ 
	float x,y,z; 
	x=1.0/FLT_MAX; 
	y=FLT_MAX; 
	z=y; 
	float w, w1; 
	w=x*(y*z); 
	w1=(x*y)*z; 
	printf("\n%f",w); 
	printf("\n%f",w1); 
}
int main() 
{ 
	pierwsze(); 
	drugie(); 
	trzecie(); 
	czwarte(); 
	return 0; 
}
