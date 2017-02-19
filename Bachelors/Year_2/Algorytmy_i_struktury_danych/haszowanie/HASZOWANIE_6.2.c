#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 3647

int tab[M];
int i;

int HASZUJ(char *slowo){
	unsigned hasz;
	int b=111;
	int dl=strlen(slowo);	
	hasz=(int)slowo[dl - 1];	
		printf("%d\n" , hasz);
	for(i=dl-1;i>=0;i--){
		hasz = hasz*b+(int)slowo[i];
		hasz = hasz%M;
	}
	return hasz;
}

void WCZYTAJ(){
	FILE *plik;	
	char temp[20]; 
	plik = fopen("3700.txt", "r");
	if(plik==NULL){
		printf("PLIK JEST PUSTY!");
	}
	else{
		while(fscanf(plik, "%s", temp)!=EOF){
			tab[HASZUJ(temp)]++;
		}
	}
	fclose(plik);
}

int ZERA(){	
	int zera = 0;	
	for(i=0; i<M; i++){
		if(tab[i] == 0){
			zera++;
		}
	}
	return zera;
}

int MAKSIMUM(){
	int maks = 0;	
	for(i=0; i<M; i++){
		if(tab[i]>maks){
			maks=tab[i];
		}
	}
	return maks;
}

double SREDNIA(){
	double sum=0;
	int count=0;
	for(i=0;i<M;i++){		
		if(tab[i]>0){
			sum += tab[i];
			count++;
		}
	}		
	return sum/count;
}

int main(){
	for(i=0; i<M; i++){ 
		tab[i]=0;
	}
	
	WCZYTAJ();
	
	int zerowe = ZERA(); 
	int maksymalna = MAKSIMUM(); 
	double srednia  = SREDNIA();
	
	printf("Ilosc zerowych pozycji w tablicy: %d\n", zerowe);
	printf("Maksymalna wartosc w tablicy: %d\n", maksymalna);
	printf("Srednia wartosc liczb niezerowych: %0.2lf\n", srednia);
	return 0;
}
