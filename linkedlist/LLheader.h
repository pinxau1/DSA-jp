#ifndef LLheader
#define LLheader

typedef struct node{
  int data;
  struct node *link;
} List; 

void insertAt(List **list, int pos, int item);
void insertFront(List** list, int item);
void insertRear(List** list, int item);
void insertSorted(List** list, int item);
void display(List *list);

#endif
