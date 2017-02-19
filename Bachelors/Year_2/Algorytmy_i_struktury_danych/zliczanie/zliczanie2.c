#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int t, tab2[21], tab[99], i, n;
	t = time(NULL);
	srand(t);
	for(i=0; i<100; i++){
		tab[i] = rand()%20+1;
	}
	printf("\nWylosowane liczby:\n"); 
	for (i=0; i < 100; i++){
		printf("%d\n", tab[i]);
	}
	for(i=1; i<=20; i++)tab2[i] = 0;
	for(n=1; n<=20; n++){
		for(i=0; i<100; i++){
			if(tab[i]==n) tab2[n]++;
		}
	}
	printf("\nIlosc liczb o danym indeksie:\n");
	for (i=1; i < 21; i++){
		printf("%d\n", tab2[i]);
	}
	int j=0;
	for(i=1; i<=20; i++){
		while(tab2[i]>0){
			tab[j]=i;
			j++;
			tab2[i]--;
		}
	}
	printf("\nPosortowana tablica:\n"); 	
	for (i=0; i < 100; i++){
		printf("%d\n", tab[i]);
	}
	return 0;
}
