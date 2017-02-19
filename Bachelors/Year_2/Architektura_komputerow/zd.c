#include <stdio.h>

int main() {
    char *x="abc  b acabxx xyc pqr";
    char bufor[99];
    asm volatile (
        ".intel_syntax noprefix;"

        "mov edx,%0;"
        "push edx;"    //kladziesz x na stos
        "mov edx,%1;"
        "call zadanie1;"//wywoluje funkcje (wywolujac fucnje kaldziesz na stos rowniez adres pierwotny
        "jmp wyjscie;"//przeskakuje kod gdyz zozstanie wywolany wyzej

        "zadanie1:"

            "push eax;" //klade wsyzstkie rejestry na stos aby muc z nich krzystac 
            "push ebx;"
            "push ecx;"
            "push edx;" //kladziesz na sttos bufor
            "push ebp;" //kladziesz na stros rejestr ebp
            "mov ebp,esp;" //wpisujesz na stos ebp rejest esp (esp to wkaznik na stos) aby muc odwolywac sie do elementow na stosie
            "mov eax, [ebp+24];"       //wpisuje do eax wartosc x odwolujac sie ze stosu (czyli nizej jest y, ecx, ebx, eax, adres pierwotny, x) kazda wartosc ma 4 bjty 6*4=24
            "xor ebx, ebx;"            //zeruje ebx (licznik znakow potrzebny do wypisania)
            "push ebx;"                //klade na stos wyzerowana wartosc
        "petla1:"                      

            "mov edx, [ebp+4];"        //pobieram do edx bufor
            "mov cl, [eax];"           //przenosze do cl jeden znak eax 
            "cmp cl, 0;"               //sprawdzam czy nie jest to koniec ciagu znakow x            
            "jz wyjscie0;"             //jesli tak skacze do wtykiety wyjscie0
            "inc eax;"                 //przesuwam wskaznik w tablicy o nastepny znak, przy nastepnym skoku sprawdzac kolejny
            "cmp cl, 0x61;"            //nie znam takich znaczkow :D            
            "jz petla2;"               //jesli cos tma to skacze do petla 2
            "cmp cl, 0x62;"
            "jnz petla1;"  

            

        "petla2:"
		
	    "pop ebx;"                     //pobieram ze stosu ostania wartosc czylli licznik znakow i zapisuje do ebx
            "xor ebx, ebx;"            //zeruje te wartosc
            "mov [edx], cl;"	       //wpisuje znak z cl do bufora
            "inc edx;"	               //przesuwam o mniejsce w bufrze
            "inc ebx;"                 //zwiekszam licznik o 1
            "push ebx;"                //klade go na stos 

            "mov cl, [eax];"                   //przepisuje kolejny znak z c do cl
            "cmp cl, 0x61;"                   //cs tam dalej XD
            "jz petla1;"
            "cmp cl, 0x62;"
            "jz petla1;"
            "cmp cl, 0x63;"
            "jz petla1;"




            "mov [edx], cl;"	              //przepisuje znak do bufora
            "inc edx;"	                      //przesuwam wskaznik w buforze
            "pop ebx;"                        //pobieeram ostanio polozony elelment na stos  do ebx czyli lciznik znakow
	    "inc ebx;"                                       //zwiekszam o 1
            "push ebx;"                          //klade na stos 
            "inc eax;"                           //przesuwam o kolejene miejsce w ciagu znakow x
            "mov cl, [eax];"                      //przepisuje kolejnyc znak


        "petla3:"


            "mov [edx], cl;"	                  //przepisuje znak do bufora
            "inc edx;"	                          //itd czytaj wyzej :D
            "pop ebx;"	
            "inc ebx;"
            "push ebx;"

            "cmp cl, 0;"
            "jz wyjscie0;"
            "cmp cl, 0x61;"                      //lol :D
            "jz petla1;"
            "cmp cl, 0x62;"
            "jz petla1;"
            "cmp cl, 0x63;"
            "jz wypisywanie;"
            "inc eax;"
            "mov cl, [eax];"                     
            "jmp petla3;"


        "wypisywanie:"

	    "mov eax, [ebp+4];"                      //klade do eaxx wartosc bufora ze wskaznikiem na peirwsze meijsce
            "mov ecx,eax;"                        //d ecx kalde to co chce wypisac czyli bufor
            "mov edx,[ebp-4];"                    //tutaj pobieram ze stosu liczbe znakow do wypisania do edx podaje lcizbe znakow
            "mov eax,4;"                                  //parametr funkcji                            
            "mov ebx,1;"                                   //standardowe wyjscie
            "int 0x80;"



  "wyjscie0:"

	
	"pop ebx;"		   //zdejmuje wszystko ze stosu
	"pop ebp;"
	"pop edx;"
	"pop ecx;"
	"pop ebx;"
	"pop eax;"
	

"ret 4;"	//dejmuje ze stosu adres peirwotny i 4 bajty ktore polozylemprzes wywolaniem fucnji (jeden push)	




            "wyjscie:"
".att_syntax prefix;"
:
: "r" (x), "r" (bufor)
: "edx"

);
return 0;
}
