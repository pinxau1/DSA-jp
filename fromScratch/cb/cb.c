#include "cb.h"
#include <stdio.h>

void initSpace(VSpace *vs){
  vs->avail = MAX-1;
  int i;
  for(i = vs->avail; i >= 0; --i){
    vs->space[i].next = i-1;
  }
}

void insertHead(VSpace *vs, List *head, int item){
  int temp = allocSpace(vs);
  vs->space[temp].data = item;
  vs->space[temp].next = *head;
  *head = temp;
}
void insertRear(VSpace *vs, List *head, int item){

  int trav = *head;
  for(; vs->space[trav].next != -1; trav = vs->space[trav].next){}

  int temp = allocSpace(vs);
  if(temp != -1){
    vs->space[temp].data = item;
    vs->space[temp].next = -1;
    vs->space[trav].next = temp;
  }

}
void insertAt(VSpace *vs, List *head, int item, int idx){
  int trav = *head;
  for(;trav != -1 && idx > 1; --idx, trav = vs->space[trav].next){}
  int temp = allocSpace(vs);
  if(temp != -1){
    vs->space[temp].data = item;
    if(idx == 1){
      vs->space[temp].next = vs->space[trav].next;
      vs->space[trav].next = temp;
    } else {
      vs->space[temp].next = *head;
      *head = temp;
    }
  }
}

int allocSpace(VSpace *vs){
  int ret = vs->avail;
  if(ret != -1){
    vs->avail = vs->space[vs->avail].next;
  }
  return ret;
}

void display(VSpace vs, List head){
  while(head != -1){
    printf("%d", vs.space[head].data);
    vs.space[head].next != -1 ? printf("->") : puts("");
    head = vs.space[head].next;
  }
}

void insertSort(VSpace *vs, List *head, int item){
  int trav = *head;
  for(;trav != -1 && item < vs->space[trav].data; trav = vs->space[trav].next){}
  int temp = allocSpace(vs);
  if(temp != -1){
    vs->space[temp].data = item;
    vs->space[temp].next = vs->space[trav].next;
    vs->space[trav].next = temp;
  }
}





