#include <stdio.h> 
#define T 3
  
int OstatniW;
 
typedef struct{ 
	int pozycja;        
	short n;        	 
	short lisc;     	
	int k[2*T-1];   	
	int c[2*T];     
	int info[2*T-1];  
} Wezel; 
 
int rozmiarw = sizeof(Wezel); 
FILE *drzewo;
  
void ZAPIS(int i,Wezel *w){ 
	fseek(drzewo,(long)i*rozmiarw,SEEK_SET); 
	fwrite(w,rozmiarw,1,drzewo); 
} 
  
void ODCZYT(int i,Wezel *w){ 
	fseek(drzewo,(long)i*rozmiarw,SEEK_SET); 
	fread(w,rozmiarw,1,drzewo); 
}
  
void USUWANIE(int i){  
	Wezel w; 
	ODCZYT(i,&w); 
	w.n=-1; 
	ZAPIS(i,&w); 
} 

int BUDOWANIE(int g, int n){ 
	static int klucz = 0;
	static int pozycja = 0; 
	Wezel w;
	w.n=n;
	int i;
	if(g==0){
    	for(i=0;i<n;i++){ 
    	w.c[i]= -1; 
    	w.k[i]= klucz++; 
    	} 
    	w.c[n]= -1; 
    	w.lisc=1; 
  	}
	else{ 
    	for(i=0;i<n;i++){ 
      		w.c[i]= BUDOWANIE(g-1,n); 
      		w.k[i]= klucz++; 
    	} 
    	w.c[n]= BUDOWANIE(g-1,n);; 
    	w.lisc=0; 
  	}
  	w.pozycja=pozycja; 
  	ZAPIS(pozycja++,&w); 
  	OstatniW= pozycja -1; 
  	return pozycja-1; 
} 
  
int SZUKANIE(int korzen, int key){
	Wezel x; 
	int i, pom;
	ODCZYT(korzen,&x); 
	i = 0; 
	while(i<x.n && key>x.k[i]){ 
    	i++;  
	} 
	if(i<=x.n && key==x.k[i]){ 
    	pom = 100*x.pozycja + i; 
    	return pom; 
	}     
	if(x.lisc == 1) return -1;  
	else SZUKANIE(x.c[i], key);    
}    
  
void ZNAJDZ(int korzen, int key ){ 
	int gdzieW, miejsceK, wynik; 
	wynik=SZUKANIE(korzen, key);   
	if(wynik==-1) printf("\nnie znaleziono klucza: %d\n", key); 
	else{ 
    	gdzieW = wynik / 100; 
    	miejsceK = wynik % 100; 
    	printf("\nznaleziono klucz %d:\n -miejsce w pliku wezla z kluczem: %d \n -pozycja klucza w wezle: %d \n", key, gdzieW, miejsceK+1); 
 	}   
}

void rozbijanie_syna(int x_id, int i, int y_id){
	Wezel z, x, y; 
	int j; 
	ODCZYT(x_id,&x); 
	ODCZYT(y_id,&y); 
	z.lisc=y.lisc; 
	z.n = T-1; 
	for(j=1; j<=T-1; j++) z.k[j-1]= y.k[j+T-1]; 
	if(y.lisc == 0 ){ 
    	for(j=1; j<=T; j++) z.c[j-1]=y.c[j+T-1];
	}
	y.n = T-1; 
	for(j=x.n+1; j>=i+1; j--) x.c[j]=x.c[j-1]; 
	x.c[i]=OstatniW+1; 
	for(j=x.n; j>=i; j--) x.k[j]=x.k[j-1]; 
	x.k[i-1]=y.k[T-1]; 
	x.n++; 
	ZAPIS(y_id,&y); 
	ZAPIS(OstatniW+1,&z); 
	OstatniW++; 
	ZAPIS(x_id,&x); 
} 
      
