#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

/****************************************************************/
// DEFINICJA TYPU LICZB ZESPOLONYCH:

typedef struct {
  double rea, ima;
}  zespol;

/****************************************************************/
// POMOCNICZE:

void  err(char s[]) {  // -- sygnalizacja bledu wejscia
  printf("\n !!! FUNKCJA zesp_get: %s !!!\n\n", s);
  exit(1);
}

/****************************************************************/
// INICJALIZACJE oraz WEJSCIE-WYJSCIE:

zespol  zesp_zestawic (double r, double i) {
    // zestawienie liczby zespolonej z dwoch rzeczywistych
  zespol z;
  z.rea = r;  z.ima = i;
  return z;
}

zespol  zesp_get (void) {
    /* wczytanie liczby zespolonej; powinna skladac sie z dwoch
       rzeczywistych, oraz plusa lub minusa miedzy nimi, zaczynac sie od
       nawiasu otwierajacego, konczyc sie litera i oraz nawiasem
       zamykajacym;
       np.  (123.45 + 67.89i)
    */
  char ch;  zespol z;  int znak_im;
  do { ch = getchar(); } while (isspace(ch));
  if (ch == '(') {
    if (scanf("%lf", &(z.rea)) == 1) {
      do { ch = getchar(); } while (isspace(ch));
      if (ch == '+' || ch == '-') {
	if (ch == '+')  znak_im = 1;
	else  znak_im = -1;
	if (scanf("%lf", &(z.ima)) == 1) {
	  do { ch = getchar(); } while (isspace(ch));
	  if (ch == 'i') {
	    do { ch = getchar(); } while (isspace(ch));
	    if (ch == ')') {
	      if (znak_im == -1)  z.ima = -z.ima;
	    } else err("brak koncowego nawiasu");
	  } else err("brak 'i' na koncu czesci urojonej");
	} else err("niepoprawna czesc urojona");
      } else err("po czesci rzeczywistej brak znaku '+' lub '-'");
    } else err("niepoprawna czesc rzeczywista");
  } else err("brak rozpoczynajacego nawiasu");
  return z;
}

void  zesp_print (zespol z) { // drukowanie liczby zespolonej
  if (z.ima >= 0)
    printf("(%.2lf+%.2lfi)", z.rea, z.ima);
  else
    printf("(%.2lf-%.2lfi)", z.rea, -z.ima);
}

/****************************************************************/
// DZIALANIA:

zespol  zesp_dodac (zespol z1, zespol z2)
  // dodawanie liczb zespolonych
	{
		zespol z3;
	z3.rea = z1.rea + z2.rea;
	z3.ima = z1.ima + z2.ima;
	return z3;
	}

zespol  zesp_odjac (zespol z1, zespol z2)
   //odejmowanie liczb zespolonych
	{
		zespol z3;
	z3.rea = z1.rea - z2.rea;
	z3.ima = z1.ima - z2.ima;
	return z3;
	}
zespol  zesp_razy (zespol z1, zespol z2)
  // mnozenie liczb zespolonych
	{
		zespol z3;
	z3.rea = (z1.rea*z2.rea)-(z1.ima*z2.ima);
	z3.ima = (z1.ima*z2.rea)+(z1.rea*z2.ima);
	return z3;
	}
zespol  zesp_sprzez (zespol z)
  // liczba sprzezona do danej zespolonej
	{
	zespol spz; 
	spz.rea = (z.rea); 
	spz.ima = ( - z.ima); 
	return spz; 
	}
double  zesp_abs (zespol z)
  // wartosc bezwzgledna liczby zespolonej
	{
	zespol z3; 
	double a,b; 
	z3.rea=z.rea*z.rea; 
	z3.ima=z.ima*z.ima; 
	a=z3.rea+z3.ima; 
	b=sqrt(a); 
	return b;
	}
zespol zesp_div (zespol z1, zespol z2) 
	{ 
		// dzielenie liczb zespolonych 
		zespol z; 
		z.rea=((z1.rea*z2.rea)+(z1.ima*z2.ima))/((z2.rea*z2.rea)+(z2.ima*z2.ima)); 
		z.ima=((z2.rea*z1.ima)-(z1.rea*z2.ima))/((z2.rea*z2.rea)+(z2.ima*z2.ima)); 
		return z; 
	}
int euler_identity()
	{
	zespol z;
	z.ima = e_to_pow_ima();
	z.rea = z.rea+1;
	double euler_module = zesp_abs(z);
	if (abs(euler_module) < 0.00000001)
		return 0;
	else
		return 1;
}
/****************************************************************/


int main () {
  zespol  z1, z2;

  printf("\n z1 == "); z1 = zesp_get();
  printf(" z2 == "); z2 = zesp_get();

  printf("\n z1+z2 == "); zesp_print(zesp_dodac(z1, z2));
  printf("\n z1-z2 == "); zesp_print(zesp_odjac(z1, z2));
  printf("\n z1*z2 == "); zesp_print(zesp_razy(z1, z2));
  printf("\n |z1+z2| == %.4lf\n\n", zesp_abs(zesp_dodac(z1, z2)));
  printf("\n z1/z2 == "); zesp_print(zesp_div(z1, z2));
  	if(euler_identity()==0)
		printf("\n Tożsamość Eulera jest prawdziwa \n");
	else
		printf("\n Tożsamość Eulera jest nieprawdziwa \n");
  return 0;
}

