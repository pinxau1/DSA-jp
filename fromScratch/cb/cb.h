#ifndef CB
#define CB
#define MAX 10

typedef int List;

typedef struct{
  int data;
  int next;
} content;

typedef struct{
  content space[MAX];
  int avail;
} VSpace;

void initSpace(VSpace *vs);
void insertHead(VSpace *vs, List *head, int item);
void insertRear(VSpace *vs, List *head, int item);
void insertAt(VSpace *vs, List *head, int item, int idx);
int allocSpace(VSpace *vs);
void display(VSpace vs, List head);
void insertSort(VSpace *vs, List *head, int item);

#endif
