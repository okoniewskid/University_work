#include <stdio.h>

int Rozmiar, ilosc;

//Funkcja napraw przywraca kopcowi jego wlasnosc. Synowie musz¹ byæ nie wiêksi ni¿ ojciec.
// *A - tablica z liczbami w kopcu
// i - sprawdzany ojciec
void Napraw(int* A, int i){
    int l, r;
    l = 2*i + 1; //lewy syn
    r = 2*i + 2; //prawy syn
    if (l < Rozmiar){
        if (A[l] > A[i]){
            int pom;
            pom = A[l];  //if zamienia skladniki miejscami jesli lewy syn jest wiekszy od ojca
            A[l] = A[i];
            A[i] = pom;
        }
        if (r < Rozmiar){
            if (A[r] > A[i]){
                int pom;
                pom = A[r]; //if zamienia skladniki miejscami jesli prawy syn jest wiekszy od ojca
                A[r] = A[i];
                A[i] = pom;
            }
        }
    }
}
//Funkcja tworzaca kopiec
// *A - tablica z ktorej i do ktorej tworzymy kopiec
void Budowanie(int* A){
    int i;
    Rozmiar = ilosc;
    for (i = ilosc/2; i >= 0; i--) Napraw(A, i);
}
//Funkcja sortujaca przez kopcowanie
void SortowanieKopca(int* A){
    Budowanie(A);
    FILE*fp2=fopen("posortowane.txt","w");
    int pom, i;
 
    for (i = ilosc - 1; i >= 0; i--){
        fprintf(fp2,"%d\n", A[0]);
    //    printf("%3i ", A[0]); //wyswietla posortowana liczby
        pom = A[0];
        A[0] = A[i];
        A[i] = pom;
        Rozmiar--;
    }
    fclose(fp2);
}
//Wczytuje dane z wybranego pliku i dodaje je do tablicy *A
void CzytPlik(int *A){
    int i = 0;
    FILE *file = fopen("Pliczek.txt", "r" );
    while(fscanf(file, "%i", &A[i++]) != EOF) ilosc ++;
    fclose(file);
}
int main(){
    ilosc = 0;
    int tab[100];
    CzytPlik(tab);	
  //  for (i = 0; i < ilosc; i++) printf("%3i ", tab[i]); //wyswietla liczby przed sortowaniem
    printf("\n");
    SortowanieKopca(tab);
    printf("\n");
    return 0;
}
