#include<stdio.h>
#include<stdlib.h>
#include "LLheader.h"

void insertAt(List** list, int pos, int item){
  if(pos < 0 )
    return;
  
  List *temp, **trav;
  for(trav = list; *trav && pos > 1; --pos, trav = &(*trav)->link){}
  if(pos != 1){
    trav = list;
  }
  temp = malloc(sizeof(List));
  if(temp){
    temp->data = item;
    temp->link = *trav;
    *trav = temp;
  }
}

void insertFront(List** list, int item){
  List *temp = malloc(sizeof(List));
  if(temp){
    temp->data = item;
    temp->link = *list;
    *list = temp;
  }
}

void insertRear(List** list, int item){
  List **trav = list, *temp;
  for(;*trav; trav = &(*trav)->link){}
  temp = malloc(sizeof(List));
  if(temp){
    temp->data = item;
    temp->link = *trav;
    *trav = temp;
  }

}

void insertSorted(List** list, int item){
  List **trav = list, *temp;
  for(trav = list; *trav && item > (*trav)->data; trav = &(*trav)->link){}

  temp = malloc(sizeof(List));
  if(temp){
    temp->data = item;
    temp->link = *trav;
    *trav = temp;
  }
}

void display(List* list){
  while(list){
    printf("%d", list->data);
    list->link ? printf("->"):puts("");
    list = list->link;
  }
}
