#include<stdio.h>
#include "LLheader.h"

int main(){
  List *list = NULL;
  // insertAt(&list, 9, 1);
  // insertAt(&list, 10, 2);
  // insertFront(&list, 20123);
  // insertFront(&list, 1111111);
  // insertRear(&list, 1111111);
  insertSorted(&list, 5);
  insertSorted(&list, 6);
  insertSorted(&list, 4);
  insertSorted(&list, 9);
  insertSorted(&list, 5);
  insertSorted(&list, 6);
  insertSorted(&list, 4);
  insertSorted(&list, 9);
  display(list);


}
