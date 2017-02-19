proctype P(byte idx){
  printf("Proces %d\n", idx)
}

init {
  run P(1); run P(2)
}

//init {
//  if
//  :: 1 > 2
//  :: 2 == 3
//  :: 2 > 1 -> printf("ok1")
//  :: 2 == 2 -> printf("ok2")
//  ::else -> printf("aqq")
//  fi
//  1 < 2;
//  printf("Hello World!\n")
//}
