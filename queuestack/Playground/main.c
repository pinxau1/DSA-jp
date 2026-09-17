#include <stdio.h>
#include "myheader.h"

int main() {
    Queue q;
    initQueue(&q);
    stackPush(&q, (ProductOrder){1, "kape", 0, 20.2, 0});
    stackPush(&q, (ProductOrder){2, "kopoy", 1, 20.2, 0});
    stackPush(&q, (ProductOrder){3, "kapez", 2, 20.2, 0});
    // displayQueue(q);
    // dequeue(&q);
    // displayQueue(q);
    upsizeDrink(&q, 1);
    // displayQueue(q);
    // Queue zilter = filterAndRemoveBySize(&q, 2);
    // displayQueue(q);
    // displayQueue(zilter);
    insertVIPOrder(&q, (ProductOrder){4, "mr beast", 0, 11.2, 1});   
    insertVIPOrder(&q, (ProductOrder){6, "eumir", 0, 11.2, 1});   
    displayQueue(q);




    return 0;
}
