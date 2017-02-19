#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MDN 254 //maksymalna dlugosc napisu
#define IN 4 //ilosc napisow
int element(char **A, int wiersz, int kolumna){
 return (int)((strlen(A[wiersz]) > kolumna) ? A[wiersz][kolumna] : ' ');
}
int main(){
	char **A, **B;
	int i,j,n,c;
	char slowo[MDN]; // zawiera element do sortowania
	int max = 0; // dlugosc najdluzszego elementu
	A = (char**) malloc(IN * sizeof(char*));
	B = (char**) malloc(IN * sizeof(char*));
	for (i=0;i<IN;i++){
		printf("Podaj element %i: ",i+1); scanf("%s",slowo);
		A[i] = (char*) malloc((strlen(slowo)+1) * sizeof(char));
		strcpy(A[i],slowo);
		if (strlen(slowo) > max) max = strlen(slowo);
	}
	printf("\nNieposortowane:\n");
	for (i=0; i < IN; i++) printf(" %s\n", A[i]);
	for (j = max-1; j >= 0; j--){
		char C[MDN];
		int k = element(A, 0, j); //k - zakres wartosci w tablicy
		for (i = 1; i < IN; i++) if (element(A,i,j) > k) k = element(A,i,j);
		for (i = 0; i <= k; i++) C[i] = 0;
		for (i = 0; i < IN; i++) C[element(A,i,j)]++;
		for (i = 1; i <= k; i++) C[i] += C[i-1];
		for (i = IN-1; i >= 0; i--){
			c = element(A, i, j);
			B[C[c]-1] = A[i];
			C[c]--;
		}
		char **T = B;
		B = A;
		A = T;
	}
	free(B);
	printf("\nPosortowane:\n");
	for (i=0; i < IN; i++){
		printf(" %s\n", A[i]);
		free(A[i]);
	}
	free(A);
	return 0;
}
