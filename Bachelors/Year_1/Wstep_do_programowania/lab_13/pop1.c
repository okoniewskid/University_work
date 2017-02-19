#include <stdio.h>
#include <math.h>

int silnia(int k){
	if(k==0) return 1;
	else return k*silnia(k-1);
	}

float funkcja(int k, float lambda){
	float pom2, pom3;
	float lambdamin;
	pom2 = pow(lambda,k)*exp(lambdamin);
	pom3 = silnia(k);
		if(k==0) return exp(lambdamin);
		else 	 return pom2/pom3;
	}
int main(){
	int k = 3;
	float lambda = 5;
	float lambdamin = -5;
	printf("%f\n",funkcja(k,lambda));
	return 0;
	}
