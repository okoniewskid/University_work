
//AL14.1 Daniel Okoniewski
#include <stdio.h>
#include <stdlib.h>
void DFS(int i, int **graf, int N, int *visited){
    int j;
    printf("\n%d",i);
    visited[i]=1;
    for(j=0;j<N;j++)
        if(!visited[j] && graf[i][j] == 1) DFS(j, graf, N, visited);
}

int main(){
	int **matrix;
	int l;
/*----reading----*/
	FILE *plik; 
	char p[20]; 
	int i,j,k,size;        
	printf("Wczytaj plik o nazwie: "); 
    scanf("%s", p); 
    plik = fopen(p,"r"); 
	if(plik == NULL){ 
  		printf("Error\n"); 
       	exit(0); 
	} 
    fscanf(plik,"%d \n", &size);
    printf("Rozmiar macierzy: %dx%d\n",size,size); 
	matrix = (int**)malloc(sizeof(int*)*size); 
    for(i=0;i<size;i++){
		matrix[i]=(int*)malloc(sizeof(int)*size);
    }    
    for(i=0;i<size;i++){
		for(j=0;j<size;j++){
            fscanf(plik,"%d", &matrix[i][j]); 
        }
    } 	
    for(i=0;i<size;i++){
		for(j=0;j<size;j++){ 
		   	printf("%d ",matrix[i][j]); 
		} 
        printf("\n"); 
    }    
    fclose(plik); 
/*--end-reading--*/	
    int visited[size];
    for(l=0;l<size;l++){
    	visited[l]=0;
    }
    DFS(0, matrix, size, visited);
    return 0;
}
