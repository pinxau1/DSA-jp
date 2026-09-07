#include "ll.h"
#include <stdlib.h>
#include <stdio.h>

void insertAt(List **list, int item, int idx){
  List **trav = list;
  for(; *trav && idx > 0; --idx, trav = &(*trav)->next){}
  if(idx != 0){
    trav = list;
  }
  List *temp = malloc(sizeof(List));
  if(temp){
    temp->data = item;
    temp->next = *trav;
    *trav = temp;
  }
}

void insertFront(List **list, int item){
  List *temp = malloc(sizeof(List));

  if(temp){
    temp->data = item;
    temp->next = *list;
    *list = temp;
  }

}
void insertRear(List **list, int item){
  List **trav = list;

  for(;*trav; trav = &(*trav)->next){}

  List *temp = malloc(sizeof(List));
  if(temp){
    temp->data = item;
    temp->next = NULL;
    (*trav)= temp;
  }

}

void insertSorted(List **list, int item, int idx);

void display(List *list){
  List *trav = list;
  while(trav){
    printf("%d ", trav->data);
    trav = trav->next;
  }
}
