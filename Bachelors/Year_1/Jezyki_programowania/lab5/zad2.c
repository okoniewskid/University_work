#include<stdio.h>
#include<string.h>
#include<ctype.h>
 
#define IMIE_MAX 15
#define NAZW_MAX 15
#define IL_OSOB 10
 
	typedef struct 
		{
			char imie[IMIE_MAX+1];
			char nazwisko[NAZW_MAX+1];
			int pensja;
		} osoba;
 
osoba spis[IL_OSOB];
 
//=======================================================
 
void utworz_spis(void) 
{
	FILE* baza = fopen("./lista","r");
	if (baza == NULL) printf("\n ZLE\n\n");
	int i;
	for (i=0; i<IL_OSOB; i++) 
	{
		fscanf(baza, "%s", spis[i].imie);
		fscanf(baza, "%s", spis[i].nazwisko);
		fscanf(baza, "%i", &spis[i].pensja);
	}
	fclose(baza);
}
 
//=======================================================
 
 
 
 
void sortuj_spis(void) 
{
/* sortuje spis alfabetycznie wg nazwisk,
  a w przypadku rownych nazwisk wg imion
  */
 int i,j,k; 
 osoba zmienna; 
 for (i=0;i<IL_OSOB;i++) 
 for (j=0;j<IL_OSOB;j++) 
 { 
	 if (strcmp(spis[i].nazwisko,spis[j].nazwisko) < 0) 
		{ zmienna=spis[i]; spis[i]=spis[j]; spis[j]=zmienna; } 
	 if (strcmp(spis[i].nazwisko,spis[j].nazwisko) == 0) 
		{ 
			if (strcmp(spis[i].imie,spis[j].imie) < 0)
			{ zmienna=spis[i]; spis[i]=spis[j]; spis[j]=zmienna; } 
		} 
  }
}
 
//=======================================================
 
int znajdz_nazwisko (char na[NAZW_MAX+1],char im[IMIE_MAX+1], int *p)
{
/* do danego nazwiska na znajduje w spisie
  imie im oraz pensje p
  jesli znajdzie, to zwraca 1, jesli nie, to 0
  */
	int i,j;
	char nazw[NAZW_MAX+1] ;
	int czy_nazw=0;
	for( i=0 ; i<IL_OSOB ; i=i+1 )
	{
		strcpy (nazw ,spis[i].nazwisko);
		for(j=0 ; j<NAZW_MAX ; j++)
		{
			if(nazw[j]=='\0')
			{
				j=IMIE_MAX;
				break;
			}
			if(na[j]!=nazw[j])
			break;
		}
		if(j==IMIE_MAX)
		{
			*p=spis[i].pensja;
			strcpy (im ,spis[i].imie);
			czy_nazw=1;
		}
	}
	return czy_nazw;
	return 0;
}
 
void wypisz_spis()
	{
            int i;
            for (i = 0; i < IL_OSOB; i++)
            printf("%2i %s %s %izl\n", i, spis[i].imie, spis[i].nazwisko, spis[i].pensja);
	}

 
//=======================================================
 
int znajdz_imie (char im[NAZW_MAX+1],char na[IMIE_MAX+1],int *p)
{
/* do danego imienia im znajduje w spisie
  nazwisko na oraz pensje p
  jesli znajdzie, to zwraca 1, jesli nie, to 0
  */
	int i,j;
	char imie[IMIE_MAX+1] ;
	int czy_imie=0;
	for( i=0 ; i<IL_OSOB ; i=i+1 )
	{
		strcpy (imie ,spis[i].imie);
		for(j=0 ; j<IMIE_MAX ; j++)
		{
			if(imie[j]=='\0')
			{
				j=IMIE_MAX;
				break;
			}
			if(im[j]!=imie[j])
			break;
		}
		if(j==IMIE_MAX)
		{
			*p=spis[i].pensja;
			strcpy (na ,spis[i].nazwisko);
			czy_imie=1;
		}
	}
	return czy_imie;
}
 
//=======================================================
 
int main ()
{
	char odpowiedz, im[NAZW_MAX+1], na[IMIE_MAX+1];
	int p;
 
	utworz_spis();
	sortuj_spis();
 
do
{
printf("\n Znalezc wg imienia (I), nazwiska (N) , wypisac liste (L), czy zakonczyc (Q)? ");
 
do
{
odpowiedz = getchar();
}
while (isspace(odpowiedz));
 
odpowiedz = tolower(odpowiedz);
switch (odpowiedz)
{
case 'i' :
printf("\n szukane imie: ");
scanf("%s", im);
if (znajdz_imie(im, na, &p))
{
printf(" IMIE: %s, NAZWISKO: %s, PENSJA: %i\n", im, na, p);
}
else
{
printf(" nie ma imienia %s\n", im);
}
break;
case 'n' :
printf("\n szukane nazwisko: ");
scanf("%s", na);
if (znajdz_nazwisko(na, im, &p))
printf(" IMIE: %s, NAZWISKO: %s, PENSJA: %i\n", im, na, p);
else
printf(" nie ma nazwiska %s\n", na);
break;
case 'l' :
wypisz_spis();
case 'q' :
break;
default :
printf(" Poprawne odpowiedzi: N, I, Q.\n");
}
}
while (tolower(odpowiedz) != 'q');
 
printf("\n DZIEKUJE.\n\n");
return 0;
}
