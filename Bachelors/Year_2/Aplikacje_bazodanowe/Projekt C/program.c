#include <stdlib.h>
#include <stdio.h>
#include <libpq-fe.h>
#include <string.h>
#include <stdbool.h>

void PQprint2(FILE *output, const PGresult *result)
{
  switch (PQresultStatus(result)) {
  case PGRES_TUPLES_OK:
  {
    int n = 0, m = 0;
    int nrows = PQntuples(result);
    int nfields = PQnfields(result);

    fprintf(output, "%s", "<table>");
    fprintf(output, "%s", "<tr>"); //poczatek linii z nazwami kolumn
    for (n = 0; n < nfields; n++){ //wypisywanie kolumn
      fprintf(output, "%s", "<th>");
      fprintf(output, "%s", PQfname(result, n));
      fprintf(output, "%s", "</th>");
    }
    fprintf(output, "%s", "</tr>");

    for (m = 0; m < nrows; m++) {
      fprintf(output, "%s", "<tr>");
      for (n = 0; n < nfields; n++){
        fprintf(output, "%s", "<td>");
        fprintf(output, "%s", PQgetvalue(result, m, n)); //wartosci kolumn
        fprintf(output, "%s", "</td>");
      }
      fprintf(output, "%s", "</tr>");
    }
    fprintf(output, "%s", "</table>");
  }
  }
}

void doSQL(PGconn *conn, char *command)
{
  PGresult *result;

  printf("%s\n", command);

  result = PQexec(conn, command);
  printf("status is     : %s\n", PQresStatus(PQresultStatus(result)));
  printf("#rows affected: %s\n", PQcmdTuples(result));
  printf("result message: %s\n", PQresultErrorMessage(result));

  switch (PQresultStatus(result)) {
  case PGRES_TUPLES_OK:
  {
    int n = 0, m = 0;
    int nrows = PQntuples(result);
    int nfields = PQnfields(result);
    printf("number of rows returned   = %d\n", nrows);
    printf("number of fields returned = %d\n", nfields);
    for (m = 0; m < nrows; m++) {
      for (n = 0; n < nfields; n++)
        printf(" %s = %s", PQfname(result, n), PQgetvalue(result, m, n));
      printf("\n");
    }
  }
  }
  PQclear(result);
}

char* pobierz_kolumne(char* nazwy_kolumn, int num){
  char* tok;
  for (tok = strtok(nazwy_kolumn, ";"); tok && *tok; tok = strtok(NULL, ";\n")){
    if (!--num)
      return tok;
  }
  return NULL;
}

int policz_kolumny(char* nazwy_kolumn){
  char* tok;
  int licznik = 0;
  for (tok = strtok(nazwy_kolumn, ";"); tok && *tok; tok = strtok(NULL, ";\n"))
    licznik++;
  return licznik;
}

void drop_table_query(char *nazwa_tablicy, PGconn *conn)
{
  char query[100] = "DROP TABLE ";
  strcat(query, nazwa_tablicy);
  doSQL(conn, query);
}

void increase_string(char *dane_wejsciowe, char *nazwa_tablicy, char *nazwa_kolumny, PGconn *conn)
{
  int dlugosc_napisu = strlen(dane_wejsciowe);
  char dlugosc[BUFSIZ];

  sprintf(dlugosc, "%d", dlugosc_napisu); //zamiana int na char

  char query[100];
  strcat(query, "ALTER TABLE ");
  strcat(query, nazwa_tablicy);
  strcat(query, " ALTER COLUMN ");
  strcat(query, nazwa_kolumny);
  strcat(query, " TYPE VARCHAR(");
  strcat(query, dlugosc);
  strcat(query, ")");

  doSQL(conn, query);
}

void create_table_query(char* dane_wiersza, char* nazwa_tablicy, PGconn *conn) //tworzenie tabeli
{
  char* tok;
  char query[1000] = "";

  strcat(query, "CREATE TABLE ");
  strcat(query, nazwa_tablicy);
  strcat(query, " (");

  bool pierwsz_wyst = true;
  for (tok = strtok(dane_wiersza, ";"); tok && *tok; tok = strtok(NULL, ";\n"))
  {
    if (pierwsz_wyst == false)
      strcat(query, ", "); //przecinek jest dodawany po pierwszym wystapieniu, na koncu pomijany

    //kolejne wystapiania dla VARCHAR(30)
    if (pierwsz_wyst == false){
      strcat(query, tok);
      strcat(query, " VARCHAR(30)");
      pierwsz_wyst = false;
    }

    //1 wystapienie dla INT
    if (pierwsz_wyst == true){
      strcat(query, tok);
      strcat(query, " SERIAL PRIMARY KEY");
      pierwsz_wyst = false;
    }
  }
  strcat(query, ")");

  doSQL(conn, query);
}

