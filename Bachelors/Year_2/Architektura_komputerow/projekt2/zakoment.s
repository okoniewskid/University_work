	.intel_syntax noprefix
	.global _start

						//deklaracja "zmiennych" stalych
	.data
zmienna1:
	.ascii "komunikat informujacy, ze uzytkownik podal zbyt malo danych\n"
	.equ	dlugosc1, $-zmienna1  //liczy dlugosc komunikatu
zmienna2:
	.ascii "komunikat informujacy, ze uzytkownik podal nieprawidlowo liczby\n"
	.equ	dlugosc2, $-zmienna2
zmienna3:
	.ascii "komunikat informujacy, ze uzytkownik podal nieprawidlowy element ciagu\n"
	.equ	dlugosc3, $-zmienna3
zmienna4:
	.ascii "komunikat informujacy, ze uzytkownik podal liczbe ciagu  wieksza niz 255\n"
	.equ	dlugosc4, $-zmienna4
zmienna5:
	.ascii "wynik: "
	.equ	dlugosc5, $-zmienna5

						//deklaracja zmiennych nieinicjalizowanych
	.bss
zmienna6: 
	.skip 300
zmienna7: 
	.skip 300
zmienna8:
	.skip 300			//zmienne ktore mozemy zmieniac, maja miejsce na 300 elementow
zmienna9:
	.skip 300
zmienna10:
	.skip 300
zmienna11:
	.skip 300

	.text
_start:


	jmp 	etykieta5
						//procedura sprawdzajaca czy uzytkownik wpisal poprawnie element ciagu
etykieta1:
	mov	bh, 48			//wrzucamy 0 w kodzie ascii do bh
etykieta2:
	cmp	[eax], bh 			//sprawdzamy czy pierwszy znak jest = 0
	jz	etykieta3 			//
	inc	bh 					//ziwekszamy az dojdzie do 9
	cmp	bh, 58          	//
	jnz	etykieta2 			////to samo co przy sprawdzaniu liczb	
etykieta3: 					////jedyna roznica polega na tym ze 
	cmp	bh, 58 				////teraz sprawdzanie odbywa sie w 
	jnz	etykieta4       	////systemie dziesietnym
	inc 	bl 				//jesli bl = 0 to znaczy ze uzytkownik wpisal dobre dane
etykieta4: 					//
	inc	eax 				//
	cmp	[eax], byte ptr 0 	//oznacza ze 0 jest w 1 bajcie (?)
	jnz 	etykieta1 		//
	ret 					//
etykieta5:

	jmp 	etykieta109
						//procedura sprawdzajaca czy uzytkownik wpisal poprawnie liczby
etykieta110:
	mov	bh, 48			//wrzucamy 0 w kodzie ascii do bh
etykieta111:
	cmp	[eax], bh			//sprawdzamy czy pierwszy znak jest = 0
	jz	etykieta112			//jesli tak to skaczemy do etykiety112
	inc	bh					//zwiekszamy bh o 1, czyli bh = 1
	cmp	bh, 56 				//czy bh = 8?
	jnz	etykieta111 		//jesli nie to skaczemy do 111, jesli tak to jedziemy dalej
etykieta112:
	cmp	bh, 56 				//czy dojechalismy do konca
	jnz	etykieta113 		//jesli nie to zwiekszamy bl o 1
	inc 	bl 				//jesli bl = 0 to znaczy ze uzytkownik wpisal dobre dane
etykieta113:
	inc	eax 				//przerzucamy wskaznik na drugi znak
	cmp	[eax], byte ptr 0   //sprawdzamy czy jest zerem
	jnz 	etykieta110		//jesli nie, to skaczemy do 110 i sprawdzamy
	ret                     //jesli tak to zdejmujemy funkcje ze stosu
etykieta109:

	jmp 	etykieta10
						//procedura odwracajaca wynik i usuwajaca zera ktore moga pojawic sie na poczatku wyniku
odwracanie:
	xor 	ecx, ecx
