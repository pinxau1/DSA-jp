#ifndef HEAD
#define HEAD

#define MAX 5

typedef int Data;

typedef struct{
    Data elems[MAX];
    int front;
    int rear;
} Queue;

typedef struct{
    int id;
    char name[20];
    double price;
} Product;

typedef struct {
    Product elems[MAX];
    int front;
    int rear;
} QueueProduct;



Product newProduct(int, char*, double);
void displayProduct(Product p);

void initQueue(Queue* q);
Queue newQueue();
int isEmpty(Queue q);
int isFull(Queue q);

void enqueue(Queue *q, Data item);
void dequeue(Queue *q);
Data front(Queue q);

void display(Queue q);
void visualize(Queue q);

#endif