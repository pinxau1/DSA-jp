#ifndef LL
#define LL

typedef struct node{
  int data;
  struct node *next;
} List;

void insertAt(List **list, int item, int idx);
void insertFront(List **list, int item);
void insertRear(List **list, int item);
void insertSorted(List **list, int item, int idx);
void display(List *list);

#endif
