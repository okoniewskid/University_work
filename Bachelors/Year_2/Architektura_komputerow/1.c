#include <stdio.h>

int main() {
    char *x="abc  b acabxx xyc pqr";
    char bufor[99];
    asm volatile (
        ".intel_syntax noprefix;"

        "mov edx,%0;"
        "push edx;"
        "mov edx,%1;"
        "call zadanie1;"
        "jmp wyjscie;"

        "zadanie1:"

            "push eax;" //klade na stos wszystkie rejestry by moc z nich korzystac
            "push ebx;"
            "push ecx;"
            "push edx;" 
            "push ebp;" //klade na stos rejestr ebp aby moc pobierac wartosci ze stosu
            "mov ebp,esp;" //od tego miejsca bede mogl wskazywac przy kazdym pobieraniu stosu (kazda wartosc ze stosu ma 4 bajty)
            "mov eax, [ebp+24];" //klade do eax wartosc "x" czyli 7 miejsc nizej 6*4=24 (PUSH + adres pierwotny)
            "xor ebx, ebx;" //zeruje licznik znakow
            "push ebx;" //klade na stos liczb? 0

        "petla1:"

            "mov edx, [ebp+4];"
            "mov cl, [eax];"
            "cmp cl, 0;"
            "jz wyjscie0;"
            "inc eax;"
            "cmp cl, 0x61;"
            "jz petla2;"
            "cmp cl, 0x62;"
            "jnz petla1;"

            

        "petla2:"
		
		"pop ebx;"
            "xor ebx, ebx;" //zeruje licznik znakow
            "mov [edx], cl;"	//wpisuje odpowiedni znak do bufora
            "inc edx;"	//przesuwam wskaznik bufora aby wpisac natepny znak w nowe miejsce tablicy
            "inc ebx;"
            "push ebx;"

            "mov cl, [eax];"
            "cmp cl, 0x61;"
            "jz petla1;"
            "cmp cl, 0x62;"
            "jz petla1;"
            "cmp cl, 0x63;"
            "jz petla1;"




            "mov [edx], cl;"	//wpisuj? odpowiedni znak do bufora
            "inc edx;"	//przesuwam wskaznik bufora aby wpisa? natepny znak w nowe miejsce tablicy
            "pop ebx;"
	    "inc ebx;"
            "push ebx;"
            "inc eax;"
            "mov cl, [eax];"


        "petla3:"


            "mov [edx], cl;"	//wpisuj? odpowiedni znak do bufora
            "inc edx;"	//przesuwam wskaznik bufora aby wpisa? natepny znak w nowe miejsce tablicy
            "pop ebx;"	//zdejmuj? ostani? po?o?on? rzecz ze stosu i zapisuje do ebx
            "inc ebx;"
            "push ebx;"	//klade nowa wartosc na stos, robie to w ki spsob poniewaz mam juz wszystkie rejestry zajete a do ebx wpisuje lancuch y przy sprawdzaniu nastepnego znaku

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

	    "mov eax, [ebp+4];"
            "mov ecx,eax;"    //co wypisac
            "mov edx,[ebp-4];"    //dlugosc
            "mov eax,4;"    //przy wypisywaniu zawsze do eax daje 4 //kolejny znak
            "mov ebx,1;"    //przy wypisywaniu zawsze do ebx daje 1 // na kolejnym miejscu
            "int 0x80;"



  "wyjscie0:"

	
	"pop ebx;"		//zdejmuj? pokolei wszystko ze stosu (inaczje procesor zg?osi naruszenie ochrony pami?ci)
	"pop ebp;"
	"pop edx;"
	"pop ecx;"
	"pop ebx;"
	"pop eax;"
	

"ret 4;"		//tym poleceniem zdejmuj? ze stosu adres pierwotny + 8 bajtow (czyli 2 rzeczy jakie po?o?y?em na stos przed wywo?aniem funcji)




            "wyjscie:"
".att_syntax prefix;"
:
: "r" (x), "r" (bufor)
: "edx"

);
return 0;
}