void insert_query(char* dane_wiersza, char *nazwa_tablicy, char *nazwy_kolumn, int liczba_kolumn, PGconn *conn) //dodawanie rekordow
{
  char* tok;
  char *nazwa_kolumny;
  char query[1000] = "";
  strcat(query, "INSERT INTO "); //tworzenie tabeli
  strcat(query, nazwa_tablicy);
  strcat(query, " VALUES(");

  int pozycja_kolumny = 1;
  bool pierwsz_wyst = true;
  for (tok = strtok(dane_wiersza, ";"); tok && *tok; tok = strtok(NULL, ";"))
  {
    if(pozycja_kolumny <= liczba_kolumn){ //pomija nadmiar kolumn
      if (pierwsz_wyst == false) //dodawanie ',' po pierwszym wyrazeniu, a nie przed (np ,id zamiast id,)
        strcat(query, ", ");

        //kolejne wystapiania dla VARCHAR(30)
        strcat(query, "'"); //
        strcat(query, tok); // 'Warszawa'
        strcat(query, "'"); //

        if (strlen(tok)>30){ //jesli dodawana wartosc jest wieksza od wielkosci kolumny, zwieksz kolumne (alter table)
          nazwa_kolumny = pobierz_kolumne(nazwy_kolumn, pozycja_kolumny);
          increase_string(tok, nazwa_tablicy, nazwa_kolumny, conn);
        }

      pozycja_kolumny++;
      pierwsz_wyst = false;
    }
  }
  strcat(query, ")");
  doSQL(conn, query);
}

int main(int argc, char **argv){
  if (argc == 2){ //dla 1 argumentu np ./program nazwa.csv
    //laczenie z baza
    PGconn *conn = PQconnectdb("host=localhost port=5432 dbname=dokoniewski user=dokoniewski password=");

    char nazwa_pliku[100]; //baza.csv
    strcpy(nazwa_pliku, argv[1]);

    char nazwa_tablicy[100];
    strcpy(nazwa_tablicy, argv[1]);
    strtok(nazwa_tablicy, "."); //usuniecie "." i napisu po niej, zostaje baza

    //sprawdzanie polaczenia
    if (PQstatus(conn) == CONNECTION_OK){

      //wczytywanie z pliku
      FILE *stream;

      bool pierw_wyst = true;

      char dane_wiersza[1024]; //dane aktualnej linijki pobieranej z pliku .csv
      char nazwy_kolumn[1024]; //linia z nazwami kolumn pobrana z pliku .csv

      char *query; //do tworzenia zapytania

      int liczba_kolumn = 0; //uzywane przy sprawdzaniu, czy ilosc podanych kolumn w pliku .csv nie przekracza ilosci kolumn

      //usuniecie poprzedniej tablicy
      drop_table_query(nazwa_tablicy, conn); //zastapienie istniejacej tablicy nowa (jesli maja takie same nazwy)

      stream = fopen(nazwa_pliku, "r");
      fgets(nazwy_kolumn, 1024, stream); //zapisanie nazw kolumn, beda uzywane do pobierania nazw kolumn w funkcji pobierz_kolumne

      liczba_kolumn = policz_kolumny(nazwy_kolumn);
      printf("LICZBA KOLUMN: %i\n", liczba_kolumn);

      stream = fopen(nazwa_pliku, "r"); //czytanie pliku od nowa
      fgets(dane_wiersza, 1024, stream); //1 wystapienie dla create table (nazwy kolumn)
      create_table_query(dane_wiersza, nazwa_tablicy, conn);

      while (fgets(dane_wiersza, 1024, stream)) //kolejne wystapienia dla insert
        insert_query(dane_wiersza, nazwa_tablicy, nazwy_kolumn, liczba_kolumn, conn);

      doSQL(conn, "SELECT * FROM zeszyt1");
    }
    else{
      printf("connection failed: %s\n", PQerrorMessage(conn));
      //proba ponownego nawiazania polaczenia
      PQreset(conn);
    }

    PQfinish(conn);
  }
  else{ //dla wiecej niz 1 argumentu np ./program nazwa_bazy nazwa_tabeli > strona1.html
    //pobieranie 

    char connectInfo[33] = "host=localhost port=5432 dbname=";
    strcat(connectInfo, argv[1]); //dodanie nazwy bazy danych do zapytania (pobranie jako argument)
    strcat(connectInfo, " user=jmokrzycki password=*****");

    PGconn *conn = PQconnectdb(connectInfo);

    PGresult *result;

    printf("<!DOCTYPE HTML><HTML><HEAD><title>Tabela</title><meta http-equiv=\"Content-Type\" content=\"text/html;charset=UTF-8\">"); //PRZED PETLA, css miedzy HEAD
    printf("<style type=\"text/css\">table{font-family:verdana,arial,sans-serif;font-size:11px;color:#333333;border-width:1px;border-color:#999999;border-collapse:collapse;margin:auto;}table th{background-color:#c3dde0;border-width:1px;padding:8px;border-style:solid;border-color:#a9c6c9;}table tr{background-color:#d4e3e5;}table td{border-width:1px;padding:8px;border-style:solid;border-color:#a9c6c9;}tr:hover{background-color:#ffff99;}</style>");
    printf("</HEAD><BODY>");
    int i = 2;
    for (i = 2; i < argc; i++){ //od 2 argumentu (./program i nazwa bazy)
      //tworzenie zapytania
      char query[15] = "SELECT * FROM ";
      strcat(query, argv[i]); //nazwa aktualnej bazy
      result = PQexec(conn, query);
      if (PQresultStatus(result) == PGRES_TUPLES_OK) {
        PQprint2(stdout, result);
        printf("%s", "<br>");
      }
      else{
        printf("connection failed: %s\n", PQerrorMessage(conn));
        //proba ponownego nawiazania polaczenia
        PQreset(conn);
      }
    }
    printf("</BODY></HTML>");

    PQfinish(conn);
  }
  return EXIT_SUCCESS;
}
