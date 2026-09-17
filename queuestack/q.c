#include <stdio.h>
#include<string.h>
#include "q.h"


void initQueue(Queue* q){
    q->elems;
    q->front = 2;
    q->rear = 2;
}

Queue newQueue(){
    Queue q = {.front = MAX-1, .rear = MAX-1};
    return q;
}

int isEmpty(Queue q){
    return q.front == q.rear;
}

int isFull(Queue q){
    return q.front == (q.rear + 1) % MAX;
}

void enqueue(Queue *q, Data item){
    if(!isFull(*q)){
        q->elems[q->rear] = item;
        q->rear = (q->rear + 1) % MAX;
    }
}

void dequeue(Queue *q){
    if(!isEmpty(*q)){
        q->front = (q->front + 1)  % MAX;
    }
}

Data front(Queue q){
    Data item = -1;
    if(!isEmpty(q)){
        item = q.elems[q.front];
    }
    return item;
}

void display(Queue q){
    printf("{");
    while(!isEmpty(q)){
        printf("%d", front(q));
        dequeue(&q);
        if(!isEmpty(q)){
            printf(", ");
        }
    }
    printf("}\n");
}
void visualize(Queue q){
    printf("%-10s | %s\n", "INDEX", "VALUE");
    for(int i = 0; i < MAX; ++i){
        printf("%-10d | %d", i, q.elems[i]);
        if(i == q.front) { 
            printf(" >> front ");
        } 
        if(i == q.rear){
            printf(" >> rear ");
        }
        putchar('\n');
    }
}

//PRODUCT VERSION

Product newProduct(int id, char* pname, double price){
    Product ret;
    ret.id = id;
    ret.price = price;
    strcpy(ret.name, pname);
    return ret;
}
void displayProduct(Product p){
    // while(!isEmpty(p)){
    //     dequeue(&p);
        printf("%-10s | %d\n", "id:", p.id);
        printf("%-10s | %s\n", "product:", p.name);
        printf("%-10s | %.2lf\n", "price:", p.price);
    //     if(!isEmpty(p)){
    //         putchar('\n');
    //     }
    // }
    
}