etykieta6:
	inc 	ebx				//przesuwamy ebx na koniec
	inc 	ecx         	//w ecx bedzie dlugosc liczby
	cmp 	[ebx], byte ptr 0
	jnz 	etykieta6
etykieta7: //wywala zera jesli liczba poczatkowo to np 12500
	dec	ecx					//odejmuje poniewaz dlugosc bedzie za duza po usunieciu zer
	cmp	ecx, 0 				//zabezpieczenie przed usunieciem jednego zera (?)
	jz	etykieta8 			
	mov	[ebx], byte ptr 0
	dec 	ebx
	cmp	[ebx], byte ptr 48
	jz	etykieta7
	inc	ebx					//wracam na koniec napisu bez zer na koncu
etykieta8:
	inc 	ecx
	push 	ecx
	xor 	ecx, ecx
etykieta9:
	add 	ecx, 2 			//aby dojsc do polowy w zamianie kolejnosci
	push 	ecx
	dec 	ebx
	mov 	cl, [eax]
	mov 	ch, [ebx]
	mov 	[eax], ch		//zamiana miejscami pierwszej cyfry z ostatnia
	mov 	[ebx], cl
	inc 	eax
	pop 	ecx
	cmp 	ecx, [ebp-8]	//porownuje z dlugoscia (ebp-8) polozona wczesniej na stosie
	jb 	etykieta9
	pop 	ecx
	ret
etykieta10:

	jmp	etykieta18
						//procedura dodajaca do siebie dwie liczby
etykieta11: //zabezpieczenie przed tym, ze druga liczba jest dluzsza
	push	ecx				// ecx - zmienna6
	mov	ch, [eax] 			//pierwszy element
	cmp	ch, 0
	jz	etykieta12
	sub	ch, 48	
etykieta12:
	mov	dl, [ebx] 			//drugi element
	sub	dl, 48
	add 	dl, dh
	xor	dh, dh
	add	dl, ch
	cmp	dl, 8
	jb	etykieta13
etykieta107:
	inc 	dh
	sub 	dl, 8
	cmp	dl, 8
	jnb	etykieta107
etykieta13:
	add	dl, 48	
	pop    ecx
	mov 	[ecx], dl
	inc	ecx
	inc	eax
	inc	ebx
	cmp	[ebx], byte ptr 0
	jnz	etykieta11
etykieta14:  				//zabezpieczenie, ze pierwsza liczba jest dluzsza
	cmp	[eax], byte ptr 0
	jz	etykieta16
	mov	dl, [eax]
	sub	dl, 48
	add	dl, dh
	xor	dh, dh
	cmp	dl, 8
	jb	etykieta15
etykieta108:
	inc 	dh
	sub 	dl, 8
	cmp	dl, 8
	jnb	etykieta108
etykieta15:
	add	dl, 48
	mov	[ecx], dl
	inc	eax
	inc	ecx
	jmp	etykieta14
etykieta16:
	cmp	dh, 0
	jz	etykieta17
	add	dh, 48
	mov	[ecx], dh
etykieta17:
	ret
etykieta18:

	jmp	etykieta22
etykieta19:
						//procedura mnozaca dwie liczby
	mov 	dl, [ecx]		//w ecx liczba do mnozenia
	sub 	dl, 48 			//konwersja na int
	push	ecx
	mov	cl, dl
	add	dl, cl	
	add	dl, cl	
	add	dl, cl	
	add	dl, cl	
	add	dl, cl	
	add	dl, cl	
	add	dl, cl	
	add	dl, cl	
	add	dl, cl	
	add	dl, dh 				//dh - przeniesienie w dodawaniu pisemnym
	xor	dh, dh
	pop	ecx
	cmp	dl, 8 				//jezeli mniejsze od 8
	jb	etykieta20 			//jezeli tak to przeskakujemy
etykieta104: 				//jezeli nie to wyliczamy przeniesienie
	sub	dl, 8
	inc	dh
	cmp	dl, 8
	jnb	etykieta104
