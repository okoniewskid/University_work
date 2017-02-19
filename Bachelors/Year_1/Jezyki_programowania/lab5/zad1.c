    #include <stdio.h>
     
    int q,r;
    void funkcja(int n, int k, int* q , int* r)
    {
    *q=n/k;
    *r=n%k;
    }
     
     
    int main()
    {
    int n , k , q , r;
    printf("Podaj pierwszą wartość: ");
    scanf("%d" , &n);
     
    printf("Podaj drugą wartość: ");
    scanf("%d" , &k);
    funkcja( n , k , &q , &r );
    printf("Iloraz: %d\nReszta: %d\n", q , r);
     
    return 0;
    }
     
