 #include <stdio.h> 

 
 int main()

 
 {
   int n = 0;
   int m = 0;
while (n < 11)
{
	printf("\n");
   while (m < 11)
     {
       printf(" %d ",n*m);
       m++;
     }
   m = 0;
   n++;
 }

return 0;
 
}
