//Zadanie AL 7.4
#include <stdio.h>
#include <stdlib.h>
//Struktura wezla z ktorych zbudowane jest drzewo
struct Wezel{
	int wartosc;
	struct Wezel *lewy;
	struct Wezel *prawy;
	struct Wezel *rodzic;
	int licznik;
};
//Funkcja sprawdzajaca czy dany element istnieje
int liczenie(struct Wezel *drzewo, int element){
	struct Wezel *tmp = drzewo;
	while(tmp != NULL && tmp->wartosc != element){
		if(element < tmp->wartosc){tmp = tmp->lewy;}
		else{tmp = tmp->prawy;}	
	}
	if(tmp == NULL){return 0;} 
	else{return 1;}
}
//Funkcja wyszukujaca dany wezel
struct Wezel* SZUKAJ(struct Wezel *drzewo, int element){
	struct Wezel *tmp = drzewo;
	while(tmp != NULL && tmp->wartosc != element){
		if(element < tmp->wartosc){tmp = tmp->lewy;}
		else{tmp = tmp->prawy;}
	}
	return tmp;
}
//Funkcja wstawiajaca wezel
void WSTAW(struct Wezel *drzewo, int element){

	struct Wezel *wstawiany = malloc(sizeof(struct Wezel));
	struct Wezel *tmp = drzewo;
	struct Wezel *rodzic;

	wstawiany->wartosc = element;
	wstawiany->lewy = NULL;
	wstawiany->prawy = NULL;
	wstawiany->rodzic = NULL;
	wstawiany->licznik = 1;

	if(liczenie(drzewo, element) == 1){ //zwieksza licznik elementu jesli istnieje
		struct Wezel *s = SZUKAJ(drzewo, element);
		s->licznik++;
	} 
	else{	//szuka gdzie wstawic element i przypisuje mu rodzica
		while(tmp != NULL){
			rodzic = tmp;
			if(element < tmp->wartosc){tmp = tmp->lewy;}
			else{tmp = tmp->prawy;}
		}
		wstawiany->rodzic = rodzic;

		if(rodzic == NULL){drzewo = wstawiany;} //ustawia jako korzen gdy drzewo jest puste
		else{  //zaleznie od wartosci przypisuje element po odpowiedniej stronie rodzica
			if(wstawiany->wartosc < rodzic->wartosc){rodzic->lewy = wstawiany;}
			else{rodzic->prawy = wstawiany;}
		}
	}
}
//Funkcja szukajaca minimum
struct Wezel* MINIMUM(struct Wezel *drzewo){
	struct Wezel* tmp = drzewo;
	while(tmp->lewy != NULL){
		tmp = tmp->lewy;
	}
	return tmp;
}
//Funkcja usuwajaca wezel
int USUN(struct Wezel *drzewo, int element){
	struct Wezel* z = SZUKAJ(drzewo, element);
	struct Wezel* y = malloc(sizeof(struct Wezel));
	struct Wezel* x = malloc(sizeof(struct Wezel));
    //z = usuwany wezel
	if(z->licznik > 1){ //jesli element nie jest jedyny zmniejsza mu licznik
		z->licznik--;
		return 1;
	}
	else{
		if(z->lewy == NULL || z->prawy == NULL){y = z;} //wykonuje jesli z ma max 1 syna i przypisuje jego wartosc y'kowi
		else{y = MINIMUM(z->prawy);} //szuka nastepnika z i przypisuje go y'grekowi
		
		if(y->lewy != NULL){x = y->lewy;} //przypisuje x'owi mniejszego syna y
		else{x = y->prawy;}               //przypisuje x'owi wiekszego syna y jesli jest jedyny/null jesli ich nie ma
		
		if(x != NULL){x->rodzic = y->rodzic;} //jesli x istnieje przypisuje mu jako rodzica, rodzica y
		if(y->rodzic == NULL){drzewo = x;}  //jesli y jest korzeniem wstawia x w jego miejsce
		else{
			if(y == y->rodzic->lewy ){y->rodzic->lewy = x;} //jesli x jest lewym synem rodzica wstawia x jako lewy syn
			else{y->rodzic->prawy = x;}						//jesli nie, wstawia go jako prawego syna 
		}
	}
	if(y != z){z->wartosc = y->wartosc;} //wstawia w miejsce z jego nastepnik, lub jedynego syna, element usuniety
	return 1;
}
//Drukuje elementy drzewa i ich ilosc (licznik)
void DRUKUJ(struct Wezel *drzewo){
	struct Wezel *tmp = drzewo;
	if(tmp != NULL){
		DRUKUJ(tmp->lewy);
		printf("wezel: %d ilosc: %d \n", tmp->wartosc, tmp->licznik);
		DRUKUJ(tmp->prawy);
	}
}

int main(void){
	struct Wezel *korzen = malloc(sizeof(struct Wezel));
	korzen->rodzic = NULL;
	korzen->lewy = NULL;
	korzen->prawy = NULL;
	korzen->licznik = 1;
	korzen->wartosc = 21;
	
	WSTAW(korzen, 7);
	WSTAW(korzen, 2);
	WSTAW(korzen, 6);
	WSTAW(korzen, 8);
	WSTAW(korzen, 9);
	WSTAW(korzen, 6);
	WSTAW(korzen, 12);
	USUN(korzen, 2);
	WSTAW(korzen, 17);
	WSTAW(korzen, 7);
	WSTAW(korzen, 21);
	USUN(korzen, 21);
	USUN(korzen, 21);
	WSTAW(korzen, 6);
	DRUKUJ(korzen);

	return 0;
}
