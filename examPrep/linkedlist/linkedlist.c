#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(int data){
  Node *ret = malloc(sizeof(Node));
  ret->data = data;
  ret->next = NULL;
  return ret;
}

void insertAtHead(Node** head, int data){
  Node *temp = createNode(data);

  temp->next = *head;
  *head = temp;
}

void displayList(const Node* head){
  while(head){
    printf("%d", head->data);
    head->next ? printf("->") : 0;
    head = (head)->next;
  }
}
