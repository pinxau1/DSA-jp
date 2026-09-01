#include "CBheader.h"
#include <stdio.h>

void initVSpace(VSpace *vs){
  vs->avail = MAX-1;
  int i;
  for(i = vs->avail; i >= 0; --i){
    vs->space[i].next = i-1;
  }
}

void insertHead(VSpace *vs, List *list, int item){
  List temp = allocSpace(vs);

  if(temp != -1){
    vs->space[temp].data = item;
    vs->space[temp].next = *list;
    *list = temp;
  }
}

void insertRear(VSpace *vs, List *list, int item){

  List trav = *list;
  while(vs->space[trav].next != -1){
    trav = vs->space[trav].next; 
  }

  List temp = allocSpace(vs);
  if(temp != -1){
    vs->space[trav].next = temp;
    vs->space[temp].data = item; 
    vs->space[temp].next = -1; 
  }

}

int allocSpace(VSpace *vs){
  int ret = vs->avail;

  if(ret != -1){
    vs->avail = vs->space[vs->avail].next;
  }

  return ret;
}

void insertSorted(VSpace *vs, List *list, int item){
  List trav = *list;
  List prev = -1;

  while(trav != -1 && item > vs->space[trav].data){
    prev = trav;
    trav = vs->space[trav].next;
  }

  List temp = allocSpace(vs);
  if(temp != -1){
    vs->space[temp].data = item;
    vs->space[temp].next = trav;
    if(prev == *list){
      *list = temp;
    } else
      vs->space[prev].next = temp;
  }
}

void insertAt(VSpace *vs, List *list, int item, int pos){
  List trav = *list;

  for(; trav != -1 && pos > 1; pos--){
    trav = vs->space[trav].next;
  }

  List temp = allocSpace(vs);
  if(temp != -1){
    vs->space[temp].data = item;
    if(pos == 1){
      vs->space[temp].next = vs->space[trav].next;
      vs->space[trav].next = temp;
    } else {
      vs->space[temp].next = *list;
      *list = temp;
    }

  }
}

void display(VSpace vs, List list){
  while(list != -1){
    printf("%d", vs.space[list].data);
    vs.space[list].next != -1 ? printf("->") : putchar('\n');
    list = vs.space[list].next;
  }
}

void freeSpace(VSpace *vs, List *list, int pos){
  if(*list == -1){
    return;
  }
  List trav = *list;
  for(;trav != -1 && vs->space[trav].next != -1 && pos > 1; --pos, trav = vs->space[trav].next){}

  if(pos == 1 && trav != -1 && vs->space[trav].next != -1){
    int freed = vs->space[trav].next;
    vs->space[trav].next = vs->space[freed].next;
    vs->space[freed].next = vs->avail;
    vs->avail = freed;
  } else {
    int freed = *list;
    *list = vs->space[*list].next;
    vs->space[freed].next = vs->avail;
    vs->avail = freed;
  }
}
