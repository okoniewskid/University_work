#include <stdio.h>
#include <stdlib.h>

int main (int ile_arg, char* arg[ ])
    {
     int i;
     for(i=ile_arg-1; i>0; i--){
        printf(" %s", arg[i]);
        }
    printf("\n");
    return 0;
    }
