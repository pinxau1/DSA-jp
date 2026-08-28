#ifndef CBHEADER
#define CBHEADER
#define MAX 10

typedef struct {
  int data;
  int next;
} content;

typedef struct {
  content space[MAX];
  int avail;
} VSpace;

typedef int List;

void initVSpace(VSpace *vs);
void insertHead(VSpace *vs, List *list, int item);
void insertRear(VSpace *vs, List *list, int item);
void insertSorted(VSpace *vs, List *list, int item);
int allocSpace(VSpace *vs);
void display(VSpace vs, List list);

#endif // !CBHEADER
