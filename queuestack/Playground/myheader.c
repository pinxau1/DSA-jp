#include <stdio.h>
#include <string.h>
#include "myheader.h"

void initQueue(QPtr q) {
  q->rear = q->front = MAX - 1;    
}

Queue newQueue() {
  Queue q;

  q.front = q.rear = 0;

  return q;
}

int isEmpty(Queue q) { return q.front == q.rear; }
int isFull(Queue q) { return (q.rear + 1) % MAX == q.front; }

void enqueue(QPtr q, ProductOrder po) {
  if(!isFull(*q)) {
    q->orders[q->rear] = po;
    q->rear = (q->rear + 1) % MAX;
  }    
}

void dequeue(QPtr q) {
  if(!isEmpty(*q)) {
    q->front = (q->front + 1) % MAX;
  } 
}

ProductOrder front(Queue q) {
  ProductOrder po = newProductOrder(0, "", -1, 0);
  if(!isEmpty(q)) {
    po = q.orders[q.front];
  } 
  return po;
}

void displayQueue(Queue q) {
  printf("{");
  while(!isEmpty(q)) {
    displayProduct(front(q));
    dequeue(&q);
    if(!isEmpty(q)) {
      printf(",");
    }
    printf("\n");
  }
  printf("}\n");
}

void displayProduct(ProductOrder po) {
  char sizeName [5][20] = {"Short", "Tall", "Grande", "Venti", "Trenta"};
  if(po.size >= 0 && po.size < 5){
    printf("%5d | %15s | %-10s | Php %.2f", po.prodID, po.kopiName, sizeName[po.size], po.prodPrice);
  } else {
    printf("Unknown size\n");
  }
}

ProductOrder newProductOrder(int prodID, char *kopiName, int size, double price) {
  ProductOrder po;

  po.prodID = prodID;
  strcpy(po.kopiName, kopiName);
  po.size = size;
  po.prodPrice = price;

  return po;
}

void stackPush(QPtr q, ProductOrder po){
  int count = (q->rear - q->front + MAX) % MAX;
  enqueue(q, po);
  for(int i = 0; i < count; ++i){
    enqueue(q, front(*q));
    dequeue(q);
  }
}

void stackPop(QPtr q){
  dequeue(q);
}

void upsizeDrink(QPtr q, int prodID){
  int count = (q->rear - q->front + MAX) % MAX;
  for(int i = 0; i < count; ++i){
    ProductOrder temp = front(*q);
    temp.size++;
    temp.prodPrice += 25;
    temp.prodID == prodID ? enqueue(q, temp) : enqueue(q, front(*q));
    dequeue(q);
  }
}

Queue filterAndRemoveBySize(QPtr mainQ, int targetSize){
  //ang size 2 tangtangon
  int count = (mainQ->rear - mainQ->front + MAX) % MAX;
  Queue ret;
  initQueue(&ret);
  for(int i = 0; i < count; ++i){
    ProductOrder temp = front(*mainQ);
    temp.size == targetSize ? enqueue(&ret, temp) : enqueue(mainQ, temp);
    dequeue(mainQ);
  }
  return ret;
}

void insertVIPOrder(QPtr q, ProductOrder vipOrder){
  int count = (q->rear - q->front + MAX) % MAX;
  int inserted = 0;
  for(int i = 0; i < count; ++i){
    ProductOrder x = front(*q);
    dequeue(q);
    if(x.isVIP == 0 && inserted == 0){
      enqueue(q, vipOrder);
      inserted = 1;
    }
    enqueue(q, x);
  }
  if(inserted == 0){
    enqueue(q, vipOrder);
  }
}
