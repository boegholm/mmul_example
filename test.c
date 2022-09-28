#include <stdio.h>
#include <stdlib.h>

void f(int s){
  int v[s];
  printf("%d\n", s);
}

void main(int argc, char** argv){
  f(argc);
}
