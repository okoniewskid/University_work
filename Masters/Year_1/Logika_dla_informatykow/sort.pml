#define MAX 5
#define DIM 5
byte a[DIM];

active proctype Generuj(){
  byte b;
  byte index;
  do
  :: index < DIM ->
        select( b : 1 .. MAX);
        a[index] = b;
        printf("a%d = %d\n", index, b);
        index++
  :: else -> break
  od

  run Pilnuj(0);
  run Pilnuj(1);
  run Pilnuj(2);
  run Pilnuj(3)
}

proctype Pilnuj(byte index){
  byte pom;
  do
  :: a[index] > a[index + 1] ->
        pom = a[index];
        a[index] = a[index + 1];
        a[index + 1] = pom
  od
}

active proctype Weryfikuj(){
  byte index;
  if
  :: timeout ->
        do
        :: index < DIM - 1 ->
              assert(a[index] <= a[index + 1]);
              index++
        :: else -> break
        od
  fi
}
