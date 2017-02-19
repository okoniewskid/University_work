#include<stdio.h>
#include<libpq-fe.h>
#include<string.h>
#include<stdlib.h>
//Funkcja z programow przykladowych
void doSQL(PGconn *conn, char *command){
  PGresult *result;

  printf("%s\n", command);

  result = PQexec(conn, command);
  printf("status is     : %s\n", PQresStatus(PQresultStatus(result)));
  printf("#rows affected: %s\n", PQcmdTuples(result));
  printf("result message: %s\n", PQresultErrorMessage(result));

	switch(PQresultStatus(result)){
		case PGRES_TUPLES_OK:{
			int n = 0, m = 0;
      		int nrows   = PQntuples(result);
      		int nfields = PQnfields(result);
      		printf("number of rows returned   = %d\n", nrows);
      		printf("number of fields returned = %d\n", nfields);
			for(m = 0; m < nrows; m++){
				for(n = 0; n < nfields; n++)
	  			printf(" %s = %s", PQfname(result, n),PQgetvalue(result,m,n));
				printf("\n");
      		}
    	}
  	}
  PQclear(result);
}
//Pobieranie pola (kolumny)
char* getfield(char* kolumny, int num){
    char* token;
    for (token = strtok(kolumny, ";");token && *token;token = strtok(NULL, ";\n")){
        if (!--num)
            return token;
    }
    return NULL;
}
//Liczenie ilosci kolumn
int ilkol(char* kolumny){
	char *token;
	int l = 0;
	for (token = strtok(kolumny, ";"); token && *token; token = strtok(NULL, ";\n"))
		l++;
	return l;
}
//Tworzenie tabeli
void CREATE_TABLE(char* nazwa, char* dane, PGconn *conn){
	char *token;
	int key = 0;
	char komenda[1000] = "";
	
	strcat(komenda, "CREATE TABLE ");
	strcat(komenda, nazwa);
	strcat(komenda," (");
	
	for (token = strtok(dane, ";"); token && *token; token = strtok(NULL, ";\n")){
		if(key != 0){
    		strcat(komenda, ", ");
			strcat(komenda, token);
    		strcat(komenda, " VARCHAR(30)");
    	}
    	if(key == 0){
			strcat(komenda, token);
      		strcat(komenda, " INT PRIMARY KEY UNIQUE");
      		key++;
		}
    }
    strcat(komenda, ")");
    doSQL(conn, komenda);
}
//Dodawanie do tabeli
void INSERT(char *nazwa, char *dane, char *kolumny, int lkol, PGconn *conn){
	char* token;
	char *kolumna;
	int nr = 1;
	int key = 0;
	char komenda[1000] = "";
	strcat(komenda, "INSERT INTO ");
  	strcat(komenda, nazwa);
  	strcat(komenda, " VALUES(");
	for(token = strtok(dane, ";"); token && *token; token = strtok(NULL, ";")){
		if(nr<=lkol){
			if(key != 0){
				strcat(komenda, ", ");
				strcat(komenda, "'"); 
        		strcat(komenda, token); 
        		strcat(komenda, "'");
			}
			if(key == 0){
				strcat(komenda, "'"); 
        		strcat(komenda, token); 
        		strcat(komenda, "'"); 
      			key++;
			}
        	
        	//miejsce na dopisanie ALTER TABLE dla dluzszych ciagow
        	if(strlen(token)>30){
        		kolumna = getfield(kolumny, nr);
        		int dl = strlen(token);
        		char dlugosc[100];
        		sprintf(dlugosc, "%d", dl);
        		char komenda2[1000];
        		strcat(komenda2, "ALTER TABLE ");
  				strcat(komenda2, nazwa);
  				strcat(komenda2, " ALTER COLUMN ");
  				strcat(komenda2, kolumna);
  				strcat(komenda2, " TYPE VARCHAR(");
  				strcat(komenda2, dlugosc);
  				strcat(komenda2, ")");
  				doSQL(conn, komenda2);
			}
        	
        	nr++;
		}
  	}
	strcat(komenda, ")");
  	doSQL(conn, komenda);
}

int main(int argc, char *argv[]){
	PGconn   *conn;
	if(argc != 2){
		printf("Prawidlowe wywolanie programu: ./zadanie.c plik.csv \n");
		return 0;
	}
	//Okreslenie nazwy tabeli
	char nazwa[30];
	strcpy(nazwa, argv[1]);
	int dl = strlen(nazwa)-4;
	nazwa[dl] = '\0';
	//Dzialanie na bazie danych
	conn = PQconnectdb("host=localhost port=5432 dbname=dokoniewski user=dokoniewski password=");
	if(PQstatus(conn) == CONNECTION_OK){
    	printf("connection made\n");
    	FILE *file;
    	//Usuwanie tabeli ktora bedziemy tworzyc
    	char drop[50] = "DROP TABLE ";
		strcat(drop, nazwa);
		doSQL(conn, drop);
    	//Deklaracja zmiennych do przechowywania danych wierszy
    	char kolumny[1000];
    	char dane[1000];
		//Inicjalizacja zmiennej przechowujacej dane o kolumnach
    	file = fopen("zeszyt1.csv","r");
    	fgets(kolumny,1000,file);
    	//Deklaracja i inicjalizacja zmiennej przechowujacej ilosc kolumn tabeli
    	int lkol = 0;
    	lkol = ilkol(kolumny);
    	//Inicjalizacja zmiennej przechowujacej dane o dodawanych rekordach
    	//Pierwsze wywolanie poza petla aby pobrac nazwy kolumn do tworzenia tabeli i pozniej dzialac tylko na rekordach
    	file = fopen("zeszyt1.csv","r");
    	fgets(dane,1000,file);
    	CREATE_TABLE(nazwa, dane, conn);
    	//Wczytywanie niepustej linii z niepustego pliku do tymczasowej zmiennej aby dodac rekord
    	while(!feof(file)){
    		if(fgets(dane,1000,file) != NULL){
				INSERT(nazwa, dane, kolumny, lkol, conn);
			}
		}
		//Wyswietlenie rezultatu dzialania programu
    	doSQL(conn, "SELECT * FROM zeszyt1");
	}
	else printf("connection failed: %s\n", PQerrorMessage(conn));
	PQfinish(conn);
	return EXIT_SUCCESS;
}
