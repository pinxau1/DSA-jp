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
  insertSorted(&vs, &list, 5);
  insertSorted(&vs, &list, 100);
  insertSorted(&vs, &list, 3);
  insertSorted(&vs, &list, 6);
  insertSorted(&vs, &list, 6);
  insertSorted(&vs, &list, 3);
  insertSorted(&vs, &list, 3);
  insertSorted(&vs, &list, 1);
  
  display(vs, list);
}
