#include <stdio.h>
#include "CBheader.h"

int main(){

  VSpace vs;
  List list = -1;
  initVSpace(&vs);
  // insertHead(&vs, &list, 10);
  // insertHead(&vs, &list, 20);
  // insertHead(&vs, &list, 30);
  // insertRear(&vs, &list, 100);
  // insertRear(&vs, &list, 67);
  // insertRear(&vs, &list, 89);
  // insertSorted(&vs, &list, 5);
  // insertSorted(&vs, &list, 100);
  insertAt(&vs, &list, 1500, 5);
  display(vs, list);
  insertAt(&vs, &list, 1200, 0);
  display(vs, list);
  insertAt(&vs, &list, 1300, 1);
  display(vs, list);
  insertAt(&vs, &list, 1400, 0);
  display(vs, list);
  freeSpace(&vs, &list, 0);
  freeSpace(&vs, &list, 10);
  puts("final");
  display(vs, list);
}
