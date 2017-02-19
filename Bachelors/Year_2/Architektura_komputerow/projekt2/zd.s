	.intel_syntax noprefix
	.global _start

						//deklaracja "zmiennych" stalych oczywiscie
	.data
zmienna1:
	.ascii "komunikat informujacy, ze uzytkownik podal zbyt malo danych\n"
	.equ	dlugosc1, $-zmienna1
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
	.skip 300
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
	mov	bh, 48
etykieta2:
	cmp	[eax], bh
	jz	etykieta3
	inc	bh
	cmp	bh, 58
	jnz	etykieta2
etykieta3:
	cmp	bh, 58
	jnz	etykieta4
	inc 	bl
etykieta4:
	inc	eax
	cmp	[eax], byte ptr 0
	jnz 	etykieta1
	ret
etykieta5:

	jmp 	etykieta109
						//procedura sprawdzajaca czy uzytkownik wpisal poprawnie liczby
etykieta110:
	mov	bh, 48
etykieta111:
	cmp	[eax], bh
	jz	etykieta112
	inc	bh
	cmp	bh, 56
	jnz	etykieta111
etykieta112:
	cmp	bh, 56
	jnz	etykieta113
	inc 	bl
etykieta113:
	inc	eax
	cmp	[eax], byte ptr 0
	jnz 	etykieta110
	ret
etykieta109:

	jmp 	etykieta10
						//procedura odwracajaca wynik i usuwajaca zera ktore moga pojawic sie na poczatku wyniku
odwracanie:
	xor 	ecx, ecx
etykieta6:
	inc 	ebx
	inc 	ecx
	cmp 	[ebx], byte ptr 0
	jnz 	etykieta6
etykieta7:
	dec	ecx
	cmp	ecx, 0
	jz	etykieta8
	mov	[ebx], byte ptr 0
	dec 	ebx
	cmp	[ebx], byte ptr 48
	jz	etykieta7
	inc	ebx
etykieta8:
	inc 	ecx
	push 	ecx
	xor 	ecx, ecx
etykieta9:
	add 	ecx, 2
	push 	ecx
	dec 	ebx
	mov 	cl, [eax]
	mov 	ch, [ebx]
	mov 	[eax], ch
	mov 	[ebx], cl
	inc 	eax
	pop 	ecx
	cmp 	ecx, [ebp-8]
	jb 	etykieta9
	pop 	ecx
	ret
etykieta10:

	jmp	etykieta18
						//procedura dodajaca do siebie dwie liczby
etykieta11:
	push	ecx
	mov	ch, [eax]
	cmp	ch, 0
	jz	etykieta12
	sub	ch, 48	
etykieta12:
	mov	dl, [ebx]
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
etykieta14:
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
	mov 	dl, [ecx]
	sub 	dl, 48
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
	add	dl, dh
	xor	dh, dh
	pop	ecx
	cmp	dl, 8
	jb	etykieta20
etykieta104:
	sub	dl, 8
	inc	dh
	cmp	dl, 8
	jnb	etykieta104
etykieta20:	
	add 	dl, 48
	mov 	[ebx], dl
	inc	ebx
	inc	ecx
	cmp	[ecx], byte ptr 0
	jnz 	etykieta19
	cmp	dh, 0
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

	mov 	ebp, esp
						//sprawdzamy czy uzytkownik podal odpowiednia ilosc liczb jezeli podal za malo wypisze komunikat o bledzie
	mov	eax, [ebp+8]
	cmp	eax, 0
	jnz	etykieta23
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna1
	mov 	edx, offset dlugosc1
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta23:
	mov	eax, [ebp+12]
	cmp	eax, 0
	jnz	etykieta24
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna1
	mov 	edx, offset dlugosc1
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta24:
	mov	eax, [ebp+16]
	cmp	eax, 0
	jnz	etykieta25
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna1
	mov 	edx, offset dlugosc1
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta25:

						//sprawdzamy czy liczby sa podany poprawnie
	xor	bl, bl
	mov	eax, [ebp+8]
	call	etykieta110
	mov	eax, [ebp+12]
	call	etykieta110
	cmp 	bl, 0
	jz	etykieta26
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna2
	mov 	edx, offset dlugosc2
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta26:

						//sprawdzamy czy elelemt ciagu do wyliczenia jest podany poprawnie
	mov	eax, [ebp+16]
	call	etykieta1
	cmp 	bl, 0
	jz	etykieta27
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna3
	mov 	edx, offset dlugosc3
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta27:

						//konwersacja ciagu znakow w elemencie ciagu na liczbe
	xor 	ebx, ebx;
	mov	eax, [ebp+16]
	mov	ecx, [ebp+16]
						//pomijam zera ktore uzytkownik mogl wpisac na poczatku liczby, jezeli liczba jest zerem wypisze blad
