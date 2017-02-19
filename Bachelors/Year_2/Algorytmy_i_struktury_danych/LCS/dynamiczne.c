//AL9.3 - na podstawie pseudokodu na stronie pana doktora P¹czkowskiego. 
#include <stdio.h>
#include <string.h>
int i, j, m, n, c[20][20];
char x[10], y[10], b[20][20];

void DRUKUJ(int i,int j){
	if(i==0 || j==0){
		return;
	}
	if(b[i][j] == 's'){ //skos w pseudokodzie "\"
		DRUKUJ(i-1,j-1);
		printf("%c",x[i-1]);
	}
	else if(b[i][j] == 'g'){ //gora w pseudokoszie "|"
		DRUKUJ(i-1,j);
	} 
	else{	//lewo w pseudzokodzie "-"
		DRUKUJ(i,j-1);
	}
}

void LCS(){
	m = strlen(x);
	n = strlen(y);
	for(i = 0; i <= m; i++){
		c[i][0]=0;
	}
	for(j = 0; j <= n; j++){
		c[0][j] = 0;
	}
	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++){
			if(x[i-1] == y[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 's';
			} 
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
				b[i][j] = 'g';
			} 
			else{
				c[i][j] = c[i][j-1];
				b[i][j] = 'l';
			}
		}
	}
	DRUKUJ(m,n);
}

int main(void){
	printf("1 ciag:\n");
	gets(x);
	printf("2 ciag:\n");
	gets(y);
	printf("Najdluzszy wspolny podciag: \n");
	LCS();
	printf("\n");
	return 0;
}
