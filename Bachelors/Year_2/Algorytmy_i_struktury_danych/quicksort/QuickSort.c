#include <stdio.h>
int dlugosc;

void CzytPlik(int *A){
	int i = 0;
	FILE *plik = fopen("dane.txt","r");
	while(fscanf(plik,"%i",&A[i++]) !=EOF) dlugosc++;
	fclose(plik);
}

int Partition(int A[], int p, int r){
   int pivot, i, j, pom;
   pivot = A[p];
   i = p; j = r;
		
   while(1){
		while (A[j] > pivot)
			j--;
		while (A[i] < pivot)
			i++;
		if (i < j){
			pom = A[i];
			A[i] = A[j];
			A[j] = pom;
			i++;
			j--;
		}
		else 
			return j;
   }
}

void quickSort( int A[], int p, int r){
   int q;
   if( p < r ) {
	q = Partition( A, p, r);
	quickSort( A, p, q);
	quickSort( A, q+1, r);
   }
	
}

int main(){
	
	int i;
	dlugosc = 0;
	int tab[100];
	CzytPlik(tab);
	for (i = 0; i < dlugosc; i++) printf("%d ", tab[i]);
	printf("\n"); FILE*fp2=fopen("posortowane.txt","w");
	quickSort(tab, 0, dlugosc);
	for (i = 0; i < dlugosc; i++){
		fprintf(fp2,"%d\n", tab[i]); 
		printf("%d ", tab[i]);
	}
	printf("\n"); 
	fclose(fp2);
	getchar();
	return 0;
}
