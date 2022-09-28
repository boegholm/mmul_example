#include "mmul.h"
#include "nanos.h"
#include <stdio.h>

int main(){
  long start = get_nanos();
  FlatArray(1000);
  long end = get_nanos();
  printf("%ld", (end-start)/1000000);
}
