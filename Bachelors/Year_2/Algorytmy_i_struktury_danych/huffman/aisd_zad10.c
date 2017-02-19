
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1500
int length; 
int total; 
int  lastH, lastC;
char B[N];
char C[N]; 
int H[N*20]; 
 
typedef struct Letter{
	char znak; 
	int ile, kod[20], ileK;
	struct Letter *next, *prev;
	struct Letter *left, *right;
	struct Letter *nast;
} Letter;

Letter *start, *root;  
Letter *first; 
 
void read(char B[]){
	int  i=0, c=1;
	char pom;
	while(c>0 && i<N){
		c=(scanf("%c",&pom));
    	B[i] = pom;
    	i++;    
 	}
 	length=i-1;
}
 
Letter *search(char x){
	Letter *pom;
	pom=start;
	while(pom != NULL ){
    	if(pom->znak == x) return pom;
    	pom = pom->next;
 	}
	return NULL; 
}
 
Letter *add (int cos,  Letter *lewy,  Letter *prawy, char x){
	Letter *pom=start, *add;
	add = malloc(sizeof( Letter));
	add->znak = x;
	add->ile=cos;
	add->next = NULL;
	add->left = lewy;
	add->right = prawy;
	while(pom->next != NULL) pom=pom->next;
	pom->next = add;
	add->prev=pom;
	total++;
	return add;
}
 
void licz(Letter *start){
	int i;
	Letter *pom;
	total=1;
	start->znak =B[0];
	start->ile=1;
	start->next=NULL;
	start->prev=NULL;
	start->left = start->right= NULL;
	for( i=1; i<length; i++ ){
    	pom = search( B[i]); 
    	if( pom == NULL) add(  1 , NULL, NULL, B[i]);
    	else pom->ile++; 
 	}
}
 
void print(){
	Letter *pom=start; 
	printf("\n");
	while ( pom != NULL ) {
    	printf("%c: %d \n", pom->znak, pom->ile);
    	pom=pom->next; 
	}  
}
 
Letter *ExtractMin(){
	Letter *pom = start, *min=start;
	int min_ile=start->ile;
	while(pom->next != NULL){
	    pom=pom->next;
    	if(min_ile > (pom->ile)){
	        min = pom;
		    min_ile=pom->ile;
    	}   
 	} 
	if(min == start){
		if (start->next!=NULL) start=start->next;
	}    
	if((min->prev)!=NULL)(min->prev)->next = min->next; 
	if((min->next)!=NULL)(min->next)->prev = min->prev;
	return min;
}
 
void drukujB( char B[]){
	int i;   
	for(i=0; i<length; i++)
    	printf("%c", B[i]); 
}
 
void drukujH(){
	int i;  
	printf("____________zakodowany tekst \n");
	for(i=0; i<lastH; i++) printf("%d", H[i]); 
	printf("\n");
	FILE *coded;
	coded=fopen("pom.txt", "w");
	for(i=0; i<lastH; i++) fprintf(coded,"%d", H[i]);
	fprintf(coded, "\n");   
	fclose(coded);      
}
 
void drukujC(){
	int i;  
	printf("_______________odkodowany tekst \n");
	for(i=0; i<lastC; i++) printf("%c", C[i]); 
	printf("\n");
}
 
void Huffman(){
	int razem, pom, i;
	Letter *x, *y, *z;
	pom=total;
 
	for(i=1; i<=pom-1; i++){ 
	    x=ExtractMin();
    	y=ExtractMin();
    	razem = (x->ile)+(y->ile);
    	z=add(razem, x, y, '~' ); 
	}
	root=z;
}
 
void inorder(Letter * n, int c[], int lenc){
	int i, j;
	Letter *pom;
	if(!(n->left)){
    	printf("%c : ", n->znak );
    	for(i = 0; i < lenc; i++) printf( "%d ", c[i]);
    	printf( "\n");
    	for(j=0; j<lenc;j++) n->kod[j]=c[j];
    	n->ileK=lenc;
    	n->nast=NULL;
    	if(first == NULL){
        	first=n;      
    	}   
    	else{
        	pom=first;
        	while(pom->nast != NULL){
            	pom=pom->nast;
	        }   
        	pom->nast=n;
		}   
 	}
	else{
    	c[lenc] = 0; inorder(n->left,c,lenc + 1);
    	c[lenc] = 1; inorder(n->right,c,lenc + 1);    
	}
}
 
void kodowanie(){
	int i, j;
	Letter *pom;
	for(i=0; i<length; i++){
    	pom=first;
    	while ( pom->nast != NULL && pom->znak != B[i]) pom=pom->nast;
    	if( pom->znak != B[i] ) printf("%c( %c) znak niezdefiniowany \n", B[i], pom->znak);
    	else{
        	for(j=lastH; j<lastH+(pom->ileK); j++){
            	H[j]=pom->kod[j-lastH];  
	        }   
        	lastH=j;
    	}   
	}  
}

void odkodowanie(){
	Letter *pom;
	int i;
	pom= root;  
	for(i=0; i<lastH; i++){    
    	if(H[i]==0 && pom->left != NULL) pom=pom->left;
    	if(H[i]==1 && pom->right != NULL) pom=pom->right;
    	if(pom->left == NULL && pom->right == NULL){
	        C[lastC]=pom->znak;
    	    lastC++;
        	pom= root;  
    	}    
	}  
}   

int main(){
	start = malloc(sizeof( Letter));
	root = malloc(sizeof( Letter));
	first = malloc(sizeof( Letter));
	int hcodes[20];
	lastH=lastC=0;
	read(B);
	printf(" %d-> %d znakow->bitow w input \n", length, length*8);
	licz(start);
	print();
	Huffman();
	first=NULL;
	inorder(root,hcodes,0);
	kodowanie();
	drukujH();
	odkodowanie();
	drukujC();
	printf("  %d -> %d bitow  \n", 8*length, lastH);
	printf( "lastB:%d \t lastC:%d \n",length, lastC);
	return 0;
}