etykieta28:
	cmp	[eax], byte ptr 0
	jnz	etykieta29
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna3
	mov 	edx, offset dlugosc3
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta29:
	cmp	[eax], byte ptr 48
	jnz	etykieta30
	inc	eax
	inc	ecx
	jmp 	etykieta28

						//jezeli ilosc cyfr jest wieksza niz 3 to to wypisze blad w przeciwnym razie dokona konwersacji na liczbe
etykieta30:
	inc	ecx
	cmp	[ecx], byte ptr 0
	jz	etykieta35
	inc	ecx
	cmp	[ecx], byte ptr 0
	jz	etykieta33
	inc	ecx
	cmp	[ecx], byte ptr 0
	jz	etykieta31
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna4
	mov 	edx, offset dlugosc4
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80

etykieta31:
	mov	cl, [eax]
	inc 	eax
	sub	cl, 48
etykieta32:
	add	ebx, 100
	dec 	cl
	cmp 	cl, 0
	jnz 	etykieta32
etykieta33:
	mov	cl, [eax]
	inc 	eax
	sub	cl, 48
	cmp 	cl, 0
	jz	etykieta35
etykieta34:
	add	ebx, 10
	dec 	cl
	cmp 	cl, 0
	jnz 	etykieta34
etykieta35:
	mov	cl, [eax]
	sub	cl, 48
	cmp 	cl, 0
	jz	etykieta37
etykieta36:
	inc	ebx
	dec 	cl
	cmp 	cl, 0
	jnz 	etykieta36
etykieta37:
						//jezeli liczba jest wieksza niz 255 wyppisze blad
	cmp 	ebx, 256
	jb 	etykieta38
	mov 	eax, 4
	mov	ebx, 1
	mov	ecx, offset zmienna4
	mov 	edx, offset dlugosc4
	int 	0x80
	mov 	eax, 1
	mov	ebx, 0
	int 	0x80
etykieta38:
						//liczba jest ok wiec przepisujemy ja do malego rejestru
	xor	dl, dl
etykieta39:
	dec	ebx
	inc 	dl
	cmp	ebx,0
	jnz	etykieta39
						//przepisuje do zmiennych obie liczby od tylu
	mov	eax, [ebp+12]
	mov	ebx, offset zmienna7
	xor	dh, dh
etykieta40:
	inc 	eax
	inc	dh
	cmp	[eax], byte ptr 0
	jnz	etykieta40
	xor	ch, ch
etykieta41:
	dec	eax
	dec	dh
	mov	cl, [eax]
	mov	[ebx], cl
	inc	ebx
	cmp	dh, 0
	jnz	etykieta41

	mov	eax, [ebp+8]
	mov	ebx, offset zmienna6
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
	jnz	etykieta43

						//sprawdzam czy uzytkownik podal element 1 tak wypisuje peirwszya liczba
	cmp 	dl, 1
	jnz	etykieta44
	jmp	etykieta46
etykieta44:
						//sprawdzam czy uzytkownik podal elelment 2 jezeli tak wypisuje druga liczbe
	dec	dl
	cmp 	dl, 1
	jnz	etykieta45
	jmp	etykieta47

						//dokonuje dodawania	odpowiednia ilosc razy z odpowiednim mnoznikiemi wypisuje wynik (w odwrotnej kolejnosci)
etykieta45:
	dec 	dl
	
	cmp	dl, 0
	jz	etykieta47
	push	edx
	xor	dh, dh
	mov 	ecx, offset zmienna6
	mov 	ebx, offset zmienna8
	call	etykieta19
	xor	dh, dh	
	mov 	ecx, offset zmienna7
	mov 	ebx, offset zmienna9
	call	procedura2
	mov 	eax, offset zmienna8
	mov 	ebx, offset zmienna9
	mov	ecx, offset zmienna6
	xor	dh, dh	
	call	etykieta11
	pop	edx
	dec 	dl
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
	mov	[ecx], byte ptr 10
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

