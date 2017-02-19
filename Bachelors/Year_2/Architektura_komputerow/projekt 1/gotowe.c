//zad - wypisac ciag ktory zaczyna sie od a lub b, conajmniej jedna literka w srodku nie jest a, b, c i konczy sie c
#include <stdio.h>
int main() {
    char *x="abc  b acabxx xyc pqr";
    char bufor[99];
    asm volatile (
        ".intel_syntax noprefix;"

        "mov edx,%0;"
        "push edx;"     //kladzie x na stos
        "mov edx,%1;"
        "call zadanie1;"//wywoluje funkcje (wywolujac funkcje kladziesz na stos rowniez adres pierwotny)
        "jmp wyjscie;"  //przeskakuje kod gdyz zozstanie wywolany wyzej

        "zadanie1:"

            "push eax;" 	   	 //kladzie wsyzstkie rejestry na stos aby moc z nich krzystac 
            "push ebx;"
            "push ecx;"
            "push edx;"    		 //kladzie na stos bufor
            "push ebp;" 	     //kladzie na stos rejestr ebp aby moc pobierac z niego wartosci
            "mov ebp,esp;" 		 //wpisuje na stos ebp rejest esp (esp to wkaznik na stos) aby moc odwolywac sie do elementow na stosie
            "mov eax, [ebp+24];" //wpisuje do eax wartosc x (czyli nizej jest y, ecx, ebx, eax, adres pierwotny, x) kazda wartosc ma 4 bjty 6*4=24
            "xor ebx, ebx;"      //zeruje ebx (licznik znakow potrzebny do wypisania)
            "push ebx;"          //kladzie na stos wyzerowana wartosc
        
		"petla1:"	/* najpierw do EDX wysyla adres pierwotny (przechodzi na poczatek EDX), wysyla pierwsza litere do CL i zwieksza EAX(przechodzi na nastepna litere ciagu).
					dalej sprawdza czy pierwsza litera jest a albo b, jesli jest a przechodzi do petla2, jesli nie, sprawdzam czy jest b, jesli tak, to idzie dalej,
					jesli nie,to wraca na poczatek. */    

            "mov edx, [ebp+4];"     //pobiera do edx bufor
            "mov cl, [eax];"        //przenosi do cl jeden znak eax 
            "cmp cl, 0;"            //sprawdza czy nie jest to koniec ciagu znakow x            
            "jz wyjscie0;"          //jesli tak skacze do etykiety wyjscie0
            "inc eax;"              //przesuwa wskaznik w tablicy o nastepny znak, przy nastepnym skoku sprawdza kolejny
            "cmp cl, 0x61;"                        
            "jz petla2;"               
            "cmp cl, 0x62;"
            "jnz petla1;"  

        "petla2:"	/* zeruje EBX(licznik znakow), wpisuje pierwsza litere na poczatek buffora (oraz wraca na poczatek buffora w petli pierwsza, w drugiej wpisuje
			pierwszy znak do buffora na poczatek, niewazne czy zapisywal litere wczesniej), zeruje i zwieksza licznik znakow (dlatego ze wpisalo pierwsza litere), 
			dalej wpisuje do CL nastepna litere i sprawdza, czy ona nie jest a albo b, albo c, jesli jest a,b albo c, idzie do petla1 i zaczyna od poczatku, 
			jesli nie zapisuje litere do EDX i zwieksza licznik znakow, do Cl wpisuje nastepna litere */
		
	    "pop ebx;"                     //pobiera ze stosu ostania wartosc czyli licznik znakow i zapisuje do ebx
            "xor ebx, ebx;"            //zeruje te wartosc
            "mov [edx], cl;"	       //wpisuje znak z cl do bufora
            "inc edx;"	               //przesuwa o miejsce w buforze
            "inc ebx;"                 //zwieksza licznik o 1
            "push ebx;"                //kladzie go na stos 

            "mov cl, [eax];"           //przepisuje kolejny znak z c do cl
            "cmp cl, 0x61;"                  
            "jz petla1;"
            "cmp cl, 0x62;"
            "jz petla1;"
            "cmp cl, 0x63;"
            "jz petla1;"

            "mov [edx], cl;"	        //przepisuje znak do bufora
            "inc edx;"	                //przesuwa wskaznik w buforze
            "pop ebx;"                  //pobiera ostanio polozony element na stos do ebx czyli licznik znakow
	    "inc ebx;"                      //zwieksza o 1
            "push ebx;"                 //kladzie na stos 
            "inc eax;"                  //przesuwa o kolejene miejsce w ciagu znakow x
            "mov cl, [eax];"            //przepisuje kolejny znak

        "petla3:"	/*  wpisuje litere do EDX, zwieksza licznik, sprawdza czy ta litera jest a labo b, jesli tak, idzie do petla1, jesli nie, sprawdza czy jest
					to c, jesli tak, to idzie do wypisywanie i wypisuje buffora(EDX), jesli nie jest c, wpisuje do CL nastepna litere i powtarza petla3 */
					
            "mov [edx], cl;"  //przepisuje znak do bufora
            "inc edx;"	      //przesuwa wskaznik bufora aby wpisac nastepny znak                    
            "pop ebx;"		  //zdejmuje ostatnio polozona rzecz ze stosu
            "inc ebx;"
            "push ebx;"		  //kladzie nowa wartosc na stos, w ten sposob poniewaz wszystkie rejestry sa zajete

            "cmp cl, 0;"
            "jz wyjscie0;"
            "cmp cl, 0x61;"                     
            "jz petla1;"
            "cmp cl, 0x62;"
            "jz petla1;"
            "cmp cl, 0x63;"
            "jz wypisywanie;"
            "inc eax;"
            "mov cl, [eax];"                     
            "jmp petla3;"

        "wypisywanie:"

	    "mov eax, [ebp+4];"     //kladzie do eaxx wartosc bufora ze wskaznikiem na peirwsze miejsce
            "mov ecx,eax;"      //do ecx kladzie to co chce wypisac czyli bufor
            "mov edx,[ebp-4];"  // pobiera ze stosu liczbe znakow do wypisania do edx, podaje liczbe znakow
            "mov eax,4;"        //parametr funkcji                            
            "mov ebx,1;"        //standardowe wyjscie
            "int 0x80;"

  "wyjscie0:"

	"pop ebx;"	//zdejmuje wszystko ze stosu
	"pop ebp;"
	"pop edx;"
	"pop ecx;"
	"pop ebx;"
	"pop eax;"
	
"ret 4;"	//zdejmuje ze stosu adres pierwotny i 8 bajtow ktore polozyl przed wywolaniem funkcji

            "wyjscie:"
".att_syntax prefix;"
:
: "r" (x), "r" (bufor)
: "edx"

);
return 0;
}
