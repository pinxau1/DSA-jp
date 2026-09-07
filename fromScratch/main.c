#include "ll.h"
#include<stdio.h>

int main(){

  List *list = NULL;

  insertRear(&list, 20000);
  insertAt(&list, 10, 0);
  insertAt(&list, 5, 1);
  insertAt(&list, 3, 1);
  insertFront(&list, 20);
  insertRear(&list, 20000);
  display(list);
}
