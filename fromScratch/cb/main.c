#include "cb.h"

int main(){
  VSpace vs;
  List head = -1;
  initSpace(&vs);
  insertHead(&vs, &head, 10);
  insertHead(&vs, &head, 20);
  insertRear(&vs, &head, 20);
  insertRear(&vs, &head, 100);
  insertAt(&vs, &head, 555, 1);
  insertSort(&vs, &head, 21);
  display(vs, head);
}
