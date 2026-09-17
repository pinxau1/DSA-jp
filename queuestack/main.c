#include<stdio.h>
#include "q.h"

int main(){
    Queue q1 = newQueue();

    Queue q2;
    initQueue(&q2);

    display(q1);
    visualize(q1);
    display(q2);
    visualize(q2);

    displayProduct(newProduct(12, "hi", 12.2));

    return 0;
}