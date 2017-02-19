/* Uzupelnic ponizszy program tak, aby na ekranie terminala po jego uruchomieniu na ekranie
wypisane zostalo pierwsze dopasowanie wyrazenia regularnego [ab][^abc]+c do lancucha x.
Np. w przypadku gdy x = "abc  b acabxx xyc pqr", to efektem dzialania programu powinno byc
wyprowadzenie na ekran lancucha
			bxx xyc
	W funkcji zadanie 1 prosze nie odwolywac sie do zmiennych jezyka C (tj. nie uzywac "%0",
"%1", etc) Wywolanie funkcji zadanie1 nie powinno wplywac na wartosci przechowywane w rejestrach
(ich zawartosc po powrocie z funkcji musi byc identyczna jak w momencie jej wywolania). Wyprowadzenie
napisu na ekran prosze zrealizowac z wykorzystaniem odpowiedniego wolania systemowego systemu
operacyjnego Linux.
*/

int main(){
	char *x = "abc  b acabxx xyc pqr";
	char bufor[100]
	asm volatile(
		".intel_syntax noprefix;"
		"mov edx,%0;"
		"push edx;"
		"mov edx,%1;"
		"call zadanie1;"
		"jmp wyjscie;"
		"zadanie1:"
		
		[...]
		
		"wyjscie:"
		".att_syntax prefix:"
		:
		:"r"(x),"r"(bufor)
		:"edx"
	);
	return 0;
}