etykieta20:	
	add 	dl, 48  		//zamiana na char
	mov 	[ebx], dl 		//pierwszy slupek dodawnia pisemnego wrzucamy na 1 miejsce w ebx
	inc	ebx
	inc	ecx
	cmp	[ecx], byte ptr 0 	//sprawdzenie czy nie jest koniec liczby
	jnz 	etykieta19
	cmp	dh, 0 				 //czy istnieje przeniesienie
	jz	etykieta21
	add	dh, 48
	mov	[ebx], dh
etykieta21:
	ret
etykieta22:

	jmp	etykieta105
procedura2:
						//procedura mnozaca dwie liczby
	mov 	dl, [ecx]
	sub 	dl, 48
	push	ecx
	mov	cl, dl
	add	dl, cl	
	add	dl, cl	
	add	dl, cl	
	add	dl, cl	
	add	dl, cl		
	add	dl, dh
	xor	dh, dh
	pop	ecx
etykieta101:
	cmp	dl, 8
	jb	etykieta102
	sub	dl, 8
	inc	dh
	cmp	dl, 8
	jnb	etykieta101
etykieta102:	
	add 	dl, 48
	mov 	[ebx], dl
	inc	ebx
	inc	ecx
	cmp	[ecx], byte ptr 0
	jnz 	procedura2
	cmp	dh, 0
	jz	etykieta103
	add	dh, 48
	mov	[ebx], dh
etykieta103:
	ret
etykieta105:

	mov 	ebp, esp	// ilosc liczb w ebp
			//sprawdzamy czy uzytkownik podal odpowiednia ilosc liczb jezeli podal za malo wypisze komunikat o bledzie
	mov	eax, [ebp+8]	//pierwszy paramert dlatego +8
	cmp	eax, 0 			 //sprawdzamy czy podany 1 parametr jest nullem
	jnz	etykieta23
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna1 		 //za malo parametrow, wypisanie komunikatow z zmienna1. dlugosc1
	mov edx, offset dlugosc1 	 //za malo parametrow, wypisanie komunikatow z zmienna1. dlugosc1
	int 	0x80
	mov 	eax, 1 			//konczenie programu
	mov	ebx, 0
	int 	0x80
etykieta23:
	mov	eax, [ebp+12]  		//drugi parametr
	cmp	eax, 0
	jnz	etykieta24
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna1
	mov edx, offset dlugosc1
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta24:
	mov	eax, [ebp+16] 		//3 parametr
	cmp	eax, 0
	jnz	etykieta25
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna1
	mov edx, offset dlugosc1
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta25:

						//sprawdzamy czy liczby sa podany poprawnie 0-7 w osemkowym
	xor	bl, bl
	mov	eax, [ebp+8] 		//pierwszy argument
	call	etykieta110 	//zwieksza 0
	mov	eax, [ebp+12]		//drugi argument
	call	etykieta110
	cmp 	bl, 0 			//sprawdzamy czy zero
	jz	etykieta26 			//jezeli bl rozne od 0 to 
	mov 	eax, 4 			//wypisywanie komunikatu 
	mov	ebx, 1
	mov	ecx, offset zmienna2 		//wypisujemy blad w razie zlych danych
	mov edx, offset dlugosc2
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta26:

						//sprawdzamy czy elelemt ciagu do wyliczenia jest podany poprawnie
	mov	eax, [ebp+16]
	call	etykieta1
	cmp 	bl, 0
	jz	etykieta27 		//jezeli nie ma bledu to idziemy do etykieta27
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna3
	mov 	edx, offset dlugosc3
	int 	0x80  					//zakonczenie programu
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta27:

						//konwersacja ciagu znakow w elemencie ciagu na liczbe
	xor 	ebx, ebx;
	mov	eax, [ebp+16]   //zapisujemy do 2 rejestrow 3argument
	mov	ecx, [ebp+16]
				//pomijam zera ktore uzytkownik mogl wpisac na poczatku liczby, jezeli liczba jest zerem wypisze blad
