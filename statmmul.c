#include "mmul.h"
#include "nanos.h"
#include <stdio.h>

void main(){
  long start = get_nanos();
  SFlatArray(1000);
  long end = get_nanos();
  printf("%ld", (end-start)/1000000);
}
