#include "linkedlist.h"
#include<stdio.h>

int main(){
  Node *head = NULL;

  insertAtHead(&head, 2);
  insertAtHead(&head, 1);
  displayList(head);
}