etykieta28:				
	cmp	[eax], byte ptr 0  			//sprawdzanie czy 1 wartosc = 0, az dojdzie sie do nulla
	jnz	etykieta29
	mov 	eax, 4 					//jezeli null to wypisze blad i zakonczy program
	mov	ebx, 1
	mov	ecx, offset zmienna3
	mov 	edx, offset dlugosc3
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta29:
	cmp	[eax], byte ptr 48 	 		//spradzamy czy 0 w ascii
	jnz	etykieta30 					//jezeli nie to
	inc	eax 						//przesuwamy sie dalej w tablicy, sprawdzamy dalej
	inc	ecx
	jmp 	etykieta28 				//jezeli 0 to skacze wyzej do etykeita28

					//jezeli ilosc cyfr jest wieksza niz 3 to to wypisze blad w przeciwnym razie dokona konwersacji na liczbe
etykieta30:
	inc	ecx
	cmp	[ecx], byte ptr 0 		//spradzenie ilu cyfrowa liczba, 3 argument
	jz	etykieta35 				//jezeli null to skaczemy do etykiety 35
	inc	ecx
	cmp	[ecx], byte ptr 0 		//sprawdzanie czy 3cyfrowa
	jz	etykieta33
	inc	ecx
	cmp	[ecx], byte ptr 0 		//sprawdzanie czy 4cyfrowa
	jz	etykieta31 				//wyswietlanie komunikatu ze za duzo cyfr
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna4 		//wypisuje komunikat, ze liczba jest za duza
	mov 	edx, offset dlugosc4
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
 
etykieta31: 		  //konwersje
	mov	cl, [eax] 		// na poczatku eax jest na pierwszym miejscu
	inc 	eax 		//nastepne miejsce
	sub	cl, 48			//zmiana z char na int
etykieta32:				//czesc setna
	add	ebx, 100 		//pierwsza liczba na setki
	dec 	cl 			//dejmowanie 1 liczby (?)
	cmp 	cl, 0 		//jezeli 0 to skacze do 32
	jnz 	etykieta32
etykieta33:				//czesc dziesietna
	mov	cl, [eax]
	inc 	eax
	sub	cl, 48
	cmp 	cl, 0 		//zabezpieczenie jakby bylo np 102 to przeskoczy do jednosci
	jz	etykieta35
etykieta34:
	add	ebx, 10
	dec 	cl
	cmp 	cl, 0
	jnz 	etykieta34
etykieta35: 			//jednosci
	mov	cl, [eax]
	sub	cl, 48
	cmp 	cl, 0 		//zabezpieczenie jakby bylo np 120 to przeskoczy
	jz	etykieta37
etykieta36:
	inc	ebx
	dec 	cl
	cmp 	cl, 0
	jnz 	etykieta36
etykieta37:				//tu juz jest postac liczbowa
				//jezeli liczba jest wieksza niz 255 wyppisze blad
	cmp 	ebx, 256 	//sprawdzanie
	jb 	etykieta38 		//jump below(?)//jezeli mniejsze to przeskok, jezeli wieksze to komunikat o bledzie
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna4 		//kominikat, ze za duza liczba
	mov 	edx, offset dlugosc4
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta38:
						//liczba jest ok wiec przepisujemy ja do malego rejestru
	xor	dl, dl
etykieta39: 	//przerzucanie z duzego ebx do malego dl
	dec	ebx
	inc 	dl 			//to co bylo w ebx trafia do dl
	cmp	ebx,0
	jnz	etykieta39
				//przepisuje do zmiennych obie liczby od tylu
	mov	eax, [ebp+12]   		//do eax drugi parametr (2 liczba)
	mov	ebx, offset zmienna7 	//operowanie w ebx w zmiennej7, co zapisanie w ebx bedzie w zmiennej7
	xor	dh, dh
etykieta40: 	//przesuniecie wskaznika z liczby na koniec (0 null)
	inc 	eax
	inc	dh 				//w bh dlugosc liczby
	cmp	[eax], byte ptr 0
	jnz	etykieta40
	xor	ch, ch
