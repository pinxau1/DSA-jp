#ifndef PEMDAS
#define PEMDAS

#include<stdio.h>
#define MAX 10

typedef struct {
  int type; // 0int 1char
  union {
    int ints[MAX];
    char chars[MAX];
  }
  int top;
} Stack;

void initStack(Stack *s);
void push(Stack *s, int item);
void pop(Stack *s);
void front(Stack s);

#endif
