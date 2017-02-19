#include <stdio.h>

int main(){
	int tabA[2][2];
	int tabB[2][2];
	int tabW[2][2];
	int i,j =0;
	
	 for(i=0;i<2;i++) 
      for(j=0;j<2;j++)
       {
		   scanf("%d",&tabA[i][j]);
		}
         
     for(i=0;i<2;i++)
      for(j=0;j<2;j++)
      {
          scanf("%d",&tabB[i][j]);
		  tabW[i][j] = tabA[i][j] + tabB[i][j];
      }
    
	printf("%d\n",tabW[i][j]);
		
	return 0;
}
