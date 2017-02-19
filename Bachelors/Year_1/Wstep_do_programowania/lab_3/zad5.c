 #include <stdio.h> 

 int main()
 
{
float suma; 
int licznik; 
float srednia;  
float liczba; 
int dzielnik;
int granica;
int b = 1;

   suma = 0; 
   dzielnik = 0;
   licznik = 0; 

	
	printf("podaj wartosc graniczna");
	scanf("%d",&granica);

  while (licznik < granica)
  { 
	suma = suma + b;
	dzielnik = dzielnik + 1;
	licznik = licznik + 1;
	b = b + 2;
  }

  srednia = suma/dzielnik; 

 printf("oto suma liczb %f",suma);
 printf("a to ich wartosc srednia %f",srednia);

return 0;
}