void W_NIEPELNY(int korzen, int key){
	Wezel x, w; 
	int i;  
	ODCZYT(korzen,&x); 
	i=x.n; 
	if(x.lisc==1){ 
    	while (i>=1 && key<x.k[i-1]){ 
        	x.k[i]=x.k[i-1]; 
        	i--; 
    	}    
    	x.k[i]=key; 
    	x.n++; 
    	ZAPIS( korzen, &x); 
	} 
	else{ 
    	while (i>=1 && key<x.k[i-1]) i--; 
    	i++; 
    	ODCZYT(x.c[i-1],&w); 
    	if(w.n == (short) 2*T-1){ 
        	rozbijanie_syna(korzen, i, x.c[i-1]); 
        	if(key>x.k[i-1]) i++;    
    	}    
    	W_NIEPELNY( x.c[i-1], key); 
 	}       
} 
      
int WSTAWIANIE(int korzen, int key){
	Wezel r;  
	int pom, s_id, tmp;   
	pom=0;   
	ODCZYT(korzen, &r); 
	if(r.n == 2*T-1 ){ 
    	Wezel s; 
    	s_id=OstatniW+1; 
    	OstatniW++; 
    	pom=s_id; 
    	s.lisc=0; 
    	s.n=0; 
    	s.c[0]=korzen; 
    	ZAPIS(s_id, &s); 
    	rozbijanie_syna(s_id, 1, korzen); 
    	W_NIEPELNY(s_id, key); 
	}    
	else W_NIEPELNY(korzen, key); 
	if(pom == 0 ) return korzen; 
	else return pom;   
}
 
void drukujB(int r, int p){ 
  // drukuje B-drzewo o korzeniu r (pozycja w pliku) 
  // wydruk przesuniety o p w prawo 
	Wezel w; 
  	int i,j; 
  	ODCZYT(r,&w); 
	if(w.lisc){ 
    	for(i=0;i<p;i++) printf(" "); 
    	for(i=0;i<w.n;i++) printf("%d ",w.k[i]); 
    	printf("\n"); 
	} 
	else{ 
	    drukujB(w.c[w.n],p+4); 
    	for(i=w.n-1;i>=0;i--){ 
      		for(j=0;j<p;j++) printf(" "); 
      		printf("%d\n",w.k[i]); 
      		drukujB(w.c[i],p+4); 
    	} 
  	} 
} 
  
void drukujBDot(int r){ 
	FILE *plikwy; 
	plikwy=fopen("bdrzewo.gv","w"); 
	fprintf(plikwy, "graph bdrzewo{\n"); 
	fprintf(plikwy, "size = \"2,20\""); 
	rekDrukujBDot(r,0,plikwy); 
	fprintf(plikwy, "}\n"); 
	fclose(plikwy); 
	printf("utworzony plik bdrzewo.gv"); 
} 

int rekDrukujBDot(int r, int z, FILE *plikwy){  
	Wezel w; 
	int nz,i; 
	ODCZYT(r,&w);  
  	fprintf(plikwy,"%d [shape=box, label=\"",z); 
  	for (i=0;i<w.n;i++) fprintf(plikwy,"%d ",w.k[i]); 
  	fprintf(plikwy,"\"]\n"); 
  	nz=z; 
	if (!w.lisc){ 
		for (i=0;i<=w.n;i++){ 
			fprintf(plikwy,"%d -- %d ;\n",z,nz+1); 
      		nz=rekDrukujBDot(w.c[i],nz+1,plikwy);   
    	}	 
  	} 
  	return nz; 
} 
   
int main(){
	drzewo = fopen("bdrzewo","w+"); 
    int korzen, add;
    OstatniW=0; 
    korzen=BUDOWANIE(2,2); 
    printf("\n"); 
    ZNAJDZ(korzen, 15); 
    ZNAJDZ(korzen, 18); 
    ZNAJDZ(korzen, 86); 
    drukujB(korzen,0); 
    printf("\n \n"); 
    add=WSTAWIANIE(korzen, 12); 
	drukujB(korzen,0); 
	printf("\n \n");
    korzen=add; 
    add=WSTAWIANIE(korzen, 22); 
	drukujB(korzen,0);
	printf("\n \n"); 
    korzen=add; 
    add=WSTAWIANIE(korzen, 20); 
	drukujB(korzen,0);
	printf("\n \n"); 
    korzen=add; 
    add=WSTAWIANIE(korzen, 19); 
	drukujB(korzen,0);
	printf("\n \n"); 
    korzen=add; 
    drukujB(korzen,0);
	printf("\n \n"); 
    drukujBDot(korzen); 
    fclose(drzewo); 
    return 0; 
} 
