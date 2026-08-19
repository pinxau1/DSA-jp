#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "boom.h"

int main(){
    List myNew;
    
    initList(&myNew, 10);
    insertRear(&myNew, 30);
    insertRear(&myNew, 10);
    insertRear(&myNew, 20);
    insertAt(&myNew, 2, 100);
    deleteFront(&myNew);
    deleteItem(&myNew, 100);
    isFoundAt(myNew, 20);
    isInList(myNew, 10);

    display(myNew);
}

void initList(List *list, int size){
    list->size = size;
    list->elems = malloc(sizeof(Data)*list->size);
    list->count = 0;
}

List newList(int size){
    List myNew;
    myNew.size = size;
    myNew.elems = malloc(sizeof(Data)*size);
    myNew.count = 0;
    return myNew;
}

bool dynamicSizer(List *list){
    if(list->count >= list->size){
        Data *temp = list->elems
        temp = realloc(list->elems, sizeof(Data)*list->size*2);

        if(!temp)
          return
        list->size*=2;
    }
}

void display(List list){
    printf("{");
    for(int i = 0; i < list.count; i++){
        printf("%d", list.elems[i]);
        i < list.count-1 ? printf(", ") : 0;
    }
    puts("}");
    return;
}

bool insertFront(List *list, int item){
    if(list->count >= list->size){
        list->elems = realloc(list->elems, sizeof(int)*list->size*2);
        list->size*=2;
    }

    for(int i = list->count; i > 0; i--){
        list->elems[i] = list->elems[i - 1];
    }
    list->count++;
    list->elems[0] = item;
    return true;
}

bool insertRear(List *list, int item){
    if(list->count >= list->size){
        list->elems = realloc(list->elems, list->size*2);
    }
    list->elems[list->count++] = item;
    return true;
}

bool insertAt(List *list, int index, int item){
    if(list->count >= list->size){
        list->elems = realloc(list->elems, list->size*2);
    }
  
    for(int i = list->count; i > index; i--){
      list->elems[i] = list->elems[i - 1];
    }

    list->elems[index] = item;
    list->count++;
    return true;
}

bool deleteFront(List *list){
  for(int i = 0; i < list->count; i++){
    list->elems[i] = list->elems[i+1];
  }
  list->count--;
  return true;
}

bool deleteRear(List *list){
  if(list->count <= 0){
    return false;
  }
  list->count--;
  return true;
}

int deleteAllItem(List *list, int item){
  list->count = 0;
  return true;
}

int deleteItem(List *list, int item){
  if(list->count <= 0){
    return false;
  }
  int idx = isFoundAt(*list, item);
  if(idx == -1)
    return false;
  for(int i = idx; i < list->count; i++){
    list->elems[i] = list->elems[i+1];
  }
  list->count--;
  return true;
}

bool isInList(List list, int key){
  int ret = isFoundAt(list, key);
  if(ret == -1){
    return false;
  } else 
    return true;
}

int isFoundAt(List list, int key){
  int idx = -1;
  for(int i = 0; i < list.count; i++)  {
    if(list.elems[i] == key){
      idx = i;
      break;
    }
  }
  return idx;
}