etykieta41: 	//zapisywanie odwroconej liczby do ebx//przesuwanie o 1 miejsce w tyl, liczba 123 jako 321
	dec	eax				//przesuwanie w tyl
	dec	dh
	mov	cl, [eax]
	mov	[ebx], cl 		// przypisanie zmiennej 
	inc	ebx
	cmp	dh, 0
	jnz	etykieta41

	mov	eax, [ebp+8] 			//pobiera 1 parametr
	mov	ebx, offset zmienna6 	//przypisuje do zmiennej6
etykieta42:
	inc 	eax
	inc	dh
	cmp	[eax], byte ptr 0
	jnz	etykieta42
etykieta43:
	dec	eax
	dec	dh
	mov	cl, [eax]
	mov	[ebx], cl
	inc	ebx
	cmp	dh, 0
	jnz	etykieta43		//liczby odwrócone zapisane w zmienna7 i zmienna6 jak skonczymy skakanie

						//sprawdzam czy uzytkownik podal element 1 tak wypisuje peirwszya liczba
	cmp 	dl, 1
	jnz	etykieta44
	jmp	etykieta46
etykieta44:
						//sprawdzam czy uzytkownik podal elelment 2 jezeli tak wypisuje druga liczbe
	dec	dl 			//odejmujemy 1 zeby latwiej w petli skakac
	cmp 	dl, 1
	jnz	etykieta45
	jmp	etykieta47

						//dokonuje dodawania	odpowiednia ilosc razy z odpowiednim mnoznikiemi wypisuje wynik (w odwrotnej kolejnosci)
etykieta45:
	dec 	dl
	
	cmp	dl, 0 			//w dl jest 3 arg
	jz	etykieta47
	push	edx 		//puszujemy zeby nie stracic dl
	xor	dh, dh
	mov 	ecx, offset zmienna6 	//pierwsza liczba w zmiennej6 zapisana odwrotnie
	mov 	ebx, offset zmienna8 	//wartosc pomnozona razy a=10
	call	etykieta19
	xor	dh, dh	
	mov 	ecx, offset zmienna7 	//druda liczba zapisana odwrotnie
	mov 	ebx, offset zmienna9 	//wartosc pomnozona razy b=6
	call	procedura2
	mov 	eax, offset zmienna8
	mov 	ebx, offset zmienna9
	mov	ecx, offset zmienna6
	xor	dh, dh	
	call	etykieta11
	pop	edx 			//sciaga ze stosu
	dec 	dl 			//porownanie z 0
	cmp	dl, 0
	jz	etykieta46
	push	edx
	xor	dh, dh
	mov 	ecx, offset zmienna7
	mov 	ebx, offset zmienna10
	call	etykieta19
	xor	dh, dh	
	mov 	ecx, offset zmienna6
	mov 	ebx, offset zmienna11
	call	procedura2
	mov 	eax, offset zmienna10
	mov 	ebx, offset zmienna11
	mov	ecx, offset zmienna7
	xor	dh, dh	
	call	etykieta11
	pop	edx
	jmp 	etykieta45
						//odwraca wynik i wypisuje odpowiednia liczbe
etykieta46:
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna5
	mov 	edx, offset dlugosc5
	int 	0x80
	mov 	eax, offset zmienna6
	mov 	ebx, offset zmienna6
	call 	odwracanie
	mov 	eax, 4
	mov	ebx, 1
	mov 	edx, ecx
	mov	ecx, offset zmienna6
	int 	0x80
	mov 	eax, 4
	mov	ebx, 1
	mov	[ecx], byte ptr 10 	//wypisanie entera
	mov 	edx, 1
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80

etykieta47:
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna5
	mov 	edx, offset dlugosc5
	int 	0x80
	mov 	eax, offset zmienna7
	mov 	ebx, offset zmienna7
	call 	odwracanie
	mov 	eax, 4
	mov	ebx, 1
	mov 	edx, ecx
	mov	ecx, offset zmienna7
	int 	0x80
	mov 	eax, 4
	mov	ebx, 1
	mov	[ecx], byte ptr 10
	mov 	edx, 1
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80

