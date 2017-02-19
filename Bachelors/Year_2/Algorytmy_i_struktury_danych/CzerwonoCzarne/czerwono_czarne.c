#include <stdio.h>
#include <stdlib.h>
typedef struct Wezel{
	int wartosc;
	struct Wezel *rodzic;
	struct Wezel *lewy;
	struct Wezel *prawy;
	char kolor; //B=czarny, R=czerwony
}Wezel;

void WSTAW(struct Wezel *drzewo, int a){
	struct Wezel *wstawiany = malloc(sizeof(struct Wezel));
	struct Wezel *tmp = drzewo;
	struct Wezel *rodzic;
	struct Wezel *temp;
	struct Wezel *temp2;
	
	wstawiany->wartosc = a;
	wstawiany->lewy = NULL;
	wstawiany->prawy = NULL;
	wstawiany->rodzic = NULL;
	wstawiany->kolor = 'R';
	
	while(tmp != NULL){
		rodzic = tmp;
		if(a < tmp->wartosc){tmp = tmp->lewy;}
		else{tmp = tmp->prawy;}
	}
	wstawiany->rodzic = rodzic;	
	if(rodzic == NULL){
		wstawiany->kolor = 'B';
		drzewo = wstawiany;
	} //ustawia jako korzen gdy drzewo jest puste
	else{ //zaleznie od wartosci przypisuje element po odpowiedniej stronie rodzica
		if(wstawiany->wartosc < rodzic->wartosc){
			rodzic->lewy = wstawiany;
			while(rodzic->kolor == 'R'){
				temp = rodzic->prawy;
				temp2 = rodzic->rodzic;
				if(temp->kolor = 'R'){
					rodzic->kolor = 'B';
					temp->kolor = 'B';
					temp2->kolor = 'R';
					if(temp2->rodzic == NULL){temp2->kolor = 'B';}
					rodzic = temp2->rodzic;
				}
			}
		}
		else{
			rodzic->prawy = wstawiany;
			while(rodzic->kolor == 'R'){
				temp = rodzic->lewy;
				temp2 = rodzic->rodzic;
				if(temp->kolor = 'R'){
					rodzic->kolor = 'B';
					temp->kolor = 'B';
					temp2->kolor = 'R';
					if(temp2->rodzic == NULL){temp2->kolor = 'B';}
					rodzic = temp2->rodzic;
				}
			}
		}
	}
}

int main(){
	struct Wezel *korzen = malloc(sizeof(struct Wezel));
	korzen->rodzic = NULL;
	korzen->lewy = NULL;
	korzen->prawy = NULL;
	korzen->wartosc = 12;
	korzen->kolor = 'B';
	
	return 0;
}

