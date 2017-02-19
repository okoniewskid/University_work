
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
     
    #define MAX_DL_SLOWA 30
     
    typedef struct sl {
      char slowo[MAX_DL_SLOWA];
      struct sl* dalej;
    }*lista;
     
    //=======================================================
     
    int pusta(lista lis) {
        lista wsk;
        wsk=lis;
        if(wsk==NULL) return 1;
        else return 0;
    }
     
    //=======================================================
     
    char* pierwsze(lista lis) {
     
        lista wsk;
        wsk=lis;
        if(wsk==NULL) return 0;
        else return wsk->slowo;
     
    }
     
    //=======================================================
     
    lista reszta(lista lis) {
      // zwraca liste  lis  z usunietym pierwszym slowem
      // jesli jest pusta, to dzialanie nieokreslone
      lista wsk;
      wsk=lis;
      if(wsk==NULL) return 0;
      else return wsk=wsk->dalej;
     
     
    }
     
    //=======================================================
     
    lista dolacz(char slow[MAX_DL_SLOWA], lista lis) {//zle
     
        lista wsk;
        wsk=lis;
        lista nowa;
     
        nowa=malloc(sizeof(struct sl));
        strcpy(nowa->slowo,slow);
        nowa->dalej=lis;
        return nowa;
    }
     
    //=======================================================
     
    void druk(lista lis) {
     
        lista wsk=lis;
        while(wsk!=NULL){
            printf("%s \n", wsk->slowo);
            wsk=wsk->dalej;
        }
     
    }
     
    //=======================================================
     
   lista odwroc(lista lis) {
     
      lista pom = NULL;
      char slowo[MAX_DL_SLOWA];
      while (! pusta(lis)) {
         strcpy(slowo, pierwsze(lis));
         lis = reszta(lis);
         pom = dolacz(slowo, pom);
      }
      return pom;
    }
    //=======================================================
    
   void usun_liste(lista lis){
	   lista wsk=lis;
	   while(wsk!=NULL){
		   free(wsk);
		   wsk=wsk->dalej;
	   }
   }
    //=======================================================
    
     
    int main () {
      lista lis = NULL;
      lis = dolacz("abc", dolacz("def", dolacz("ghi", lis))); 
      druk(odwroc(lis));
      usun_liste(lis);
      druk(odwroc(lis));
      return 0;
    }



